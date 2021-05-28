-- 10023 Patriarca Quijahierro
-- https://es.wowhead.com/quest=10023
SET @ID := 10023;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El espíritu espera, $n. ¿Tienes la pelambre del patriarca lobo?', 0),
(@ID, 'esMX', 'El espíritu espera, $n. ¿Tienes la pelambre del patriarca lobo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El pelaje es incluso más magnífico de lo que pensaba! Esto es un buen presagio, $n, y los espíritus te favorecerán por tu contribución a esta ceremonia.$B$BHe hecho un casco para ti con los pelajes que sobraban, $n. Te identifica como $gun:una; gran $gcazador:cazadora; y como $galiado:aliada; del gran espíritu lobo del Bosque de Terokkar.', 0),
(@ID, 'esMX', '¡El pelaje es incluso más magnífico de lo que pensaba! Esto es un buen presagio, $n, y los espíritus te favorecerán por tu contribución a esta ceremonia.$B$BHe hecho un casco para ti con los pelajes que sobraban, $n. Te identifica como $gun:una; gran $gcazador:cazadora; y como $galiado:aliada; del gran espíritu lobo del Bosque de Terokkar.', 0);
-- 10024 Visiones de Voren'thal
-- https://es.wowhead.com/quest=10024
SET @ID := 10024;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido los ojos de basilisco para el elixir de Voren\'thal?', 0),
(@ID, 'esMX', '¿Has conseguido los ojos de basilisco para el elixir de Voren\'thal?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Están en perfectas condiciones, $n. Sigue así y pronto tendrás a los Arúspices como amigos.', 0),
(@ID, 'esMX', 'Están en perfectas condiciones, $n. Sigue así y pronto tendrás a los Arúspices como amigos.', 0);
-- 10025 Más ojos de basiliscos
-- https://es.wowhead.com/quest=10025
SET @ID := 10025;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Se necesitan muchos ojos de basiliscos para hacer una pequeña dosis del elixir de Voren\'thal. Si me traes más, conseguirás el favor de los Arúspices.', 0),
(@ID, 'esMX', 'Se necesitan muchos ojos de basiliscos para hacer una pequeña dosis del elixir de Voren\'thal. Si me traes más, conseguirás el favor de los Arúspices.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te lo agradezco, $n. Un día, las visiones de Voren\'thal podrían decidir el destino de nuestra raza. Nos corresponde a nosotros intentar asegurarnos de que sus visiones son tan precisas como se pueda.', 0),
(@ID, 'esMX', 'Te lo agradezco, $n. Un día, las visiones de Voren\'thal podrían decidir el destino de nuestra raza. Nos corresponde a nosotros intentar asegurarnos de que sus visiones son tan precisas como se pueda.', 0);
-- 10026 Alteraciones mágicas
-- https://es.wowhead.com/quest=10026
SET @ID := 10026;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has limpiado a los acechadores de distorsión de las cercanías de la fortaleza?', 0),
(@ID, 'esMX', '¿Has limpiado a los acechadores de distorsión de las cercanías de la fortaleza?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Andarl se frota la frente con la manga de su túnica.>$B$BMenos mal. Estaba empezando a pensar que esos bichos habían echado al resto de las criaturas del bosque.', 0),
(@ID, 'esMX', '<Andarl se frota la frente con la manga de su túnica.>$B$BMenos mal. Estaba empezando a pensar que esos bichos habían echado al resto de las criaturas del bosque.', 0);
-- 10027 Alteraciones mágicas
-- https://es.wowhead.com/quest=10027
SET @ID := 10027;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Keb\'ezil quiere saber si es seguro lanzar una bola de fuego sin volver a avergonzarse.$B$B<El diablillo emite unos chasquidos y el brujo se vuelve hacia él.>$B$B¡No, no fue mi rayo de sombra! ¡Retíralo, pixy demasiado grande!', 0),
(@ID, 'esMX', 'Keb\'ezil quiere saber si es seguro lanzar una bola de fuego sin volver a avergonzarse.$B$B<El diablillo emite unos chasquidos y el brujo se vuelve hacia él.>$B$B¡No, no fue mi rayo de sombra! ¡Retíralo, pixy demasiado grande!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Keb\'ezil está aliviado porque te has encargado del pequeño problema. ¿Verdad, Keb?$B$B<El diablillo ignora a su maestro, supuestamente indignado.>$B$BTendrás que perdonar sus malos modales. Ya sabes cómo pueden ser los demonios...', 0),
(@ID, 'esMX', 'Keb\'ezil está aliviado porque te has encargado del pequeño problema. ¿Verdad, Keb?$B$B<El diablillo ignora a su maestro, supuestamente indignado.>$B$BTendrás que perdonar sus malos modales. Ya sabes cómo pueden ser los demonios...', 0);
-- 10028 Vasijas de poder
-- https://es.wowhead.com/quest=10028
SET @ID := 10028;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido encontrar alguna vasija intacta?', 0),
(@ID, 'esMX', '¿Has conseguido encontrar alguna vasija intacta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que no sean las únicas vasijas intactas de la ciudad. Está bien para empezar, pero sospecho que necesitaremos muchas más.', 0),
(@ID, 'esMX', 'Espero que no sean las únicas vasijas intactas de la ciudad. Está bien para empezar, pero sospecho que necesitaremos muchas más.', 0);
-- 10030 Recuperar los huesos
-- https://es.wowhead.com/quest=10030
SET @ID := 10030;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto? ¿Quién eres?', 0),
(@ID, 'esMX', '¿Qué es esto? ¿Quién eres?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Genial, justo lo que necesitaba..., más huesos.$B$B<Ramdor suspira.>$B$BSí, sí, me encargaré de que los huesos de estos honorables ancestros tengan una digna sepultura, no temas.$B$BHay algo más que puedes hacer si de verdad estás interesado en ayudar a los muertos.', 0),
(@ID, 'esMX', 'Genial, justo lo que necesitaba..., más huesos.$B$B<Ramdor suspira.>$B$BSí, sí, me encargaré de que los huesos de estos honorables ancestros tengan una digna sepultura, no temas.$B$BHay algo más que puedes hacer si de verdad estás interesado en ayudar a los muertos.', 0);
-- 10031 Ayudar a Los Perdidos a encontrar su camino
-- https://es.wowhead.com/quest=10031
SET @ID := 10031;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n? ¿Qué te trae de vuelta a mí? ¿Le entregaste los huesos de los inquietos a Ramdor como te pedí?', 0),
(@ID, 'esMX', '$n? ¿Qué te trae de vuelta a mí? ¿Le entregaste los huesos de los inquietos a Ramdor como te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho lo que había que hacer; no hay nada que perdonar. Si bien me apena escuchar que algunos de mis ancestros fueron corrompidos y terminaron convirtiéndose en horribles no-muertos, gracias a tus actos, ahora descansan en paz.$B$BGracias por liberarlos, $n. Acepta este regalo como recompensa por tu generosidad.', 0),
(@ID, 'esMX', 'Has hecho lo que había que hacer; no hay nada que perdonar. Si bien me apena escuchar que algunos de mis ancestros fueron corrompidos y terminaron convirtiéndose en horribles no-muertos, gracias a tus actos, ahora descansan en paz.$B$BGracias por liberarlos, $n. Acepta este regalo como recompensa por tu generosidad.', 0);
-- 10033 Se busca: Atizahuesos ¡Muertos!
-- https://es.wowhead.com/quest=10033
SET @ID := 10033;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Supongo que también buscas la recompensa de los Atizahuesos?', 0),
(@ID, 'esMX', '¿Supongo que también buscas la recompensa de los Atizahuesos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, seguro que has matado a todos esos Atizahuesos. Es obvio, ya que el capitán te pidió pruebas sobre ese cartel de Se busca.$B$B<Taela te mira con sarcasmo.>$B$BAcepto tu palabra. No tengo muy claro a quién hice enfadar para tener que encargarme de esto, pero te doy las gracias en nombre de la Alianza. Aquí tienes algo por tus molestias.', 0),
(@ID, 'esMX', 'Sí, seguro que has matado a todos esos Atizahuesos. Es obvio, ya que el capitán te pidió pruebas sobre ese cartel de Se busca.$B$B<Taela te mira con sarcasmo.>$B$BAcepto tu palabra. No tengo muy claro a quién hice enfadar para tener que encargarme de esto, pero te doy las gracias en nombre de la Alianza. Aquí tienes algo por tus molestias.', 0);
-- 10034 Se busca: Atizahuesos ¡Muertos!
-- https://es.wowhead.com/quest=10034
SET @ID := 10034;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Es sangre de Atizahuesos lo huelo en tus manos?', 0),
(@ID, 'esMX', '¿Es sangre de Atizahuesos lo huelo en tus manos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tienes que haber matado muchos de esos Atizahuesos! Bien, ¡los odio! Desde que uno de ellos me mordió, no hago más que sufrir hechizos de desfallecimiento.$B$B¿Te das cuenta de la vergüenza que tengo que pasar? Toma, acepta esto como agradecimiento por vengarte por mí.', 0),
(@ID, 'esMX', '¡Tienes que haber matado muchos de esos Atizahuesos! Bien, ¡los odio! Desde que uno de ellos me mordió, no hago más que sufrir hechizos de desfallecimiento.$B$B¿Te das cuenta de la vergüenza que tengo que pasar? Toma, acepta esto como agradecimiento por vengarte por mí.', 0);
-- 10035 ¡Torgos!
-- https://es.wowhead.com/quest=10035
SET @ID := 10035;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la pluma? ¿He de recompensarte por tu temerario valor?', 0),
(@ID, 'esMX', '¿Tienes la pluma? ¿He de recompensarte por tu temerario valor?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Impresionante, $c. Torgos era una de las criaturas más fuertes a este lado de Nagrand.$B$BEsto se merece algo de la tesorería del Bastión Allerian. Coge lo que quieras.', 0),
(@ID, 'esMX', 'Impresionante, $c. Torgos era una de las criaturas más fuertes a este lado de Nagrand.$B$BEsto se merece algo de la tesorería del Bastión Allerian. Coge lo que quieras.', 0);
-- 10036 ¡Torgos!
-- https://es.wowhead.com/quest=10036
SET @ID := 10036;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo has hecho? ¿Torgos está muerto?$B$B¿Tienes una prueba?', 0),
(@ID, 'esMX', '¿Lo has hecho? ¿Torgos está muerto?$B$B¿Tienes una prueba?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias, $n! Te has vengado por mí y, como te prometí, recibirás una recompensa.$B$BElige algo y dale un buen uso.', 0),
(@ID, 'esMX', '¡Gracias, $n! Te has vengado por mí y, como te prometí, recibirás una recompensa.$B$BElige algo y dale un buen uso.', 0);
-- 10037 Mejor pescando
-- https://es.wowhead.com/quest=10037
SET @ID := 10037;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Seth te tira de la capa.>$B$B¿Has encontrado anguilas? ¿Las has encontrado?', 0),
(@ID, 'esMX', '<Seth te tira de la capa.>$B$B¿Has encontrado anguilas? ¿Las has encontrado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias! Ya ni me acuerdo de la última vez que comí anguilas.$B$B¿Cómo las cocino?', 0),
(@ID, 'esMX', '¡Gracias! Ya ni me acuerdo de la última vez que comí anguilas.$B$B¿Cómo las cocino?', 0);
-- 10038 Habla con el soldado Semanas
-- https://es.wowhead.com/quest=10038
SET @ID := 10038;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya era hora de que alguien viniera. Envié ese informe al Bastión Allerian hace ya una semana.$B$B¡Burocracia!', 0),
(@ID, 'esMX', 'Ya era hora de que alguien viniera. Envié ese informe al Bastión Allerian hace ya una semana.$B$B¡Burocracia!', 0);
-- 10039 Habla con la exploradora Neftis
-- https://es.wowhead.com/quest=10039
SET @ID := 10039;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya era hora de que alguien viniera. Envié ese informe al Bastión Rompepedras hace ya una semana.$B$B¡Esos elfos de sangre y su burocracia!', 0),
(@ID, 'esMX', 'Ya era hora de que alguien viniera. Envié ese informe al Bastión Rompepedras hace ya una semana.$B$B¡Esos elfos de sangre y su burocracia!', 0);
-- ¿Quiénes son?
-- 10040, 10041
-- https://es.wowhead.com/quest=10040
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Iniciado oscuro sonsacado', `ObjectiveText2` = 'Obrero oscuro sonsacado', `ObjectiveText3` = 'Consejero oscuro sonsacado', `VerifiedBuild` = 0 WHERE `id` IN(10040, 10041) AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` IN(10040, 10041) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(10040, 'esES', '¿Hablaste con todos ellos? ¿Que tenían que decir?', 0),
(10041, 'esES', '¿Hablaste con todos ellos? ¿Que tenían que decir?', 0),
(10040, 'esMX', '¿Hablaste con todos ellos? ¿Que tenían que decir?', 0),
(10041, 'esMX', '¿Hablaste con todos ellos? ¿Que tenían que decir?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10040, 10041) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10040, 'esES', '¡Bien, por fin has vuelto! Bueno, ¿y qué has descubierto? ¿Quiénes son?', 0),
(10041, 'esES', '¡Bien, por fin has vuelto! Bueno, ¿y qué has descubierto? ¿Quiénes son?', 0),
(10040, 'esMX', '¡Bien, por fin has vuelto! Bueno, ¿y qué has descubierto? ¿Quiénes son?', 0),
(10041, 'esMX', '¡Bien, por fin has vuelto! Bueno, ¿y qué has descubierto? ¿Quiénes son?', 0);
-- 10042 ¡Acaba con el Consejo de la Sombra!
-- https://es.wowhead.com/quest=10042
SET @ID := 10042;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, ¿qué averiguaste, $gchico:chica;?', 0),
(@ID, 'esMX', 'Bueno, ¿qué averiguaste, $gchico:chica;?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué noticias tan terribles! Bueno, parece que tomé la decisión correcta al enviarte a ayudar a Semanas. Lo último que queremos es que el Consejo de la Sombra se establezca a la vuelta de la esquina.$B$B$n, en reconocimiento a tus esfuerzos en el Poblado Grangol\'var, te concedo el derecho a elegir una de estas recompensas.', 0),
(@ID, 'esMX', '¡Qué noticias tan terribles! Bueno, parece que tomé la decisión correcta al enviarte a ayudar a Semanas. Lo último que queremos es que el Consejo de la Sombra se establezca a la vuelta de la esquina.$B$B$n, en reconocimiento a tus esfuerzos en el Poblado Grangol\'var, te concedo el derecho a elegir una de estas recompensas.', 0);
-- 10043 ¡Acaba con el Consejo de la Sombra!
-- https://es.wowhead.com/quest=10043
SET @ID := 10043;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, ¿qué averiguaste?', 0),
(@ID, 'esMX', 'Bueno, ¿qué averiguaste?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué noticias tan terribles! Bueno, parece que tomé la decisión correcta al enviarte a ayudar a Neftis. Lo último que queremos es que el Consejo de la Sombra se establezca a la vuelta de la esquina.$B$B$n, te mereces una buena recompensa. Adelante, elige.', 0),
(@ID, 'esMX', '¡Qué noticias tan terribles! Bueno, parece que tomé la decisión correcta al enviarte a ayudar a Neftis. Lo último que queremos es que el Consejo de la Sombra se establezca a la vuelta de la esquina.$B$B$n, te mereces una buena recompensa. Adelante, elige.', 0);
-- 10044 Una visita a la Abuela
-- https://es.wowhead.com/quest=10044
SET @ID := 10044;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por favor $gquerido:querida;, siéntate.', 0),
(@ID, 'esMX', 'Por favor $gquerido:querida;, siéntate.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tenemos que abrir tu mente para que puedas comunicarte con los ancestros.', 0),
(@ID, 'esMX', 'Tenemos que abrir tu mente para que puedas comunicarte con los ancestros.', 0);
-- 10045 Componentes materiales
-- https://es.wowhead.com/quest=10045
SET @ID := 10045;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $gquerido:querida;.', 0),
(@ID, 'esMX', 'Hola, $gquerido:querida;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes muchos recursos $n. Nuestros mejores recolectores habrían tardado el doble en conseguir las hierbas.$B$B<La abuela Geyah mezcla las hierbas en una poción y luego coloca la tintura en tus labios, obligándote a beber.>$B$BNo tengas miedo.', 0),
(@ID, 'esMX', 'Tienes muchos recursos $n. Nuestros mejores recolectores habrían tardado el doble en conseguir las hierbas.$B$B<La abuela Geyah mezcla las hierbas en una poción y luego coloca la tintura en tus labios, obligándote a beber.>$B$BNo tengas miedo.', 0);
-- 10047 El Camino a la Gloria
-- https://es.wowhead.com/quest=10047
SET @ID := 10047;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Purificar esqueleto pisoteado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los lamentos parecen menos... perceptibles de lo que eran antes. La Luz nos dice que hemos hecho bien.', 0),
(@ID, 'esMX', 'Los lamentos parecen menos... perceptibles de lo que eran antes. La Luz nos dice que hemos hecho bien.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes mi más sincero agradecimiento, $n. Si bien aún queda mucho por hacer, me alegra saber que hemos ayudado a algunos a encontrar su merecido descanso.', 0),
(@ID, 'esMX', 'Tienes mi más sincero agradecimiento, $n. Si bien aún queda mucho por hacer, me alegra saber que hemos ayudado a algunos a encontrar su merecido descanso.', 0);
-- 10050 Almas Implacables
-- https://es.wowhead.com/quest=10050
SET @ID := 10050;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo que te pedí es algo terrible que pedirle a cualquiera. Pero lo que debes entender es que muchos de los hombres no se acercarán a las ruinas. Los recuerdos y el dolor son demasiado recientes, pero no podemos permitir que los espíritus sigan vagando.$B$BCuanto más persisten, más se deshacen de los lazos que les quedan con su vida pasada y se entregan a la malevolencia.', 0),
(@ID, 'esMX', 'Lo que te pedí es algo terrible que pedirle a cualquiera. Pero lo que debes entender es que muchos de los hombres no se acercarán a las ruinas. Los recuerdos y el dolor son demasiado recientes, pero no podemos permitir que los espíritus sigan vagando.$B$BCuanto más persisten, más se deshacen de los lazos que les quedan con su vida pasada y se entregan a la malevolencia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los Hijos aprecian tus esfuerzos, incluso si casi ninguno de ellos quiere hablar sobre la Armería.', 0),
(@ID, 'esMX', 'Los Hijos aprecian tus esfuerzos, incluso si casi ninguno de ellos quiere hablar sobre la Armería.', 0);
-- 10051 ¡Huida del Alto Ala de Fuego!
-- https://es.wowhead.com/quest=10051
SET @ID := 10051;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Isla Peloestrella acaba de irse, pero me contó detalladamente lo que está pasando en el Alto Ala de Fuego. Es comprensible que se sienta consternada por lo que ocurrió en el Matorral Cenarion. ¡Malditos elfos de sangre!$B$BMe contó que jugaste un papel decisivo al salvarla para que pudiéramos conseguir esa información. El Bastión Allerian está en deuda contigo.$B$BPor favor, acepta este regalo de nuestra parte.', 0),
(@ID, 'esMX', 'Isla Peloestrella acaba de irse, pero me contó detalladamente lo que está pasando en el Alto Ala de Fuego. Es comprensible que se sienta consternada por lo que ocurrió en el Matorral Cenarion. ¡Malditos elfos de sangre!$B$BMe contó que jugaste un papel decisivo al salvarla para que pudiéramos conseguir esa información. El Bastión Allerian está en deuda contigo.$B$BPor favor, acepta este regalo de nuestra parte.', 0);
-- 10052 ¡Huida del Alto Ala de Fuego!
-- https://es.wowhead.com/quest=10052
SET @ID := 10052;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Isla Peloestrella acaba de irse, pero me contó detalladamente lo que está pasando en el Alto Ala de Fuego. Es comprensible que se sienta consternada por lo que ocurrió en el Matorral Cenarion.$B$BMe contó que jugaste un papel decisivo al salvarla para que pudiéramos conseguir esa información. El Bastión Rompepedras está en deuda contigo.$B$BPor favor, acepta este regalo de nuestra parte.', 0),
(@ID, 'esMX', 'Isla Peloestrella acaba de irse, pero me contó detalladamente lo que está pasando en el Alto Ala de Fuego. Es comprensible que se sienta consternada por lo que ocurrió en el Matorral Cenarion.$B$BMe contó que jugaste un papel decisivo al salvarla para que pudiéramos conseguir esa información. El Bastión Rompepedras está en deuda contigo.$B$BPor favor, acepta este regalo de nuestra parte.', 0);
-- 10055 No desperdicies si puedes evitarlo
-- https://es.wowhead.com/quest=10055
SET @ID := 10055;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido encontrar algún material ahí entre todo el polvo, las cenizas y los escombros?', 0),
(@ID, 'esMX', '¿Has conseguido encontrar algún material ahí entre todo el polvo, las cenizas y los escombros?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Está en mejor estado de lo que yo pensaba. Sí, llevará algo de tiempo quitar todo el óxido, el carbón y esas cosas, pero no me quejaré.', 0),
(@ID, 'esMX', 'Está en mejor estado de lo que yo pensaba. Sí, llevará algo de tiempo quitar todo el óxido, el carbón y esas cosas, pero no me quejaré.', 0);
-- 10057 El liderazgo en el punto de mira
-- https://es.wowhead.com/quest=10057
SET @ID := 10057;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudiste vencer a los oficiales en las ruinas?', 0),
(@ID, 'esMX', '¿Pudiste vencer a los oficiales en las ruinas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Solo podemos esperar que, con el acallamiento de los fantasmas de los oficiales, los espíritus de los soldados de infantería vayan detrás. Gracias de nuevo por tu ayuda, $n.', 0),
(@ID, 'esMX', 'Solo podemos esperar que, con el acallamiento de los fantasmas de los oficiales, los espíritus de los soldados de infantería vayan detrás. Gracias de nuevo por tu ayuda, $n.', 0);
-- 10058 Un viejo regalo
-- https://es.wowhead.com/quest=10058
SET @ID := 10058;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me parecía haberte pedido que no me molestaras. ¿De qué se trata?', 0),
(@ID, 'esMX', 'Me parecía haberte pedido que no me molestaras. ¿De qué se trata?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Eso es todo? Cuesta creer que sobreviviera a la contienda. Las condiciones de las ruinas no le han sentado bien al libro pero a pesar de eso, me alegro de tenerlo.$B$BEs lo único que me queda de Turalyon.$B$B<El padre Devidicus a duras penas contiene las lágrimas.>$B$BCuando luchas codo con codo con alguien durante años, acaban siendo incluso más que la familia.', 0),
(@ID, 'esMX', '¿Eso es todo? Cuesta creer que sobreviviera a la contienda. Las condiciones de las ruinas no le han sentado bien al libro pero a pesar de eso, me alegro de tenerlo.$B$BEs lo único que me queda de Turalyon.$B$B<El padre Devidicus a duras penas contiene las lágrimas.>$B$BCuando luchas codo con codo con alguien durante años, acaban siendo incluso más que la familia.', 0);
-- 10063 Liga de Expedicionarios, ¿cosa de gnomos?
-- https://es.wowhead.com/quest=10063
SET @ID := 10063;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eso pensaba yo! Se supone que ese viejo enano gruñón tenía que ayudarme a llevar mi equipamiento y a reunir datos pero se limita a quedarse sentado en esa extraña ciudad draenei y a emborracharse hasta perder el conocimiento.', 0),
(@ID, 'esMX', '¡Eso pensaba yo! Se supone que ese viejo enano gruñón tenía que ayudarme a llevar mi equipamiento y a reunir datos pero se limita a quedarse sentado en esa extraña ciudad draenei y a emborracharse hasta perder el conocimiento.', 0);
-- 10064 Habla con la Mano
-- https://es.wowhead.com/quest=10064
SET @ID := 10064;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esperaba que la Avanzada de Sangre enviara refuerzos cuando supieran a lo que nos enfrentamos.', 0),
(@ID, 'esMX', 'Esperaba que la Avanzada de Sangre enviara refuerzos cuando supieran a lo que nos enfrentamos.', 0);
-- 10065 Abrirse paso
-- https://es.wowhead.com/quest=10065
SET @ID := 10065;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has logrado limpiar la zona de algunos devastadores?', 0),
(@ID, 'esMX', '¿Has logrado limpiar la zona de algunos devastadores?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La cosa parece estar algo mejor ahí fuera pero aún me pregunto si no haría mejor en esperar a un médico aquí.', 0),
(@ID, 'esMX', 'La cosa parece estar algo mejor ahí fuera pero aún me pregunto si no haría mejor en esperar a un médico aquí.', 0);
-- 10066 ¡Vaya una maraña de telarañas!
-- https://es.wowhead.com/quest=10066
SET @ID := 10066;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has logrado despejar la zona de los enmarañadores mutados?', 0),
(@ID, 'esMX', '¿Has logrado despejar la zona de los enmarañadores mutados?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Será mucho más fácil conseguir refuerzos de la Avanzada de Sangre o lanzar ataques contra los Halcones del Sol sin tener que preocuparme por lo que los enmarañadores estén tramando.', 0),
(@ID, 'esMX', 'Muy bien, $n. Será mucho más fácil conseguir refuerzos de la Avanzada de Sangre o lanzar ataques contra los Halcones del Sol sin tener que preocuparme por lo que los enmarañadores estén tramando.', 0);
-- 10067 Espíritus del agua contaminados
-- https://es.wowhead.com/quest=10067
SET @ID := 10067;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has comenzado a limpiar los espíritus del agua podridos?', 0),
(@ID, 'esMX', '¿Has comenzado a limpiar los espíritus del agua podridos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Hay que aprovechar todas las oportunidades de cortar las provisiones a los Halcones del Sol.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Hay que aprovechar todas las oportunidades de cortar las provisiones a los Halcones del Sol.', 0);
-- 10074 Polvo de cristal de Oshu'gun
-- https://es.wowhead.com/quest=10074
SET @ID := 10074;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El polvo de cristal de la montaña está imbuido en el núcleo terráneo de esta región.', 0),
(@ID, 'esMX', 'El polvo de cristal de la montaña está imbuido en el núcleo terráneo de esta región.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Magnífico, $n. Esto nos ayudará en nuestra lucha contra la escoria de la Alianza que ha aparecido en Terrallende.', 0),
(@ID, 'esMX', 'Magnífico, $n. Esto nos ayudará en nuestra lucha contra la escoria de la Alianza que ha aparecido en Terrallende.', 0);
-- 10075 Polvo de cristal de Oshu'gun
-- https://es.wowhead.com/quest=10075
SET @ID := 10075;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta base fue la principal instalación de investigación draenei para el estudio de los cristales de naaru.$B$BLo que hemos descubierto es una verdadera mina de oro de notas de investigación sobre los cristales de la montaña de "diamantes", Oshu\'gun. Parecería que todo en esta región lleva consigo algún polvo residual de los cristales de Oshu\'gun. Si encuentras polvo de cristal mientras te aventuras en esta región, devuélvemela y te recompensaré con una muestra de mi agradecimiento que puedes usar para hacer compras al intendente.', 0),
(@ID, 'esMX', 'Esta base fue la principal instalación de investigación draenei para el estudio de los cristales de naaru.$B$BLo que hemos descubierto es una verdadera mina de oro de notas de investigación sobre los cristales de la montaña de "diamantes", Oshu\'gun. Parecería que todo en esta región lleva consigo algún polvo residual de los cristales de Oshu\'gun. Si encuentras polvo de cristal mientras te aventuras en esta región, devuélvemela y te recompensaré con una muestra de mi agradecimiento que puedes usar para hacer compras al intendente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'tiempre acepto contribuciones en polvo de cristal, $n. Se le compensará por cada conjunto de muestras que recuperes.', 0),
(@ID, 'esMX', 'tiempre acepto contribuciones en polvo de cristal, $n. Se le compensará por cada conjunto de muestras que recuperes.', 0);
-- 10076 Polvo de cristal de Oshu'gun
-- https://es.wowhead.com/quest=10076
SET @ID := 10076;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El polvo de cristal de la montaña está imbuido en el núcleo terráneo de esta región.', 0),
(@ID, 'esMX', 'El polvo de cristal de la montaña está imbuido en el núcleo terráneo de esta región.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Magnífico, $n. Esto nos ayudará en nuestra lucha contra la escoria de la Horda que ha aparecido en Terrallende.', 0),
(@ID, 'esMX', 'Magnífico, $n. Esto nos ayudará en nuestra lucha contra la escoria de la Horda que ha aparecido en Terrallende.', 0);
