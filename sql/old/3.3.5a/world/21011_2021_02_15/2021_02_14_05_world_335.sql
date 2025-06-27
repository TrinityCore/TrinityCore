-- 5128 Las palabras del Gran Jefe
-- https://es.classic.wowhead.com/quest=5128
SET @ID := 5128;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Círculo Esmeralda es amigo de todo el mundo, $r. ¿Qué puedo hacer por ti?', 0),
(@ID, 'esMX', 'El Círculo Esmeralda es amigo de todo el mundo, $r. ¿Qué puedo hacer por ti?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, si me dejas examinarlo un momento quizás pueda traducirlo.$B$B<Kelek hojea las páginas.>$B$BTe avisaré cuando lo haya examinado por completo.$B$BGracias por compartirlo conmigo, $n. Sabemos muy poco de los furbolgs Nevada.', 0),
(@ID, 'esMX', 'Sí, si me dejas examinarlo un momento quizás pueda traducirlo.$B$B<Kelek hojea las páginas.>$B$BTe avisaré cuando lo haya examinado por completo.$B$BGracias por compartirlo conmigo, $n. Sabemos muy poco de los furbolgs Nevada.', 0);
-- Peletería dragontina
-- 5141, 5145
-- https://es.classic.wowhead.com/quest=5141
DELETE FROM `quest_request_items_locale` WHERE `id` IN(5141, 5145) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(5141, 'esES', 'Si tu estás $glisto:lista; para comprometerte para siempre y convertirte en $gun peletero:una peletera; de escamas de dragón, entonces yo estoy listo para aceptarte como estudiante. Solo tráeme las cosas que te pedí y comenzaremos tu educación.', 0),
(5145, 'esES', 'Si tu estás $glisto:lista; para comprometerte para siempre y convertirte en $gun peletero:una peletera; de escamas de dragón, entonces yo estoy listo para aceptarte como estudiante. Solo tráeme las cosas que te pedí y comenzaremos tu educación.', 0),
(5141, 'esMX', 'Si tu estás $glisto:lista; para comprometerte para siempre y convertirte en $gun peletero:una peletera; de escamas de dragón, entonces yo estoy listo para aceptarte como estudiante. Solo tráeme las cosas que te pedí y comenzaremos tu educación.', 0),
(5145, 'esMX', 'Si tu estás $glisto:lista; para comprometerte para siempre y convertirte en $gun peletero:una peletera; de escamas de dragón, entonces yo estoy listo para aceptarte como estudiante. Solo tráeme las cosas que te pedí y comenzaremos tu educación.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5141, 5145) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5141, 'esES', 'Se necesita una voluntad fuerte para tomar una decisión como la que acabas de tomar. Te lo aseguro, la peletería de escamas de dragón demostrará ser un camino rentable y gratificante para que lo sigas.$B$BPara formarte en este arte, en el futuro, simplemente habla conmigo y pondré a tu disposición cualquier conocimiento que aún puedas aprender como tuyo.', 0),
(5145, 'esES', 'Se necesita una voluntad fuerte para tomar una decisión como la que acabas de tomar. Te lo aseguro, la peletería de escamas de dragón demostrará ser un camino rentable y gratificante para que lo sigas.$B$BPara formarte en este arte, en el futuro, simplemente habla conmigo y pondré a tu disposición cualquier conocimiento que aún puedas aprender como tuyo.', 0),
(5141, 'esMX', 'Se necesita una voluntad fuerte para tomar una decisión como la que acabas de tomar. Te lo aseguro, la peletería de escamas de dragón demostrará ser un camino rentable y gratificante para que lo sigas.$B$BPara formarte en este arte, en el futuro, simplemente habla conmigo y pondré a tu disposición cualquier conocimiento que aún puedas aprender como tuyo.', 0),
(5145, 'esMX', 'Se necesita una voluntad fuerte para tomar una decisión como la que acabas de tomar. Te lo aseguro, la peletería de escamas de dragón demostrará ser un camino rentable y gratificante para que lo sigas.$B$BPara formarte en este arte, en el futuro, simplemente habla conmigo y pondré a tu disposición cualquier conocimiento que aún puedas aprender como tuyo.', 0);
-- 5142 La pequeña Pamela
-- https://es.classic.wowhead.com/quest=5142
SET @ID := 5142;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola. Soy Pamela. ¿Y tú cómo te llamas?', 0),
(@ID, 'esMX', 'Hola. Soy Pamela. ¿Y tú cómo te llamas?', 0);
-- Peletería tribal
-- 5143, 5148
-- https://es.classic.wowhead.com/quest=5143
DELETE FROM `quest_request_items_locale` WHERE `id` IN(5143, 5148) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(5143, 'esES', 'La naturaleza es una fuerza que debe ser apaciguada antes de que esperes aprender a doblar su voluntad en tus prendas de cuero. Tráeme tu ofrenda a esta fuerza y me aseguraré de que te escuche.', 0),
(5148, 'esES', 'La naturaleza es una fuerza que debe ser apaciguada antes de que esperes aprender a doblar su voluntad en tus prendas de cuero. Tráeme tu ofrenda a esta fuerza y me aseguraré de que te escuche.', 0),
(5143, 'esMX', 'La naturaleza es una fuerza que debe ser apaciguada antes de que esperes aprender a doblar su voluntad en tus prendas de cuero. Tráeme tu ofrenda a esta fuerza y me aseguraré de que te escuche.', 0),
(5148, 'esMX', 'La naturaleza es una fuerza que debe ser apaciguada antes de que esperes aprender a doblar su voluntad en tus prendas de cuero. Tráeme tu ofrenda a esta fuerza y me aseguraré de que te escuche.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5143, 5148) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5143, 'esES', 'Has dado tus mejores ofrendas y la naturaleza pronto te permitirá doblegarla a tu voluntad. Una vez que haya terminado mi tutela, tu trabajo será una fuerza de la naturaleza en sí misma.$B$BPara formarte en este arte, en el futuro, simplemente habla conmigo y pondré a tu disposición cualquier conocimiento que aún puedas aprender.', 0),
(5148, 'esES', 'Has dado tus mejores ofrendas y la naturaleza pronto te permitirá doblegarla a tu voluntad. Una vez que haya terminado mi tutela, tu trabajo será una fuerza de la naturaleza en sí misma.$B$BPara formarte en este arte, en el futuro, simplemente habla conmigo y pondré a tu disposición cualquier conocimiento que aún puedas aprender.', 0),
(5143, 'esMX', 'Has dado tus mejores ofrendas y la naturaleza pronto te permitirá doblegarla a tu voluntad. Una vez que haya terminado mi tutela, tu trabajo será una fuerza de la naturaleza en sí misma.$B$BPara formarte en este arte, en el futuro, simplemente habla conmigo y pondré a tu disposición cualquier conocimiento que aún puedas aprender.', 0),
(5148, 'esMX', 'Has dado tus mejores ofrendas y la naturaleza pronto te permitirá doblegarla a tu voluntad. Una vez que haya terminado mi tutela, tu trabajo será una fuerza de la naturaleza en sí misma.$B$BPara formarte en este arte, en el futuro, simplemente habla conmigo y pondré a tu disposición cualquier conocimiento que aún puedas aprender.', 0);
-- Peletería elemental
-- 5144, 5146
-- https://es.classic.wowhead.com/quest=5144
DELETE FROM `quest_request_items_locale` WHERE `id` IN(5144, 5146) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(5144, 'esES', 'Hacer este tipo de armadura a base de cuero requiere paciencia y dedicación. Una vez que hayas echado tu suerte a los elementos, no hay forma de darles la espalda. Tráeme una prueba de tu valía y empezaremos.', 0),
(5146, 'esES', 'Hacer este tipo de armadura a base de cuero requiere paciencia y dedicación. Una vez que hayas echado tu suerte a los elementos, no hay forma de darles la espalda. Tráeme una prueba de tu valía y empezaremos.', 0),
(5144, 'esMX', 'Hacer este tipo de armadura a base de cuero requiere paciencia y dedicación. Una vez que hayas echado tu suerte a los elementos, no hay forma de darles la espalda. Tráeme una prueba de tu valía y empezaremos.', 0),
(5146, 'esMX', 'Hacer este tipo de armadura a base de cuero requiere paciencia y dedicación. Una vez que hayas echado tu suerte a los elementos, no hay forma de darles la espalda. Tráeme una prueba de tu valía y empezaremos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5144, 5146) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5144, 'esES', 'Has echado tu suerte y los elementos te aceptan. Una vez que haya terminado mi tutela, confeccionarás los mejores atuendos de cuero.$B$BPara formarte en este arte, en el futuro, simplemente habla conmigo y pondré a tu disposición cualquier conocimiento que aún puedas aprender.', 0),
(5146, 'esES', 'Has echado tu suerte y los elementos te aceptan. Una vez que haya terminado mi tutela, confeccionarás los mejores atuendos de cuero.$B$BPara formarte en este arte, en el futuro, simplemente habla conmigo y pondré a tu disposición cualquier conocimiento que aún puedas aprender.', 0),
(5144, 'esMX', 'Has echado tu suerte y los elementos te aceptan. Una vez que haya terminado mi tutela, confeccionarás los mejores atuendos de cuero.$B$BPara formarte en este arte, en el futuro, simplemente habla conmigo y pondré a tu disposición cualquier conocimiento que aún puedas aprender.', 0),
(5146, 'esMX', 'Has echado tu suerte y los elementos te aceptan. Una vez que haya terminado mi tutela, confeccionarás los mejores atuendos de cuero.$B$BPara formarte en este arte, en el futuro, simplemente habla conmigo y pondré a tu disposición cualquier conocimiento que aún puedas aprender.', 0);
-- 5147 Se busca: Arnak Tótem Siniestro
-- https://es.classic.wowhead.com/quest=5147
SET @ID := 5147;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sabes algo del peligrosísimo Arnak Tótem Siniestro?', 0),
(@ID, 'esMX', '¿Sabes algo del peligrosísimo Arnak Tótem Siniestro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja! ¡Qué noticia tan estupenda! ¡Empezaba a pensar que nunca recibiría su merecido!$B$BAquí tienes, $n... y gracias. Con solo oír hablar de Arnak me hervía la sangre...', 0),
(@ID, 'esMX', '¡Ja! ¡Qué noticia tan estupenda! ¡Empezaba a pensar que nunca recibiría su merecido!$B$BAquí tienes, $n... y gracias. Con solo oír hablar de Arnak me hervía la sangre...', 0);
-- 5151 Hipercondensador
-- https://es.classic.wowhead.com/quest=5151
SET @ID := 5151;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes mi hipercondensador?', 0),
(@ID, 'esMX', '¿Tienes mi hipercondensador?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Mi hipercondensador! Esto me mantendrá ocupado hasta que pueda descifrar para qué sirve...', 0),
(@ID, 'esMX', '¡Mi hipercondensador! Esto me mantendrá ocupado hasta que pueda descifrar para qué sirve...', 0);
-- 5153 Una extraña historiadora
-- https://es.classic.wowhead.com/quest=5153
SET @ID := 5153;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Llegas en el momento justo, como si supieras cuándo tenías que llegar. No vendrás del futuro, ¿verdad?', 0),
(@ID, 'esMX', 'Llegas en el momento justo, como si supieras cuándo tenías que llegar. No vendrás del futuro, ¿verdad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto? ¿Una alianza? Déjame verla...$B$B¡Aah! Este anillo tenía su lugar en la mano de un gran hombre... pero el pasado de ese hombre está lleno de tragedia.$B$B¿Estás aquí para ayudarle? Es demasiado tarde para él... ¡pero quizás podamos ayudarle desde el pasado!', 0),
(@ID, 'esMX', '¿Qué es esto? ¿Una alianza? Déjame verla...$B$B¡Aah! Este anillo tenía su lugar en la mano de un gran hombre... pero el pasado de ese hombre está lleno de tragedia.$B$B¿Estás aquí para ayudarle? Es demasiado tarde para él... ¡pero quizás podamos ayudarle desde el pasado!', 0);
-- 5154 Las Crónicas de Villa Darrow
-- https://es.classic.wowhead.com/quest=5154
SET @ID := 5154;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste el libro, $n?', 0),
(@ID, 'esMX', '¿Encontraste el libro, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien hecho, lo tienes!$B$B¿Lo has leído? ¿Se menciona a Joseph Rutagrana? Si se habla de él, ¡quizás podamos salvarle!$B$BAh. Las Crómicas de Villa Darrow cuentan una historia tremenda. Dicen que durante la batalla, Joseph Rutagrana fue corrompido y que se unió a las filas de la Plaga. Traicionó a los defensores de Villa Darrow.$B$BQué destino atroz. Deberíamos intentar cambiar ese destino, ¿no te parece?', 0),
(@ID, 'esMX', '¡Bien hecho, lo tienes!$B$B¿Lo has leído? ¿Se menciona a Joseph Rutagrana? Si se habla de él, ¡quizás podamos salvarle!$B$BAh. Las Crómicas de Villa Darrow cuentan una historia tremenda. Dicen que durante la batalla, Joseph Rutagrana fue corrompido y que se unió a las filas de la Plaga. Traicionó a los defensores de Villa Darrow.$B$BQué destino atroz. Deberíamos intentar cambiar ese destino, ¿no te parece?', 0);
-- 5160 El Protectorado de la matrona
-- https://es.classic.wowhead.com/quest=5160
SET @ID := 5160;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de verte, $n.', 0),
(@ID, 'esMX', 'Me alegro de verte, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los Aspectos insisten en que nos mantengamos al margen de los asuntos de los mortales. En este mundo, sin embargo, no siempre es posible tal cosa, especialmente cuando uno de los nuestros ignora una y otra vez esta regla.', 0),
(@ID, 'esMX', 'Los Aspectos insisten en que nos mantengamos al margen de los asuntos de los mortales. En este mundo, sin embargo, no siempre es posible tal cosa, especialmente cuando uno de los nuestros ignora una y otra vez esta regla.', 0);
-- 5161 La cólera del Vuelo Azul
-- https://es.classic.wowhead.com/quest=5161
SET @ID := 5161;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que así sea...', 0),
(@ID, 'esMX', 'Que así sea...', 0);
-- 5162 La cólera del Vuelo Azul
-- https://es.classic.wowhead.com/quest=5162
SET @ID := 5162;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Soy Jeziba, conocido por muchos como el Escultor. Pero lo que esculpo no son estatuas, son héroes.', 0),
(@ID, 'esMX', 'Soy Jeziba, conocido por muchos como el Escultor. Pero lo que esculpo no son estatuas, son héroes.', 0);
-- 5163 Yeti... ¿ya hemos llegado?
-- https://es.classic.wowhead.com/quest=5163
SET @ID := 5163;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Asusta a Legacki', `ObjectiveText2` = 'Asusta a Roxio', `ObjectiveText3` = 'Asusta a Quixxil', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 5164 Catálogo del Díscolo
-- https://es.classic.wowhead.com/quest=5164
SET @ID := 5164;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El libro parece componerse de cientos y cientos de páginas llenas de texto enrevesado, garabatos y símbolos.', 0),
(@ID, 'esMX', 'El libro parece componerse de cientos y cientos de páginas llenas de texto enrevesado, garabatos y símbolos.', 0);
-- 5165 Sofocar las llamas de protección
-- https://es.classic.wowhead.com/quest=5165
SET @ID := 5165;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Extingue el Blandón del Dolor', `ObjectiveText2` = 'Extingue el Blandón de la Maldad', `ObjectiveText3` = 'Extingue el Blandón del Sufrimiento', `ObjectiveText4` = 'Extingue el Blandón del Odio', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 5166 Coraza del Vuelo Cromático
-- https://es.classic.wowhead.com/quest=5166
SET @ID := 5166;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has elegido sabiamente, $r.', 0),
(@ID, 'esMX', 'Has elegido sabiamente, $r.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Aún no lo entiendes? El viaje fue el destino. ¿No puedes sentir las cicatrices de la batalla? ¿El dolor que sufriste?$B$BHabiendo sobrevivido a la terrible experiencia, eres un ser más poderoso. Mucho más poderoso. Esta coraza es simplemente un reflejo de tus propias habilidades innatas.', 0),
(@ID, 'esMX', '¿Aún no lo entiendes? El viaje fue el destino. ¿No puedes sentir las cicatrices de la batalla? ¿El dolor que sufriste?$B$BHabiendo sobrevivido a la terrible experiencia, eres un ser más poderoso. Mucho más poderoso. Esta coraza es simplemente un reflejo de tus propias habilidades innatas.', 0);
-- 5167 Quijotes del desafiante cromático
-- https://es.classic.wowhead.com/quest=5167
SET @ID := 5167;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Nunca se ha elaborado un objeto así!', 0),
(@ID, 'esMX', '¡Nunca se ha elaborado un objeto así!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Olerán a sus parientes cuando entres en sus pasillos, $n. ¡Aplastarlos con su propio miedo!', 0),
(@ID, 'esMX', 'Olerán a sus parientes cuando entres en sus pasillos, $n. ¡Aplastarlos con su propio miedo!', 0);
-- 5168 Los héroes de Villa Darrow
-- https://es.classic.wowhead.com/quest=5168
SET @ID := 5168;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las reliquias, $n?', 0),
(@ID, 'esMX', '¿Tienes las reliquias, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tienes el libro y el escudo!$B$BSu historia está entrelazada con la de Villa Darrow y, de alguna forma, sé que el destino volverá a unirlos.', 0),
(@ID, 'esMX', '¡Tienes el libro y el escudo!$B$BSu historia está entrelazada con la de Villa Darrow y, de alguna forma, sé que el destino volverá a unirlos.', 0);
-- 5181 Los villanos de Villa Darrow
-- https://es.classic.wowhead.com/quest=5181
SET @ID := 5181;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste la calavera y la espada, $n?', 0),
(@ID, 'esMX', '¿Encontraste la calavera y la espada, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Las has encontrado! ¡Bien hecho, $n! Estas reliquias poseen un poder que no entiendo del todo, un poder que un día controlarás.$B$BY también me traen recuerdos oscuros, recuerdos de muerte y traición, y de la última noche de Villa Darrow...', 0),
(@ID, 'esMX', '¡Las has encontrado! ¡Bien hecho, $n! Estas reliquias poseen un poder que no entiendo del todo, un poder que un día controlarás.$B$BY también me traen recuerdos oscuros, recuerdos de muerte y traición, y de la última noche de Villa Darrow...', 0);
-- 5201 Intrusión Nevada
-- https://es.classic.wowhead.com/quest=5201
SET @ID := 5201;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los furbolgs parecen sufrir de paranoia...', 0),
(@ID, 'esMX', 'Los furbolgs parecen sufrir de paranoia...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alivia escuchar que, por un momento, no tendremos que preocuparnos por la intrusión de los Nevada.$B$BEstás empezando a mostrar tu perseverancia, $n.', 0),
(@ID, 'esMX', 'Me alivia escuchar que, por un momento, no tendremos que preocuparnos por la intrusión de los Nevada.$B$BEstás empezando a mostrar tu perseverancia, $n.', 0);
-- 5202 Una extraña llave roja
-- https://es.classic.wowhead.com/quest=5202
SET @ID := 5202;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Empiezo a preguntarme si alguna vez conseguiré escapar de esta jaula.$B$BEs solo cuestión de tiempo... acabarán sacrificándome en el altar de sus demonios... ¡Esos monstruos!', 0),
(@ID, 'esMX', 'Empiezo a preguntarme si alguna vez conseguiré escapar de esta jaula.$B$BEs solo cuestión de tiempo... acabarán sacrificándome en el altar de sus demonios... ¡Esos monstruos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La llave! ¡La has encontrado! ¡Dámela, por favor, para que pueda escapar por fin!', 0),
(@ID, 'esMX', '¡La llave! ¡La has encontrado! ¡Dámela, por favor, para que pueda escapar por fin!', 0);
-- 5203 El rescate en Jaedenar
-- https://es.classic.wowhead.com/quest=5203
SET @ID := 5203;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te ves sin aliento, $n. ¿Estás bien o pasa algo?', 0),
(@ID, 'esMX', 'Te ves sin aliento, $n. ¿Estás bien o pasa algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Eres tú quien ayudó a Arko a escapar? Cómo me alegro de que me hayas encontrado. Ella pasó por aquí hace no mucho, de camino a Darnassus. Forjaluz iba pisándole los talones y no tenía ni tiempo para hablar con los druidas y hacer que le curaran las heridas. Dijo que tenía mucha prisa.$B$BPero sí me contó tu encuentro con el espíritu de Trey. Qué destino tan cruel para un caballero de la Mano de Plata. Ella intentaba ocultarlo, pero era evidente que la pérdida que ha sufrido le está desgarrando las entrañas.', 0),
(@ID, 'esMX', '¿Eres tú quien ayudó a Arko a escapar? Cómo me alegro de que me hayas encontrado. Ella pasó por aquí hace no mucho, de camino a Darnassus. Forjaluz iba pisándole los talones y no tenía ni tiempo para hablar con los druidas y hacer que le curaran las heridas. Dijo que tenía mucha prisa.$B$BPero sí me contó tu encuentro con el espíritu de Trey. Qué destino tan cruel para un caballero de la Mano de Plata. Ella intentaba ocultarlo, pero era evidente que la pérdida que ha sufrido le está desgarrando las entrañas.', 0);
-- 5204 La reprensión de la Luz
-- https://es.classic.wowhead.com/quest=5204
SET @ID := 5204;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Inspeccionas el cuerpo. No hay duda de que estos son los restos de Trey Forjaluz, el caballero de la Mano de Plata. Piensas en Arko\'narin y te preguntas si hay alguien en tu vida que signifique tanto como este hombre significaba para la elfo de la noche cautiva a la que ayudaste a escapar de la Guarida Sombría.$B$BPero sabes que no puedes llevar los restos del paladín a Jessir sin antes matar a su torturador.', 0),
(@ID, 'esMX', 'Inspeccionas el cuerpo. No hay duda de que estos son los restos de Trey Forjaluz, el caballero de la Mano de Plata. Piensas en Arko\'narin y te preguntas si hay alguien en tu vida que signifique tanto como este hombre significaba para la elfo de la noche cautiva a la que ayudaste a escapar de la Guarida Sombría.$B$BPero sabes que no puedes llevar los restos del paladín a Jessir sin antes matar a su torturador.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Reúnes los restos del paladín con tanto cuidado como puedes, recordando que al menos su espíritu ha sido liberado del sufrimiento que pudieran haberle infligido.', 0),
(@ID, 'esMX', 'Reúnes los restos del paladín con tanto cuidado como puedes, recordando que al menos su espíritu ha sido liberado del sufrimiento que pudieran haberle infligido.', 0);
-- 5206 Los merodeadores de Villa Darrow
-- https://es.classic.wowhead.com/quest=5206
SET @ID := 5206;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las calaveras? Cromi dijo que eran imprescindibles para su hechizo. Y ese hechizo nos dará la oportunidad de salvar Villa Darrow.', 0),
(@ID, 'esMX', '¿Tienes las calaveras? Cromi dijo que eran imprescindibles para su hechizo. Y ese hechizo nos dará la oportunidad de salvar Villa Darrow.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Las has encontrado! ¡Estupendo!$B$BAunque no acabo de entender bien cómo pueden ayudarnos, siento su poder y, en mi fuero interno, sé que están relacionadas con mi hogar, con Villa Darrow.', 0),
(@ID, 'esMX', '¡Las has encontrado! ¡Estupendo!$B$BAunque no acabo de entender bien cómo pueden ayudarnos, siento su poder y, en mi fuero interno, sé que están relacionadas con mi hogar, con Villa Darrow.', 0);
-- 5210 Carlin, el hermano de Joseph
-- https://es.classic.wowhead.com/quest=5210
SET @ID := 5210;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Vienes del oeste? ¿Cómo va el resto de Lordaeron? Sé que Andorhal está perdido pero, ¿es cierto que la Plaga ha llegado a Tirisfal?', 0),
(@ID, 'esMX', '¿Vienes del oeste? ¿Cómo va el resto de Lordaeron? Sé que Andorhal está perdido pero, ¿es cierto que la Plaga ha llegado a Tirisfal?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué libro es este? ¿Las Crónicas de Villa Darrow? Ese era mi hogar antes de la guerra... ¡antes de que aquella batalla lo destruyera! ¿Por qué me has traído este libro?$B$B¡Mira aquí! ¡Al final hay unas páginas que cuentan los días que siguieron a la batalla! ¡Y este pasaje habla de mí! ¡Y hay otro sobre mi hermano Joseph! ¿Lo que dice este libro es cierto?$B$B¡Hemos de saber la verdad!', 0),
(@ID, 'esMX', '¿Qué libro es este? ¿Las Crónicas de Villa Darrow? Ese era mi hogar antes de la guerra... ¡antes de que aquella batalla lo destruyera! ¿Por qué me has traído este libro?$B$B¡Mira aquí! ¡Al final hay unas páginas que cuentan los días que siguieron a la batalla! ¡Y este pasaje habla de mí! ¡Y hay otro sobre mi hermano Joseph! ¿Lo que dice este libro es cierto?$B$B¡Hemos de saber la verdad!', 0);
-- 5211 Los defensores de Villa Darrow
-- https://es.classic.wowhead.com/quest=5211
SET @ID := 5211;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Espíritus de Villa Darrow liberados', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 5213 El agente activo
-- https://es.classic.wowhead.com/quest=5213
SET @ID := 5213;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estamos a punto de descubrir cuál es el nuevo agente activo de la plaga!', 0),
(@ID, 'esMX', '¡Estamos a punto de descubrir cuál es el nuevo agente activo de la plaga!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Increíble! Llevará meses diseccionar y analizar esto. El Alba Argenta te agradece tus esfuerzos, $n.$B$BElige entre este Sello del Amanecer y esta Runa del Amanecer, con nuestra bendición. Puedes utilizar cualquiera de los dos en lugar de una Comisión del Alba Argenta estándar para recoger piedras de la Peste para nosotros. Si se te pierde, habla conmigo y te conseguiré un reemplazo.', 0),
(@ID, 'esMX', '¡Increíble! Llevará meses diseccionar y analizar esto. El Alba Argenta te agradece tus esfuerzos, $n.$B$BElige entre este Sello del Amanecer y esta Runa del Amanecer, con nuestra bendición. Puedes utilizar cualquiera de los dos en lugar de una Comisión del Alba Argenta estándar para recoger piedras de la Peste para nosotros. Si se te pierde, habla conmigo y te conseguiré un reemplazo.', 0);
-- 5214 El gran Fras Siabi
-- https://es.classic.wowhead.com/quest=5214
SET @ID := 5214;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No puedo soportarlo, $n! ¡Tienes que ayudarme! ¡Me muero!', 0),
(@ID, 'esMX', '¡No puedo soportarlo, $n! ¡Tienes que ayudarme! ¡Me muero!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, tabaquito, tabaquito dulce, cuánto te he echado de menos...', 0),
(@ID, 'esMX', 'Oh, tabaquito, tabaquito dulce, cuánto te he echado de menos...', 0);
-- 5215 Las calderas de la Plaga
-- https://es.classic.wowhead.com/quest=5215
SET @ID := 5215;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que el poder de la Luz te ilumine en estos tiempos sombríos, $c. Me complace servirte como coordinadora en nuestro plan para sabotear las calderas de la Plaga.$B$BNuestro objetivo será alterar la composición de la peste que crean los calderos, convirtiéndola en algo que afecte negativamente a la Plaga. Para conseguir este cambio tendrás que acceder a las cuatro calderas de las Tierras de la Peste del Oeste.$B$BHas de estar $gpreparado, héroe:preparada, heroína;, ¡te espera una batalla gloriosa contra la vil Plaga!', 0),
(@ID, 'esMX', 'Que el poder de la Luz te ilumine en estos tiempos sombríos, $c. Me complace servirte como coordinadora en nuestro plan para sabotear las calderas de la Plaga.$B$BNuestro objetivo será alterar la composición de la peste que crean los calderos, convirtiéndola en algo que afecte negativamente a la Plaga. Para conseguir este cambio tendrás que acceder a las cuatro calderas de las Tierras de la Peste del Oeste.$B$BHas de estar $gpreparado, héroe:preparada, heroína;, ¡te espera una batalla gloriosa contra la vil Plaga!', 0);
-- 5216 Objetivo: Campo de Piedramácula
-- https://es.classic.wowhead.com/quest=5216
SET @ID := 5216;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un panel de acceso a la caldera sigue estando cerrado. Para abrirlo tendrás que encontrar la llave.', 0),
(@ID, 'esMX', 'Un panel de acceso a la caldera sigue estando cerrado. Para abrirlo tendrás que encontrar la llave.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La llave que has conseguido del señor de la caldera Garravil encaja perfectamente y abre el panel de acceso. Un hedor nauseabundo emana del panel una vez abierto, al tiempo que una mezcla desconocida de sustancias concentradas se arremolina en el interior de la caldera.$B$BHay una pequeña espita en la que encaja la botella y puedes recoger una muestra para la suma sacerdotisa MacDonnell en el Alto del Orvallo.', 0),
(@ID, 'esMX', 'La llave que has conseguido del señor de la caldera Garravil encaja perfectamente y abre el panel de acceso. Un hedor nauseabundo emana del panel una vez abierto, al tiempo que una mezcla desconocida de sustancias concentradas se arremolina en el interior de la caldera.$B$BHay una pequeña espita en la que encaja la botella y puedes recoger una muestra para la suma sacerdotisa MacDonnell en el Alto del Orvallo.', 0);
-- 5217 Regresa al Campamento del Orvallo
-- https://es.classic.wowhead.com/quest=5217
SET @ID := 5217;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bienvenido de vuelta a la relativa seguridad del Campamento del Orvallo, $n. ¿Tienes que informar sobre algún progreso con las calderas?', 0),
(@ID, 'esMX', 'Bienvenido de vuelta a la relativa seguridad del Campamento del Orvallo, $n. ¿Tienes que informar sobre algún progreso con las calderas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n, el alquimista Arbington no debería necesitar mucho tiempo para analizar esto y preparar un contraagente que introducir en la caldera. Si pudiéramos propagar suficiente contraagente en el aire podríamos debilitar la Plaga de este lugar.$B$BSerá sin duda un duro esfuerzo pero no podemos dejar de atentar contra esas calderas ni de introducir nuestros componentes en su mezcla. Sin embargo, si pudiéramos seguir así tendríamos una enorme ventaja sobre la Plaga cuando llegara el momento de la batalla.', 0),
(@ID, 'esMX', 'Bien hecho, $n, el alquimista Arbington no debería necesitar mucho tiempo para analizar esto y preparar un contraagente que introducir en la caldera. Si pudiéramos propagar suficiente contraagente en el aire podríamos debilitar la Plaga de este lugar.$B$BSerá sin duda un duro esfuerzo pero no podemos dejar de atentar contra esas calderas ni de introducir nuestros componentes en su mezcla. Sin embargo, si pudiéramos seguir así tendríamos una enorme ventaja sobre la Plaga cuando llegara el momento de la batalla.', 0);
-- 5218 La caldera del Campo de Piedramácula
-- https://es.classic.wowhead.com/quest=5218
SET @ID := 5218;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El caldero de la Plaga está ante ti, arrojando grandes cantidades de toxinas al aire. Un pequeño panel de acceso indescriptible se encuentra en la base de la vasta plataforma del caldero.$B$BDespués de haber derrotado al señor del caldero y tomado su llave, puedes agregar los reactivos apropiados al caldero para hacer un agente contra la plaga.', 0),
(@ID, 'esMX', 'El caldero de la Plaga está ante ti, arrojando grandes cantidades de toxinas al aire. Un pequeño panel de acceso indescriptible se encuentra en la base de la vasta plataforma del caldero.$B$BDespués de haber derrotado al señor del caldero y tomado su llave, puedes agregar los reactivos apropiados al caldero para hacer un agente contra la plaga.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al agregar los reactivos a la mezcla del caldero, este comienza a cambiar el color y la textura de la nube que arroja. Los miembros de la Plaga que están cerca del caldero parecen retroceder ante la introducción de los nuevos componentes en el medio ambiente.', 0),
(@ID, 'esMX', 'Al agregar los reactivos a la mezcla del caldero, este comienza a cambiar el color y la textura de la nube que arroja. Los miembros de la Plaga que están cerca del caldero parecen retroceder ante la introducción de los nuevos componentes en el medio ambiente.', 0);
-- 5219 Objetivo: Llanto de Dalson
-- https://es.classic.wowhead.com/quest=5219
SET @ID := 5219;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un panel de acceso a la caldera sigue estando cerrado. Para abrirlo tendrás que encontrar la llave.', 0),
(@ID, 'esMX', 'Un panel de acceso a la caldera sigue estando cerrado. Para abrirlo tendrás que encontrar la llave.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La macabra llave que encontraste en el señor de la caldera se desliza suavemente en la cerradura y desaparece, permitiéndote acceder permanentemente al panel. Unos icores crudos y viscosos palpitan a través de tubos retorcidos en el interior de la caldera.$B$BHay una pequeña espita en la que encaja la botella y puedes recoger una muestra para la suma sacerdotisa MacDonnell en el Alto del Orvallo.', 0),
(@ID, 'esMX', 'La macabra llave que encontraste en el señor de la caldera se desliza suavemente en la cerradura y desaparece, permitiéndote acceder permanentemente al panel. Unos icores crudos y viscosos palpitan a través de tubos retorcidos en el interior de la caldera.$B$BHay una pequeña espita en la que encaja la botella y puedes recoger una muestra para la suma sacerdotisa MacDonnell en el Alto del Orvallo.', 0);
-- 5220 Regresa al Campamento del Orvallo
-- https://es.classic.wowhead.com/quest=5220
SET @ID := 5220;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabemos que cada una de las calderas utiliza una mezcla distinta de componentes para generar su toxina inductora de la Peste. De igual modo sabemos que tendremos que desarrollar un contraagente único para cada caldera. Tu muestra del Llanto del Dalson será la clave para comprender los componentes distintivos para esa caldera.', 0),
(@ID, 'esMX', 'Sabemos que cada una de las calderas utiliza una mezcla distinta de componentes para generar su toxina inductora de la Peste. De igual modo sabemos que tendremos que desarrollar un contraagente único para cada caldera. Tu muestra del Llanto del Dalson será la clave para comprender los componentes distintivos para esa caldera.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, aquí hay mucho que estudiar. ¡Bien hecho, $n!$B$BPor ahora, el siguiente paso está en nuestras manos. Tendremos que producir una lista de componentes que combinados con lo que ya está en la caldera actúen como su contrario.$B$BEl único modo en el que podremos conseguirlo es poniendo los componentes directamente en la caldera. El alquimista Arbington tendrá más información, así que no olvides hablar con él en cuanto te sea posible.', 0),
(@ID, 'esMX', 'Ah, aquí hay mucho que estudiar. ¡Bien hecho, $n!$B$BPor ahora, el siguiente paso está en nuestras manos. Tendremos que producir una lista de componentes que combinados con lo que ya está en la caldera actúen como su contrario.$B$BEl único modo en el que podremos conseguirlo es poniendo los componentes directamente en la caldera. El alquimista Arbington tendrá más información, así que no olvides hablar con él en cuanto te sea posible.', 0);
-- 5221 La caldera del Llanto de Dalson
-- https://es.classic.wowhead.com/quest=5221
SET @ID := 5221;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El caldero de la Plaga está ante ti, arrojando grandes cantidades de toxinas al aire. Un pequeño panel de acceso indescriptible se encuentra en la base de la vasta plataforma del caldero.$B$BDespués de haber derrotado al señor del caldero y tomado su llave, puedes agregar los reactivos apropiados al caldero para hacer un agente contra la plaga.', 0),
(@ID, 'esMX', 'El caldero de la Plaga está ante ti, arrojando grandes cantidades de toxinas al aire. Un pequeño panel de acceso indescriptible se encuentra en la base de la vasta plataforma del caldero.$B$BDespués de haber derrotado al señor del caldero y tomado su llave, puedes agregar los reactivos apropiados al caldero para hacer un agente contra la plaga.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al agregar los reactivos a la mezcla del caldero, este comienza a cambiar el color y la textura de la nube que arroja. Los miembros de la Plaga que están cerca del caldero parecen retroceder ante la introducción de los nuevos componentes en el medio ambiente.', 0),
(@ID, 'esMX', 'Al agregar los reactivos a la mezcla del caldero, este comienza a cambiar el color y la textura de la nube que arroja. Los miembros de la Plaga que están cerca del caldero parecen retroceder ante la introducción de los nuevos componentes en el medio ambiente.', 0);
-- 5222 Objetivo: El Tormento
-- https://es.classic.wowhead.com/quest=5222
SET @ID := 5222;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un panel de acceso al caldero permanece bien sujeto. Para abrirlo, deberás encontrar la llave.', 0),
(@ID, 'esMX', 'Un panel de acceso al caldero permanece bien sujeto. Para abrirlo, deberás encontrar la llave.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La llave del señor de la caldera abre el panel de acceso a esta caldera y luego desaparece, al igual que las otras llaves de los dos calderos anteriores. Una sustancia de olor pútrido se agita violentamente debajo de la plataforma del caldero.$B$BHay un pequeño grifo debajo del cual encaja la botella lo suficientemente bien, lo que te permite extraer una muestra para la Suma Sacerdotisa MacDonnell en el Campamento del Orvallo.', 0),
(@ID, 'esMX', 'La llave del señor de la caldera abre el panel de acceso a esta caldera y luego desaparece, al igual que las otras llaves de los dos calderos anteriores. Una sustancia de olor pútrido se agita violentamente debajo de la plataforma del caldero.$B$BHay un pequeño grifo debajo del cual encaja la botella lo suficientemente bien, lo que te permite extraer una muestra para la Suma Sacerdotisa MacDonnell en el Campamento del Orvallo.', 0);
