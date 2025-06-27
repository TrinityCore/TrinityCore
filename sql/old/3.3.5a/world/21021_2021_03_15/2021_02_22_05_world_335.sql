-- 6124 Curar la dolencia
-- https://es.classic.wowhead.com/quest=6124
SET @ID := 6124;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Ciervo enfermo curado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado lo que te pidió Alanndarian Arrullanoche de Auberdine? Tu trabajo no está completo sin eso.', 0),
(@ID, 'esMX', '¿Has completado lo que te pidió Alanndarian Arrullanoche de Auberdine? Tu trabajo no está completo sin eso.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ha sido una buena acción la de atender a los ciervos enfermos de Costa Oscura; son víctimas inocentes de una corrupción que se está extendiendo por toda esta tierra. En Darnassus hay quienes han elegido reconocer la existencia de esta amenaza, pero también hay quienes han elegido ignorar las señales. Espero que tú no ignores lo que tenemos ante nuestros propios ojos, $n.$B$BEn cualquier caso, has demostrado tu valía como amigo de la naturaleza y del Círculo, acepta esto como reconocimiento.', 0),
(@ID, 'esMX', 'Ha sido una buena acción la de atender a los ciervos enfermos de Costa Oscura; son víctimas inocentes de una corrupción que se está extendiendo por toda esta tierra. En Darnassus hay quienes han elegido reconocer la existencia de esta amenaza, pero también hay quienes han elegido ignorar las señales. Espero que tú no ignores lo que tenemos ante nuestros propios ojos, $n.$B$BEn cualquier caso, has demostrado tu valía como amigo de la naturaleza y del Círculo, acepta esto como reconocimiento.', 0);
-- 6125 Poder contra el veneno
-- https://es.classic.wowhead.com/quest=6125
SET @ID := 6125;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos. He observado tu progreso y debo admitir que la situación de Auberdine me ha sorprendido. Esos venenos alteran el equilibrio.$B$BMe ha gustado tu forma de actuar; te concedo poder permanente sobre el veneno. Úsalo con prudencia, $n.', 0),
(@ID, 'esMX', 'Saludos. He observado tu progreso y debo admitir que la situación de Auberdine me ha sorprendido. Esos venenos alteran el equilibrio.$B$BMe ha gustado tu forma de actuar; te concedo poder permanente sobre el veneno. Úsalo con prudencia, $n.', 0);
-- 6127 La fuente del envenenamiento
-- https://es.classic.wowhead.com/quest=6127
SET @ID := 6127;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te envía el Círculo Cenarion, ¿verdad? Suerte que has llegado; no podemos curar a las gacelas envenenadas. Agradecemos mucho tu ayuda.$B$B¿Traes la muestra de agua? Así podremos buscar una cura...', 0),
(@ID, 'esMX', 'Te envía el Círculo Cenarion, ¿verdad? Suerte que has llegado; no podemos curar a las gacelas envenenadas. Agradecemos mucho tu ayuda.$B$B¿Traes la muestra de agua? Así podremos buscar una cura...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Puaj, qué asco! Pobres gacelas.$B$BAlgo está contaminando toda el agua de los Baldíos del Norte, pero en esto actúa alguna otra fuerza.$B$BCon esta muestra podremos desarrollar una cura; voy a necesitar ciertos materiales...', 0),
(@ID, 'esMX', '¡Puaj, qué asco! Pobres gacelas.$B$BAlgo está contaminando toda el agua de los Baldíos del Norte, pero en esto actúa alguna otra fuerza.$B$BCon esta muestra podremos desarrollar una cura; voy a necesitar ciertos materiales...', 0);
-- 6128 Reunir los ingredientes del remedio
-- https://es.classic.wowhead.com/quest=6128
SET @ID := 6128;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los componentes que necesito para hacer el bálsamo? Las gacelas no se van a curar solas, ¡así que más vale que no cejemos en nuestro empeño por salvarlas!', 0),
(@ID, 'esMX', '¿Tienes los componentes que necesito para hacer el bálsamo? Las gacelas no se van a curar solas, ¡así que más vale que no cejemos en nuestro empeño por salvarlas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto está bien, $n, tanto que debería ser suficiente para hacer varias dosis considerables del bálsamo, o al menos lo suficiente para empezar a notar la diferencia.$B$BHacer curas para venenos a veces puede ser muy complejo porque cada uno requiere con frecuencia de un antídoto específico para contrarrestarlo. ¡Imagínate que se pudiera curar un veneno a placer sin tener que preocuparse por los ingredientes exactos para obtener el antídoto perfecto!$B$B¡Venga, ahora mismo me pongo con ello!', 0),
(@ID, 'esMX', 'Esto está bien, $n, tanto que debería ser suficiente para hacer varias dosis considerables del bálsamo, o al menos lo suficiente para empezar a notar la diferencia.$B$BHacer curas para venenos a veces puede ser muy complejo porque cada uno requiere con frecuencia de un antídoto específico para contrarrestarlo. ¡Imagínate que se pudiera curar un veneno a placer sin tener que preocuparse por los ingredientes exactos para obtener el antídoto perfecto!$B$B¡Venga, ahora mismo me pongo con ello!', 0);
-- 6129 Curar la dolencia
-- https://es.classic.wowhead.com/quest=6129
SET @ID := 6129;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Gacela enferma curada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado lo que te pidió Tonga Tótem de Runa en El Cruce? Tu trabajo no está completo sin eso.', 0),
(@ID, 'esMX', '¿Has completado lo que te pidió Tonga Tótem de Runa en El Cruce? Tu trabajo no está completo sin eso.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho bien en atender a las gacelas enfermas de Los Baldíos, son las víctimas inocentes de una corrupción y contaminación mayores que se está extendiendo por toda la zona. Como $r, estás muy impaciente por entender los movimientos de Cenario; tú, al igual que tus ancestros de Cima del Trueno, eres la prueba de que la necesidad de equilibrio trasciende las barreras raciales artificiales.$B$B$n, has demostrado tu valía como amigo de la naturaleza y del Círculo, toma esto como símbolo de esta cualidad.', 0),
(@ID, 'esMX', 'Has hecho bien en atender a las gacelas enfermas de Los Baldíos, son las víctimas inocentes de una corrupción y contaminación mayores que se está extendiendo por toda la zona. Como $r, estás muy impaciente por entender los movimientos de Cenario; tú, al igual que tus ancestros de Cima del Trueno, eres la prueba de que la necesidad de equilibrio trasciende las barreras raciales artificiales.$B$B$n, has demostrado tu valía como amigo de la naturaleza y del Círculo, toma esto como símbolo de esta cualidad.', 0);
-- 6130 Poder contra el veneno
-- https://es.classic.wowhead.com/quest=6130
SET @ID := 6130;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos. He observado tu progreso y debo admitir que la situación de El Cruce me ha sorprendido. Esos venenos alteran el equilibrio.$B$BMe ha gustado tu forma de actuar; te concedo poder permanente sobre el veneno. Úsalo con prudencia, $n.', 0),
(@ID, 'esMX', 'Saludos. He observado tu progreso y debo admitir que la situación de El Cruce me ha sorprendido. Esos venenos alteran el equilibrio.$B$BMe ha gustado tu forma de actuar; te concedo poder permanente sobre el veneno. Úsalo con prudencia, $n.', 0);
-- 6131 Aliado Fauces de Madera
-- https://es.classic.wowhead.com/quest=6131
SET @ID := 6131;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sufrimos mucho por los eventos del pasado. Gracias por lo que ha hecho para ayudar a proteger Fauces de Madera.', 0),
(@ID, 'esMX', 'Sufrimos mucho por los eventos del pasado. Gracias por lo que ha hecho para ayudar a proteger Fauces de Madera.', 0);
-- 6133 La orden del Señor forestal
-- https://es.classic.wowhead.com/quest=6133
SET @ID := 6133;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me dejes aquí esperando, $c.', 0),
(@ID, 'esMX', 'No me dejes aquí esperando, $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que no leyeras el documento. Aunque supongo que ni siquiera tú harías algo tan estúpido...', 0),
(@ID, 'esMX', 'Espero que no leyeras el documento. Aunque supongo que ni siquiera tú harías algo tan estúpido...', 0);
-- 6135 Alaocaso, cómo te odio...
-- https://es.classic.wowhead.com/quest=6135
SET @ID := 6135;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No te aconsejo que afrontes este desafío sin ayuda, $c.', 0),
(@ID, 'esMX', 'No te aconsejo que afrontes este desafío sin ayuda, $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo excelente, imbécil. Convertiré esta piel en algo que puedas usar.', 0),
(@ID, 'esMX', 'Un trabajo excelente, imbécil. Convertiré esta piel en algo que puedas usar.', 0);
-- 6136 El corpulento
-- https://es.classic.wowhead.com/quest=6136
SET @ID := 6136;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te he dicho últimamente que te odio?', 0),
(@ID, 'esMX', '¿Te he dicho últimamente que te odio?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si sigues así, tendré que ascenderte de imbécil a deficiente mental de primera clase.', 0),
(@ID, 'esMX', 'Si sigues así, tendré que ascenderte de imbécil a deficiente mental de primera clase.', 0);
-- 6142 Almejas
-- https://es.classic.wowhead.com/quest=6142
SET @ID := 6142;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy deseando ir a pescar con un poco de carne de almeja blanda fresca; ¿me has traído las 10 piezas que necesito?', 0),
(@ID, 'esMX', 'Estoy deseando ir a pescar con un poco de carne de almeja blanda fresca; ¿me has traído las 10 piezas que necesito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Perfecto, colega, es justo lo que me recetó el médico brujo para mi dolor de cabeza. Dijo: "Mai\'Lahii, ve a pescar. Te hará sentir mejor."$B$B¡Y ya estoy mejor! ¡Gracias, colega!', 0),
(@ID, 'esMX', 'Perfecto, colega, es justo lo que me recetó el médico brujo para mi dolor de cabeza. Dijo: "Mai\'Lahii, ve a pescar. Te hará sentir mejor."$B$B¡Y ya estoy mejor! ¡Gracias, colega!', 0);
-- 6143 Otros pescados para freír
-- https://es.classic.wowhead.com/quest=6143
SET @ID := 6143;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todavía escucho sus voces pidiendo ayuda cuando los nagas desataron el caos sobre nosotros. ¡Si no tuviera esta rodilla lastimada, iría y te ayudaría a matar a esos malditos naga!$B$BPor lo general los encontrarás en las profundidades de los arrecifes de coral debajo de la superficie... acechando... intrigando...', 0),
(@ID, 'esMX', 'Todavía escucho sus voces pidiendo ayuda cuando los nagas desataron el caos sobre nosotros. ¡Si no tuviera esta rodilla lastimada, iría y te ayudaría a matar a esos malditos naga!$B$BPor lo general los encontrarás en las profundidades de los arrecifes de coral debajo de la superficie... acechando... intrigando...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por dulce que sea saber que los nagas han sido derrotados, aún siento un vacío en el corazón. Dedicaré el resto de mi vida a erradicarlos a todos.$B$BTen, colega, aquí tienes la recompensa que te prometí. Es pequeña en comparación con la gratificación de saber que los nagas han sido castigados por su odioso acto.', 0),
(@ID, 'esMX', 'Por dulce que sea saber que los nagas han sido derrotados, aún siento un vacío en el corazón. Dedicaré el resto de mi vida a erradicarlos a todos.$B$BTen, colega, aquí tienes la recompensa que te prometí. Es pequeña en comparación con la gratificación de saber que los nagas han sido castigados por su odioso acto.', 0);
-- 6144 La llamada del teniente
-- https://es.classic.wowhead.com/quest=6144
SET @ID := 6144;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Gran Cruzado está al seguro en El Bastión Escarlata mientras sus ejércitos arrasan tus tierras, profanan tus estructuras y monumentos y matan a tu gente.$B$BLa Dama Oscura me ha ordenado que acabe con ese insecto de una vez por todas. Tú serás el instrumento que haga justicia a los Renegados.', 0),
(@ID, 'esMX', 'El Gran Cruzado está al seguro en El Bastión Escarlata mientras sus ejércitos arrasan tus tierras, profanan tus estructuras y monumentos y matan a tu gente.$B$BLa Dama Oscura me ha ordenado que acabe con ese insecto de una vez por todas. Tú serás el instrumento que haga justicia a los Renegados.', 0);
-- El mensajero carmesí
-- 6145, 14350
-- https://es.classic.wowhead.com/quest=6145
DELETE FROM `quest_request_items_locale` WHERE `id` IN(6145, 14350) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(6145, 'esES', 'Ten éxito ahora y casi te habrás ganado mi respeto, $n.', 0),
(14350, 'esES', 'Ten éxito ahora y casi te habrás ganado mi respeto, $n.', 0),
(6145, 'esMX', 'Ten éxito ahora y casi te habrás ganado mi respeto, $n.', 0),
(14350, 'esMX', 'Ten éxito ahora y casi te habrás ganado mi respeto, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(6145, 14350) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(6145, 'esES', '<Nathanos se ríe.>$B$B¡Excelente! ¡Finalmente! ¡Una oportunidad para destruir el Oráculo Escarlata!', 0),
(14350, 'esES', '<Nathanos se ríe.>$B$B¡Excelente! ¡Finalmente! ¡Una oportunidad para destruir el Oráculo Escarlata!', 0),
(6145, 'esMX', '<Nathanos se ríe.>$B$B¡Excelente! ¡Finalmente! ¡Una oportunidad para destruir el Oráculo Escarlata!', 0),
(14350, 'esMX', '<Nathanos se ríe.>$B$B¡Excelente! ¡Finalmente! ¡Una oportunidad para destruir el Oráculo Escarlata!', 0);
-- 6146 La estratagema de Nathanos
-- https://es.classic.wowhead.com/quest=6146
SET @ID := 6146;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto es inaceptable, soldado!', 0),
(@ID, 'esMX', '¡Esto es inaceptable, soldado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dónde has estado? Creíamos que la Plaga te había capturado.', 0),
(@ID, 'esMX', '¿Dónde has estado? Creíamos que la Plaga te había capturado.', 0);
-- 6147 Regresa junto a Nathanos
-- https://es.classic.wowhead.com/quest=6147
SET @ID := 6147;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los tontos! ¡Mi engaño pasó inadvertido! Prepárese, $n. ¡Debemos atacar con fría astucia!', 0),
(@ID, 'esMX', '¡Los tontos! ¡Mi engaño pasó inadvertido! Prepárese, $n. ¡Debemos atacar con fría astucia!', 0);
-- 6148 El Oráculo Escarlata, Demetria
-- https://es.classic.wowhead.com/quest=6148
SET @ID := 6148;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué pasa, $n?', 0),
(@ID, 'esMX', '¿Qué pasa, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estarán tambaleándose por este golpe durante años! ¡Bien hecho, $n! No solo te has ganado mi respeto, sino también esta recompensa.', 0),
(@ID, 'esMX', '¡Estarán tambaleándose por este golpe durante años! ¡Bien hecho, $n! No solo te has ganado mi respeto, sino también esta recompensa.', 0);
-- 6162 La última batalla de un marido
-- https://es.classic.wowhead.com/quest=6162
SET @ID := 6162;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes ya la zarpa de esa bestia, $n? Pagará por sus crímenes. Me da igual si ha sido corrompido o si solo está enfadado por vivir en un bosque tan sombrío. ¡Cualquier fúrbolg que dañe a mi familia recibirá su castigo!', 0),
(@ID, 'esMX', '¿Tienes ya la zarpa de esa bestia, $n? Pagará por sus crímenes. Me da igual si ha sido corrompido o si solo está enfadado por vivir en un bosque tan sombrío. ¡Cualquier fúrbolg que dañe a mi familia recibirá su castigo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me has honrado cumpliendo tu palabra. Mi marido murió en combate... él también estaría orgulloso. Pero yo no iba a encontrar paz hasta que la criatura que me ha obligado a vivir mi vida en soledad pagara por lo que había hecho.$B$BGracias otra vez, $n.', 0),
(@ID, 'esMX', 'Me has honrado cumpliendo tu palabra. Mi marido murió en combate... él también estaría orgulloso. Pero yo no iba a encontrar paz hasta que la criatura que me ha obligado a vivir mi vida en soledad pagara por lo que había hecho.$B$BGracias otra vez, $n.', 0);
-- 6163 Ramstein
-- https://es.classic.wowhead.com/quest=6163
SET @ID := 6163;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Después de que Sylvanas me liberó, cacé a la bestia por estos páramos durante meses. Huyó a la seguridad de Stratholme. El bastardo...', 0),
(@ID, 'esMX', 'Después de que Sylvanas me liberó, cacé a la bestia por estos páramos durante meses. Huyó a la seguridad de Stratholme. El bastardo...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me pregunto ... ¿suplicó misericordia? ¿Podría saber qué es la misericordia?$B$B<Nathanos escupe.>$B$BColgaré la cabeza de esta bestia en mi pared.$B$BTe has ganado un lugar entre uno de mis campeones, $n.$B$B<Nathanos saluda.>', 0),
(@ID, 'esMX', 'Me pregunto ... ¿suplicó misericordia? ¿Podría saber qué es la misericordia?$B$B<Nathanos escupe.>$B$BColgaré la cabeza de esta bestia en mi pared.$B$BTe has ganado un lugar entre uno de mis campeones, $n.$B$B<Nathanos saluda.>', 0);
-- 6164 Libro de entradas de Augustus
-- https://es.classic.wowhead.com/quest=6164
SET @ID := 6164;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes mi libro de entradas? ¡Estoy deseando volver a los negocios!', 0),
(@ID, 'esMX', '¿Tienes mi libro de entradas? ¡Estoy deseando volver a los negocios!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Aquí está! ¡Huy, vaya! Se me había olvidado lo lleno que estaba.$B$B¡Este es un día glorioso, $n! ¡Formidable! ¡Un día de locos, diría!', 0),
(@ID, 'esMX', '¡Aquí está! ¡Huy, vaya! Se me había olvidado lo lleno que estaba.$B$B¡Este es un día glorioso, $n! ¡Formidable! ¡Un día de locos, diría!', 0);
-- 6182 El primero y el último
-- https://es.classic.wowhead.com/quest=6182
SET @ID := 6182;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tras algunos informes sobre extraña actividad de los Renegados en las Tierras de la Plaga del Este, se enviaron agentes del IV:7 a investigar. Los resultados de esa investigación son inquietantes.', 0),
(@ID, 'esMX', 'Tras algunos informes sobre extraña actividad de los Renegados en las Tierras de la Plaga del Este, se enviaron agentes del IV:7 a investigar. Los resultados de esa investigación son inquietantes.', 0);
-- 6183 Honra a los muertos
-- https://es.classic.wowhead.com/quest=6183
SET @ID := 6183;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Mathias asiente.>$B$BConfiaba en que Bolvar me enviaría hombres y mujeres de honor... los soldados más dedicados de la Alianza.', 0),
(@ID, 'esMX', '<Mathias asiente.>$B$BConfiaba en que Bolvar me enviaría hombres y mujeres de honor... los soldados más dedicados de la Alianza.', 0);
-- 6184 Flint Sombramás
-- https://es.classic.wowhead.com/quest=6184
SET @ID := 6184;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La primera misión será muy directa, $n. Entras y sales. Reconocimiento...', 0),
(@ID, 'esMX', 'La primera misión será muy directa, $n. Entras y sales. Reconocimiento...', 0);
-- 6185 Las pestes del este
-- https://es.classic.wowhead.com/quest=6185
SET @ID := 6185;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿¿Ha... ha habido suerte??', 0),
(@ID, 'esMX', '¿¿Ha... ha habido suerte??', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Rutger. Fredo. Turyen. Todos... muertos...$B$B<Flint agarra con fuerza las insignias.>$B$B¿Dónde estaban? ¿Averiguaste algo más sobre ese bastardo de Clamañublo?', 0),
(@ID, 'esMX', 'Rutger. Fredo. Turyen. Todos... muertos...$B$B<Flint agarra con fuerza las insignias.>$B$B¿Dónde estaban? ¿Averiguaste algo más sobre ese bastardo de Clamañublo?', 0);
-- 6186 El regreso de Clamañublo
-- https://es.classic.wowhead.com/quest=6186
SET @ID := 6186;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No... es... ¡NO! ¿Cómo? ¿Un agente de los Renegados? ¿¿¿El CAMPEÓN de la reina alma en pena???$B$B<El Rey Varian Wrynn se desploma derrotado.>', 0),
(@ID, 'esMX', 'No... es... ¡NO! ¿Cómo? ¿Un agente de los Renegados? ¿¿¿El CAMPEÓN de la reina alma en pena???$B$B<El Rey Varian Wrynn se desploma derrotado.>', 0);
-- 6187 Restaurar el orden
-- https://es.classic.wowhead.com/quest=6187
SET @ID := 6187;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El rey Varian Wrynn está perdido en sus pensamientos>.', 0),
(@ID, 'esMX', '<El rey Varian Wrynn está perdido en sus pensamientos>.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es una tragedia. Creo que... nuestra raza está condenada, $n, condenada a perder a nuestros mejores guerreros, a nuestros héroes más nobles, a nuestros eruditos de más talento.$B$BEstamos en deuda contigo, $n, y te aseguro que esté donde esté Nathanos Marris, te estará sonriendo.', 0),
(@ID, 'esMX', 'Es una tragedia. Creo que... nuestra raza está condenada, $n, condenada a perder a nuestros mejores guerreros, a nuestros héroes más nobles, a nuestros eruditos de más talento.$B$BEstamos en deuda contigo, $n, y te aseguro que esté donde esté Nathanos Marris, te estará sonriendo.', 0);
-- 6241 Actividad de los Nevada
-- https://es.classic.wowhead.com/quest=6241
SET @ID := 6241;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por lo que has hecho. Sigue ayudándonos, $n. Tenemos muy pocos aliados a los que recurrir.', 0),
(@ID, 'esMX', 'Gracias por lo que has hecho. Sigue ayudándonos, $n. Tenemos muy pocos aliados a los que recurrir.', 0);
-- 6282 La amenaza de las arpías
-- https://es.classic.wowhead.com/quest=6282
SET @ID := 6282;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No te canses de la Vega Carbonizada; muchas criaturas malvadas residen en esas colinas. Mantente fuerte $n y vencerás esta amenaza a nuestra gente. Ahora ve y ataca con fuerza; nuestros hijos nunca conocerán esta maldad.', 0),
(@ID, 'esMX', 'No te canses de la Vega Carbonizada; muchas criaturas malvadas residen en esas colinas. Mantente fuerte $n y vencerás esta amenaza a nuestra gente. Ahora ve y ataca con fuerza; nuestros hijos nunca conocerán esta maldad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué noticias tan excelentes! Cuéntame de nuevo cómo conseguiste crear la sombra del miedo en los fríos corazones de esas malvadas arpías. ¡Un duro golpe para los Furia Sangrienta!', 0),
(@ID, 'esMX', '¡Qué noticias tan excelentes! Cuéntame de nuevo cómo conseguiste crear la sombra del miedo en los fríos corazones de esas malvadas arpías. ¡Un duro golpe para los Furia Sangrienta!', 0);
-- 6283 El linaje Furia Sangrienta
-- https://es.classic.wowhead.com/quest=6283
SET @ID := 6283;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La desgarradora Furia Sangrienta es una criatura asquerosa! Podrás encontrarla en las colinas del oeste de La Vega Carbonizada.$B$BCuando acabemos con ella, el clan Furia Sangrienta se verá desvalido... ¡Y podremos acabar con la amenaza para siempre!', 0),
(@ID, 'esMX', '¡La desgarradora Furia Sangrienta es una criatura asquerosa! Podrás encontrarla en las colinas del oeste de La Vega Carbonizada.$B$BCuando acabemos con ella, el clan Furia Sangrienta se verá desvalido... ¡Y podremos acabar con la amenaza para siempre!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya siento que la ira me abandona. ¿Qué haré con mi tiempo? Saber que el mal rondaba cerca de mis tierras era lo que mantenía mi mente ocupada, pero ahora está en reposo. Tal vez sea lo mejor... tal vez ahora pueda concentrarme en las bondades de la vida, como todo $r.$B$BAcepta esta recompensa por las molestias.', 0),
(@ID, 'esMX', 'Ya siento que la ira me abandona. ¿Qué haré con mi tiempo? Saber que el mal rondaba cerca de mis tierras era lo que mantenía mi mente ocupada, pero ahora está en reposo. Tal vez sea lo mejor... tal vez ahora pueda concentrarme en las bondades de la vida, como todo $r.$B$BAcepta esta recompensa por las molestias.', 0);
-- 6284 Aracnofobia
-- https://es.classic.wowhead.com/quest=6284
SET @ID := 6284;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Besseleth es una depredadora despiadada... Temo por aquellos que viajan por la Senda de las Tejedoras por la noche. Es por la noche cuando ella y sus hijos salen en busca de viajeros inocentes. Yo fui víctima de su enorme colmillo de la muerte pero, por suerte, conseguí escaparme y salir con vida. Daría lo que fuera por ver a ese monstruo destruido.', 0),
(@ID, 'esMX', 'Besseleth es una depredadora despiadada... Temo por aquellos que viajan por la Senda de las Tejedoras por la noche. Es por la noche cuando ella y sus hijos salen en busca de viajeros inocentes. Yo fui víctima de su enorme colmillo de la muerte pero, por suerte, conseguí escaparme y salir con vida. Daría lo que fuera por ver a ese monstruo destruido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buena cacería, $n! Besseleth es una vieja depredadora de esta zona... No la echaré de menos. Acepta esta recompensa por ser $gel campeón:la campeona; del bosque.$B$B<Maggran se toca la herida causada por Besseleth.> $B$BQuizás ahora, muchos más irán al Refugio Roca del Sol sin temer lo que acecha en la oscuridad.', 0),
(@ID, 'esMX', '¡Buena cacería, $n! Besseleth es una vieja depredadora de esta zona... No la echaré de menos. Acepta esta recompensa por ser $gel campeón:la campeona; del bosque.$B$B<Maggran se toca la herida causada por Besseleth.> $B$BQuizás ahora, muchos más irán al Refugio Roca del Sol sin temer lo que acecha en la oscuridad.', 0);
-- 6301 El ciclo del renacimiento
-- https://es.classic.wowhead.com/quest=6301
SET @ID := 6301;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La destrucción continua provocada por la guerra y por aquellos que buscan sacar provecho de la madera, me entristece profundamente. Para ayudar al ciclo de la vida y reponer las tierras, necesito semillas de Gaia. ¿Las tienes, $c?', 0),
(@ID, 'esMX', 'La destrucción continua provocada por la guerra y por aquellos que buscan sacar provecho de la madera, me entristece profundamente. Para ayudar al ciclo de la vida y reponer las tierras, necesito semillas de Gaia. ¿Las tienes, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n, ¡tienes las semillas de Gaia! Observa cómo la bendición de la Madre Tierra puede conseguir que, incluso estas pequeñas semillas de vida, florezcan y crezcan.$B$B<Tammra comienza a cantar.>', 0),
(@ID, 'esMX', 'Ah, $n, ¡tienes las semillas de Gaia! Observa cómo la bendición de la Madre Tierra puede conseguir que, incluso estas pequeñas semillas de vida, florezcan y crezcan.$B$B<Tammra comienza a cantar.>', 0);
-- 6321 Suministros para El Sepulcro
-- https://es.classic.wowhead.com/quest=6321
SET @ID := 6321;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pareces tener un encargo oficial...', 0),
(@ID, 'esMX', 'Pareces tener un encargo oficial...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, un pedido de suministros. Sin duda querrás llevar esto a Entrañas. Y hazlo rápido, El Sepulcro no puede estar sin suministros.', 0),
(@ID, 'esMX', 'Ah, un pedido de suministros. Sin duda querrás llevar esto a Entrañas. Y hazlo rápido, El Sepulcro no puede estar sin suministros.', 0);
-- 6322 Michael Garrett
-- https://es.classic.wowhead.com/quest=6322
SET @ID := 6322;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si tienes que viajar largas distancias, lo mejor es que utilices un murciélago.', 0),
(@ID, 'esMX', 'Si tienes que viajar largas distancias, lo mejor es que utilices un murciélago.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Esta caja debe llegar a El Sepulcro en Argénteos? Sin problemas, nuestros murciélagos vuelan allí diariamente.', 0),
(@ID, 'esMX', '¿Esta caja debe llegar a El Sepulcro en Argénteos? Sin problemas, nuestros murciélagos vuelan allí diariamente.', 0);
-- 6323 Vuela a Entrañas
-- https://es.classic.wowhead.com/quest=6323
SET @ID := 6323;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuido muy bien mis armas. Están limpias y preparadas.', 0),
(@ID, 'esMX', 'Cuido muy bien mis armas. Están limpias y preparadas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un pedido de El Sepulcro? Muy bien. Es un honor servir a quienes sirven a nuestra Dama Oscura.', 0),
(@ID, 'esMX', '¿Un pedido de El Sepulcro? Muy bien. Es un honor servir a quienes sirven a nuestra Dama Oscura.', 0);
-- 6324 Vuelve con Podrig
-- https://es.classic.wowhead.com/quest=6324
SET @ID := 6324;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, has vuelto. ¿Tienes nuestros suministros de Entrañas?', 0),
(@ID, 'esMX', '$n, has vuelto. ¿Tienes nuestros suministros de Entrañas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Estas armas asegurarán que nuestros guardias de la muerte no sean cogidos sin estar preparados.$B$BHas hecho un gran servicio a nuestra Dama Oscura.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Estas armas asegurarán que nuestros guardias de la muerte no sean cogidos sin estar preparados.$B$BHas hecho un gran servicio a nuestra Dama Oscura.', 0);
-- 6341 A Darnassus
-- https://es.classic.wowhead.com/quest=6341
SET @ID := 6341;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿En qué puedo ayudarte? ¿Necesitas transporte?', 0),
(@ID, 'esMX', '¿En qué puedo ayudarte? ¿Necesitas transporte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¿quieres llevar esto a Auberdine? Muy bien...', 0),
(@ID, 'esMX', 'Ah, ¿quieres llevar esto a Auberdine? Muy bien...', 0);
