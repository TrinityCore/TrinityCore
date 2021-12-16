-- 7784 Señor de Roca Negra
-- https://es.classic.wowhead.com/quest=7784
SET @ID := 7784;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Elige tu recompensa para que yo pueda montar la cabeza de la bestia para que todos la vean.', 0),
(@ID, 'esMX', 'Elige tu recompensa para que yo pueda montar la cabeza de la bestia para que todos la vean.', 0);
-- 7785 Examina la vasija
-- https://es.classic.wowhead.com/quest=7785
SET @ID := 7785;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo liberarás de su prisión eterna?', 0),
(@ID, 'esMX', '¿Lo liberarás de su prisión eterna?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que estés $gprotegido:protegida; en tu cruzada. Que el Maestro bendiga tus esfuerzos.', 0),
(@ID, 'esMX', 'Que estés $gprotegido:protegida; en tu cruzada. Que el Maestro bendiga tus esfuerzos.', 0);
-- 7786 Thunderaan el Hijo del Viento
-- https://es.wowhead.com/quest=7786
SET @ID := 7786;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Pon al mundo de rodillas, si falta hiciere!', 0),
(@ID, 'esMX', '¡Pon al mundo de rodillas, si falta hiciere!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nunca imaginé que vería este momento.$B$BAdmírate, mortal.$B$B¡ADMIRA A AQUEL QUE ES MÁS ANTIGUO QUE LA VIDA MISMA!$B$B¡ADMIRA A AQUEL QUE SE HA ENFRENTADO A DIOSES Y TITANES!$B$B¡LIBÉRATE, MAESTRO! ¡ROMPE TUS CADENAS!', 0),
(@ID, 'esMX', 'Nunca imaginé que vería este momento.$B$BAdmírate, mortal.$B$B¡ADMIRA A AQUEL QUE ES MÁS ANTIGUO QUE LA VIDA MISMA!$B$B¡ADMIRA A AQUEL QUE SE HA ENFRENTADO A DIOSES Y TITANES!$B$B¡LIBÉRATE, MAESTRO! ¡ROMPE TUS CADENAS!', 0);
-- 7787 ¡Arriba, Trueno Furioso!
-- https://es.wowhead.com/quest=7787
SET @ID := 7787;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Demitrian se encoge en tu presencia.>', 0),
(@ID, 'esMX', '<Demitrian se encoge en tu presencia.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por favor, no me hagas daño! ¡Llévatelo! ¡Llévate el acero! ¡Permite que Demitrian rehaga su miserable vida!', 0),
(@ID, 'esMX', '¡Por favor, no me hagas daño! ¡Llévatelo! ¡Llévate el acero! ¡Permite que Demitrian rehaga su miserable vida!', 0);
-- Acaba con los usurpadores Ala de Plata
-- 7789, 7874, 7875, 7876, 8294
-- https://es.classic.wowhead.com/quest=7789
DELETE FROM `quest_request_items_locale` WHERE `id` IN(7789, 7874, 7875, 7876, 8294) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(7789, 'esES', 'La sangre de nuestros enemigos es una marca de honor. ¿Tienes esa marca?', 0),
(7874, 'esES', 'La sangre de nuestros enemigos es una marca de honor. ¿Tienes esa marca?', 0),
(7875, 'esES', 'La sangre de nuestros enemigos es una marca de honor. ¿Tienes esa marca?', 0),
(7876, 'esES', 'La sangre de nuestros enemigos es una marca de honor. ¿Tienes esa marca?', 0),
(8294, 'esES', 'La sangre de nuestros enemigos es una marca de honor. ¿Tienes esa marca?', 0),
(7789, 'esMX', 'La sangre de nuestros enemigos es una marca de honor. ¿Tienes esa marca?', 0),
(7874, 'esMX', 'La sangre de nuestros enemigos es una marca de honor. ¿Tienes esa marca?', 0),
(7875, 'esMX', 'La sangre de nuestros enemigos es una marca de honor. ¿Tienes esa marca?', 0),
(7876, 'esMX', 'La sangre de nuestros enemigos es una marca de honor. ¿Tienes esa marca?', 0),
(8294, 'esMX', 'La sangre de nuestros enemigos es una marca de honor. ¿Tienes esa marca?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(7789, 7874, 7875, 7876, 8294) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(7789, 'esES', '<El capitán Shatterskull ruge triunfante.>$B$B¿Cuánto más pueden soportar? ¿Cuántas inmundicias más de la Alianza deben perecer a manos de la Horda para que se retiren? Solo el tiempo lo dirá, $r...', 0),
(7874, 'esES', '<El capitán Shatterskull ruge triunfante.>$B$B¿Cuánto más pueden soportar? ¿Cuántas inmundicias más de la Alianza deben perecer a manos de la Horda para que se retiren? Solo el tiempo lo dirá, $r...', 0),
(7875, 'esES', '<El capitán Shatterskull ruge triunfante.>$B$B¿Cuánto más pueden soportar? ¿Cuántas inmundicias más de la Alianza deben perecer a manos de la Horda para que se retiren? Solo el tiempo lo dirá, $r...', 0),
(7876, 'esES', '<El capitán Shatterskull ruge triunfante.>$B$B¿Cuánto más pueden soportar? ¿Cuántas inmundicias más de la Alianza deben perecer a manos de la Horda para que se retiren? Solo el tiempo lo dirá, $r...', 0),
(8294, 'esES', '<El capitán Shatterskull ruge triunfante.>$B$B¿Cuánto más pueden soportar? ¿Cuántas inmundicias más de la Alianza deben perecer a manos de la Horda para que se retiren? Solo el tiempo lo dirá, $r...', 0),
(7789, 'esMX', '<El capitán Shatterskull ruge triunfante.>$B$B¿Cuánto más pueden soportar? ¿Cuántas inmundicias más de la Alianza deben perecer a manos de la Horda para que se retiren? Solo el tiempo lo dirá, $r...', 0),
(7874, 'esMX', '<El capitán Shatterskull ruge triunfante.>$B$B¿Cuánto más pueden soportar? ¿Cuántas inmundicias más de la Alianza deben perecer a manos de la Horda para que se retiren? Solo el tiempo lo dirá, $r...', 0),
(7875, 'esMX', '<El capitán Shatterskull ruge triunfante.>$B$B¿Cuánto más pueden soportar? ¿Cuántas inmundicias más de la Alianza deben perecer a manos de la Horda para que se retiren? Solo el tiempo lo dirá, $r...', 0),
(7876, 'esMX', '<El capitán Shatterskull ruge triunfante.>$B$B¿Cuánto más pueden soportar? ¿Cuántas inmundicias más de la Alianza deben perecer a manos de la Horda para que se retiren? Solo el tiempo lo dirá, $r...', 0),
(8294, 'esMX', '<El capitán Shatterskull ruge triunfante.>$B$B¿Cuánto más pueden soportar? ¿Cuántas inmundicias más de la Alianza deben perecer a manos de la Horda para que se retiren? Solo el tiempo lo dirá, $r...', 0);
-- 7790 La palabra escrita
-- https://es.wowhead.com/quest=7790
SET @ID := 7790;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Palabras escritas', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 7810 El maestro de la arena
-- https://es.wowhead.com/quest=7810
SET @ID := 7810;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Arrr! ¡Ganar un abalorio no será suficiente para convertirte en maestro de la Arena! Ahora, ha llegado el momento de probar tu acero.', 0),
(@ID, 'esMX', '¡Arrr! ¡Ganar un abalorio no será suficiente para convertirte en maestro de la Arena! Ahora, ha llegado el momento de probar tu acero.', 0);
-- 7815 ¡Quijafortes, colega!
-- https://es.classic.wowhead.com/quest=7815
SET @ID := 7815;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la cacería?', 0),
(@ID, 'esMX', '¿Cómo va la cacería?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No sabes cuánto te lo agradezco. Espero que esta caña de pescar sea justa recompensa.', 0),
(@ID, 'esMX', 'No sabes cuánto te lo agradezco. Espero que esta caña de pescar sea justa recompensa.', 0);
-- 7816 ¡Gammerita, colega!
-- https://es.classic.wowhead.com/quest=7816
SET @ID := 7816;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has acabado con Gammerita?', 0),
(@ID, 'esMX', '¿Ya has acabado con Gammerita?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial! Con el cebo y muchos quijafortes muertos, tendré muchos muchos peces.', 0),
(@ID, 'esMX', '¡Genial! Con el cebo y muchos quijafortes muertos, tendré muchos muchos peces.', 0);
-- 7828 Acechar a los acechadores
-- https://es.classic.wowhead.com/quest=7828
SET @ID := 7828;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muéstrales el poder de los Sañadiente!', 0),
(@ID, 'esMX', '¡Muéstrales el poder de los Sañadiente!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $r. Tienes la gratitud de los Sañadiente.', 0),
(@ID, 'esMX', 'Buen trabajo, $r. Tienes la gratitud de los Sañadiente.', 0);
-- 7829 Cazar a los salvajes
-- https://es.classic.wowhead.com/quest=7829
SET @ID := 7829;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Limpia tu cabeza de pensamientos impuros, $r. ¡Conviértete en uno con la naturaleza!', 0),
(@ID, 'esMX', 'Limpia tu cabeza de pensamientos impuros, $r. ¡Conviértete en uno con la naturaleza!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has demostrado tu valor ante los Sañadiente, $n. Bien hecho.', 0),
(@ID, 'esMX', 'Has demostrado tu valor ante los Sañadiente, $n. Bien hecho.', 0);
-- 7830 Vengar a los Caídos
-- https://es.classic.wowhead.com/quest=7830
SET @ID := 7830;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Señor del Cielo Picovaja pertenece a una raza poco común de grifos cuya función es criar asesinos alados.', 0),
(@ID, 'esMX', 'El Señor del Cielo Picovaja pertenece a una raza poco común de grifos cuya función es criar asesinos alados.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Markhor observa la péndola.>$B$BMe pregunto a cuántos cazadores habrá devorado esta bestia.', 0),
(@ID, 'esMX', '<Markhor observa la péndola.>$B$BMe pregunto a cuántos cazadores habrá devorado esta bestia.', 0);
-- 7838 El maestro mayor de la arena
-- https://es.classic.wowhead.com/quest=7838
SET @ID := 7838;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Alto, pelele! ¡Tráeme 12 abalorios del maestro de la arena y serás un maestro mayor de la Arena Gurubashi! ¡ARRRR!', 0),
(@ID, 'esMX', '¡Alto, pelele! ¡Tráeme 12 abalorios del maestro de la arena y serás un maestro mayor de la Arena Gurubashi! ¡ARRRR!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has derramado mucha sangre en la Arena, y tengo el honor de nombrarte gran maestro de arena!', 0),
(@ID, 'esMX', '¡Has derramado mucha sangre en la Arena, y tengo el honor de nombrarte gran maestro de arena!', 0);
-- 7839 Los vándalos de Vilrama
-- https://es.classic.wowhead.com/quest=7839
SET @ID := 7839;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuidado con los Vilrama, $n, son unos asesinos despiadados.', 0),
(@ID, 'esMX', 'Cuidado con los Vilrama, $n, son unos asesinos despiadados.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Mis herramientas! ¡Excelente! ¡Gracias, muchas gracias, $n!', 0),
(@ID, 'esMX', '¡Mis herramientas! ¡Excelente! ¡Gracias, muchas gracias, $n!', 0);
-- 7840 Lard perdió su almuerzo
-- https://es.classic.wowhead.com/quest=7840
SET @ID := 7840;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Lard se frota la panza.>$B$BLard mucha hambre.', 0),
(@ID, 'esMX', '<Lard se frota la panza.>$B$BLard mucha hambre.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Lard coge la carne y empieza a devorarla.>$B$BQué rico. Gracias.$B$BLard te hace un regalo por tu ayuda.', 0),
(@ID, 'esMX', '<Lard coge la carne y empieza a devorarla.>$B$BQué rico. Gracias.$B$BLard te hace un regalo por tu ayuda.', 0);
-- 7841 Un mensaje para los Martillo Salvaje
-- https://es.classic.wowhead.com/quest=7841
SET @ID := 7841;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estás demasiado $glimpio, amigo:limpia, amiga;. Tienes que mezclarte y ensuciarte con el enemigo.', 0),
(@ID, 'esMX', 'Estás demasiado $glimpio, amigo:limpia, amiga;. Tienes que mezclarte y ensuciarte con el enemigo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que los Sañadiente están sellando nuevas alianzas. Buen trabajo.', 0),
(@ID, 'esMX', 'Parece que los Sañadiente están sellando nuevas alianzas. Buen trabajo.', 0);
-- 7842 Un nuevo mensaje para los Martillo Salvaje
-- https://es.classic.wowhead.com/quest=7842
SET @ID := 7842;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El último mensaje los asustará. O eso, o los pondrá furiosos.', 0),
(@ID, 'esMX', 'El último mensaje los asustará. O eso, o los pondrá furiosos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Solo una cosa más y los Martillo Salvaje aprenderán que con los trols no se juega!', 0),
(@ID, 'esMX', '¡Solo una cosa más y los Martillo Salvaje aprenderán que con los trols no se juega!', 0);
-- 7843 Un mensaje final para los Martillo Salvaje
-- https://es.classic.wowhead.com/quest=7843
SET @ID := 7843;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué pasa, colega?', 0),
(@ID, 'esMX', '¿Qué pasa, colega?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me habría gustado verles las caras. ¿Ya están haciendo las maletas?$B$BMuy buen trabajo, $n. Te has ganado un mojo grande.', 0),
(@ID, 'esMX', 'Me habría gustado verles las caras. ¿Ya están haciendo las maletas?$B$BMuy buen trabajo, $n. Te has ganado un mojo grande.', 0);
-- 7844 Unos primos caníbales
-- https://es.classic.wowhead.com/quest=7844
SET @ID := 7844;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los Varitas Vilrama y los arrancacabelleras habitan la región noreste de las Tierras del Interior.', 0),
(@ID, 'esMX', 'Los Varitas Vilrama y los arrancacabelleras habitan la región noreste de las Tierras del Interior.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $c. El propio Zul\'jin no lo habría hecho mejor.', 0),
(@ID, 'esMX', 'Buen trabajo, $c. El propio Zul\'jin no lo habría hecho mejor.', 0);
-- 7845 El secuestro del anciano Colmillopartido
-- https://es.classic.wowhead.com/quest=7845
SET @ID := 7845;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Apresúrate, $n. Seguro que los guardias han detectado tu presencia.', 0),
(@ID, 'esMX', 'Apresúrate, $n. Seguro que los guardias han detectado tu presencia.', 0);
-- 7846 ¡Recupera la llave!
-- https://es.classic.wowhead.com/quest=7846
SET @ID := 7846;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Apresúrate!', 0),
(@ID, 'esMX', '¡Apresúrate!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Al fin libre! Gracias, $n. ¡Sañadiente sabrá de esta proeza!', 0),
(@ID, 'esMX', '¡Al fin libre! Gracias, $n. ¡Sañadiente sabrá de esta proeza!', 0);
-- 7847 Regresa junto a Primigenia Colmillopartido
-- https://es.classic.wowhead.com/quest=7847
SET @ID := 7847;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias en nombre de los Sañadiente, $n! Tienes toda nuestra gratitud.', 0),
(@ID, 'esMX', '¡Gracias en nombre de los Sañadiente, $n! Tienes toda nuestra gratitud.', 0);
-- 7849 Una separación angustiosa
-- https://es.classic.wowhead.com/quest=7849
SET @ID := 7849;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Llevaré los restos a Yayo\'jin y los enterraré como es debido.', 0),
(@ID, 'esMX', 'Llevaré los restos a Yayo\'jin y los enterraré como es debido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cómo echo de menos a mi hermano...$B$BGracias por tu ayuda, $n. Cuenta con mi gratitud eterna.', 0),
(@ID, 'esMX', 'Cómo echo de menos a mi hermano...$B$BGracias por tu ayuda, $n. Cuenta con mi gratitud eterna.', 0);
-- 7850 Vasijas oscuras
-- https://es.classic.wowhead.com/quest=7850
SET @ID := 7850;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ten cuidado con los Vilrama, $n, están obcecados y lucharán a muerte.', 0),
(@ID, 'esMX', 'Ten cuidado con los Vilrama, $n, están obcecados y lucharán a muerte.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Se ha eliminado la energía maléfica que controlaba a los Vilrama, pero solo por el momento. No podemos bajar la guardia; aunque destruyamos a la sacerdotisa vil Hexx, otra ocupará su lugar.', 0),
(@ID, 'esMX', 'Se ha eliminado la energía maléfica que controlaba a los Vilrama, pero solo por el momento. No podemos bajar la guardia; aunque destruyamos a la sacerdotisa vil Hexx, otra ocupará su lugar.', 0);
-- 7861 Se busca: sacerdotisa vil Hexx y sus esbirros
-- https://es.classic.wowhead.com/quest=7861
SET @ID := 7861;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes noticias desde Jintha\'alor?', 0),
(@ID, 'esMX', '¿Traes noticias desde Jintha\'alor?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este será un duro golpe para los Vilrama. Te has ganado una recompensa magnífica, $n.', 0),
(@ID, 'esMX', 'Este será un duro golpe para los Vilrama. Te has ganado una recompensa magnífica, $n.', 0);
-- 7862 Oferta de empleo: capitán de la guardia de Poblado Sañadiente
-- https://es.classic.wowhead.com/quest=7862
SET @ID := 7862;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estás aquí por la oferta de empleo?', 0),
(@ID, 'esMX', '¿Estás aquí por la oferta de empleo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Desde luego, tienes muchos méritos para el puesto, $n. Acepta esto como pago por tus servicios; revisaré las candidaturas el año próximo.', 0),
(@ID, 'esMX', 'Desde luego, tienes muchos méritos para el puesto, $n. Acepta esto como pago por tus servicios; revisaré las candidaturas el año próximo.', 0);
-- Botiquín básico de centinela
-- 7863, 7864, 7865, 7866, 7867, 7868
-- https://es.classic.wowhead.com/quest=7863
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(7863, 7864, 7865, 7866, 7867, 7868) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(7863, 'esES', 'Ciertamente has comenzado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de Garganta Grito de Guerra.$B$BA medida que continúes demostrando tu valía dentro de Garganta, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(7864, 'esES', 'Ciertamente has comenzado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de Garganta Grito de Guerra.$B$BA medida que continúes demostrando tu valía dentro de Garganta, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(7865, 'esES', 'Ciertamente has comenzado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de Garganta Grito de Guerra.$B$BA medida que continúes demostrando tu valía dentro de Garganta, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(7866, 'esES', 'Ciertamente has comenzado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de Garganta Grito de Guerra.$B$BA medida que continúes demostrando tu valía dentro de Garganta, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(7867, 'esES', 'Ciertamente has comenzado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de Garganta Grito de Guerra.$B$BA medida que continúes demostrando tu valía dentro de Garganta, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(7868, 'esES', 'Ciertamente has comenzado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de Garganta Grito de Guerra.$B$BA medida que continúes demostrando tu valía dentro de Garganta, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(7863, 'esMX', 'Ciertamente has comenzado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de Garganta Grito de Guerra.$B$BA medida que continúes demostrando tu valía dentro de Garganta, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(7864, 'esMX', 'Ciertamente has comenzado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de Garganta Grito de Guerra.$B$BA medida que continúes demostrando tu valía dentro de Garganta, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(7865, 'esMX', 'Ciertamente has comenzado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de Garganta Grito de Guerra.$B$BA medida que continúes demostrando tu valía dentro de Garganta, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(7866, 'esMX', 'Ciertamente has comenzado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de Garganta Grito de Guerra.$B$BA medida que continúes demostrando tu valía dentro de Garganta, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(7867, 'esMX', 'Ciertamente has comenzado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de Garganta Grito de Guerra.$B$BA medida que continúes demostrando tu valía dentro de Garganta, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(7868, 'esMX', 'Ciertamente has comenzado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de Garganta Grito de Guerra.$B$BA medida que continúes demostrando tu valía dentro de Garganta, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0);
-- 7881 Las botas de los feriantes
-- https://es.classic.wowhead.com/quest=7881
SET @ID := 7881;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En la Feria de la Luna Negra caminamos mucho. Caminamos de un lugar de feria a otro... de hecho, ¡nunca nos verás sentados en el trabajo! ¡Así que no es de extrañar que gastemos muchas botas! Necesitamos botas que sean duraderas y elegantes, y las botas de cuero con relieve se ajustan bastante bien a esa idea.$B$B¡Tú! Eres $gun peletero:una peletera;; hazme botas de cuero relieve y te daré un boleto de la Feria de la Luna Negra por el trabajo.', 0),
(@ID, 'esMX', 'En la Feria de la Luna Negra caminamos mucho. Caminamos de un lugar de feria a otro... de hecho, ¡nunca nos verás sentados en el trabajo! ¡Así que no es de extrañar que gastemos muchas botas! Necesitamos botas que sean duraderas y elegantes, y las botas de cuero con relieve se ajustan bastante bien a esa idea.$B$B¡Tú! Eres $gun peletero:una peletera;; hazme botas de cuero relieve y te daré un boleto de la Feria de la Luna Negra por el trabajo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Estas están bastante bien hechas. ¡La artesanía es de primera! Aquí tienes un boleto para la Feria de la Luna Negra... disfrútelo, $gseñor:señora;.', 0),
(@ID, 'esMX', 'Gracias, $n. Estas están bastante bien hechas. ¡La artesanía es de primera! Aquí tienes un boleto para la Feria de la Luna Negra... disfrútelo, $gseñor:señora;.', 0);
-- 7882 Los chalecos de los feriantes
-- https://es.classic.wowhead.com/quest=7882
SET @ID := 7882;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Nuestros trabajadores de la Feria hacen más que barrer la basura y martillear picos! También ayudan a proteger el carnaval mientras viaja, y para ese fin siempre necesitan buenos chalecos de armadura resistentes.$B$BSi haces unas armaduras de cuero resistente y me la traes, me aseguraré de que llegue a las personas adecuadas. También te conseguiré algunos boletos para la Feria de la Luna Negra como intercambio.', 0),
(@ID, 'esMX', '¡Nuestros trabajadores de la Feria hacen más que barrer la basura y martillear picos! También ayudan a proteger el carnaval mientras viaja, y para ese fin siempre necesitan buenos chalecos de armadura resistentes.$B$BSi haces unas armaduras de cuero resistente y me la traes, me aseguraré de que llegue a las personas adecuadas. También te conseguiré algunos boletos para la Feria de la Luna Negra como intercambio.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, trajiste los chalecos. Espléndido. ¿Qué piel de animal usaste para hacer estos, puedo preguntar? El trabajo de costura está muy bien hecho y la textura del cuero tiene un estilo rugoso. ¡Puedo decir que eres $gun artesano experto:una artesana experta;!$B$BGracias, $n, aquí están tus boletos.', 0),
(@ID, 'esMX', 'Ah, trajiste los chalecos. Espléndido. ¿Qué piel de animal usaste para hacer estos, puedo preguntar? El trabajo de costura está muy bien hecho y la textura del cuero tiene un estilo rugoso. ¡Puedo decir que eres $gun artesano experto:una artesana experta;!$B$BGracias, $n, aquí están tus boletos.', 0);
-- 7883 ¡El gnomo más grande del mundo!
-- https://es.classic.wowhead.com/quest=7883
SET @ID := 7883;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Yebb Nebblegear está buscando agregar más talento a su programa, y está buscando por todas partes al gnomo más grande del mundo. ¿Conoces algún gnomo de tamaño considerable?$B$BMucho antes de encontrar al gnomo, quiere tener listo su disfraz. Creo que un arnés bárbaro sería una buena base para el disfraz; ¿Puedes hacer algunos arneses y traérmelos? Haz eso, y tendré un montón de boletos de la Feria de la Luna Negra para ti...', 0),
(@ID, 'esMX', 'Yebb Nebblegear está buscando agregar más talento a su programa, y está buscando por todas partes al gnomo más grande del mundo. ¿Conoces algún gnomo de tamaño considerable?$B$BMucho antes de encontrar al gnomo, quiere tener listo su disfraz. Creo que un arnés bárbaro sería una buena base para el disfraz; ¿Puedes hacer algunos arneses y traérmelos? Haz eso, y tendré un montón de boletos de la Feria de la Luna Negra para ti...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, cielos, estos son bastante grandes! No puedo imaginar encontrar un gnomo que se ajuste perfectamente a ellos, pero no te preocupes, si el gnomo que encontramos no es lo suficientemente grande, puedo hacer ajustes en el disfraz.$B$BMuchas gracias, $n. Aquí están los boletos que te prometí.', 0),
(@ID, 'esMX', '¡Oh, cielos, estos son bastante grandes! No puedo imaginar encontrar un gnomo que se ajuste perfectamente a ellos, pero no te preocupes, si el gnomo que encontramos no es lo suficientemente grande, puedo hacer ajustes en el disfraz.$B$BMuchas gracias, $n. Aquí están los boletos que te prometí.', 0);
-- 7884 El chico crocolisco y el múrloc barbudo
-- https://es.classic.wowhead.com/quest=7884
SET @ID := 7884;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Yebb está trabajando en otras atracciones para su zoo de rarezas, incluidas moradas húmedas y pantanosas para un niño criado por crocoliscos, y quizás para un múrloc. Necesitaremos unas bonitas mallas impermeables para no empaparnos durante los montajes y desmontajes. Para ese trabajo, creo que los leggings de escamas de tortuga servirán.$B$B$n, ¿puedes hacer esos leggings? Si lo haces, una gran pila de boletos para la Feria de la Luna Negra será tu recompensa...', 0),
(@ID, 'esMX', 'Yebb está trabajando en otras atracciones para su zoo de rarezas, incluidas moradas húmedas y pantanosas para un niño criado por crocoliscos, y quizás para un múrloc. Necesitaremos unas bonitas mallas impermeables para no empaparnos durante los montajes y desmontajes. Para ese trabajo, creo que los leggings de escamas de tortuga servirán.$B$B$n, ¿puedes hacer esos leggings? Si lo haces, una gran pila de boletos para la Feria de la Luna Negra será tu recompensa...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial, los hiciste! Estos funcionarán muy bien... Solo espero que no sea yo quien limpie la jaula de los crocoliscos cuando llegue el momento. Esas bestias pueden ser bastante bestiales, ¿no crees?$B$BAquí están tus boletos, $n. ¡Disfrútalos y disfruta de tu estancia en la Feria de la Luna Negra!', 0),
(@ID, 'esMX', '¡Genial, los hiciste! Estos funcionarán muy bien... Solo espero que no sea yo quien limpie la jaula de los crocoliscos cuando llegue el momento. Esas bestias pueden ser bastante bestiales, ¿no crees?$B$BAquí están tus boletos, $n. ¡Disfrútalos y disfruta de tu estancia en la Feria de la Luna Negra!', 0);
-- 7885 Refuerzos para armadura
-- https://es.classic.wowhead.com/quest=7885
SET @ID := 7885;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Puede que no te des cuenta de esto, ¡pero organizar un carnaval itinerante es costoso! Todo se desgasta tan rápido que es una maravilla que podamos obtener ganancias.$B$BDebido a todos esos costos ocultos, siempre estamos buscando formas de mantener nuestro equipo lo más barato posible. Nuestras tiendas, por ejemplo, se rompen con regularidad, pero he descubierto que los kits de armaduras de cuero son excelentes parches. ¿Puedes encontrarme y traerme algunos kits de armadura? ¡Eso nos ahorrará un montón! Haz eso, y tengo un puñado de boletos para la Feria de la Luna Negra para ti...', 0),
(@ID, 'esMX', 'Puede que no te des cuenta de esto, ¡pero organizar un carnaval itinerante es costoso! Todo se desgasta tan rápido que es una maravilla que podamos obtener ganancias.$B$BDebido a todos esos costos ocultos, siempre estamos buscando formas de mantener nuestro equipo lo más barato posible. Nuestras tiendas, por ejemplo, se rompen con regularidad, pero he descubierto que los kits de armaduras de cuero son excelentes parches. ¿Puedes encontrarme y traerme algunos kits de armadura? ¡Eso nos ahorrará un montón! Haz eso, y tengo un puñado de boletos para la Feria de la Luna Negra para ti...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial! ¡Esto funcionará muy bien! ¡Acabo de notar una rotura en una tienda de campaña más allá, y uno de estos kits de armadura es justo lo que necesito para arreglarlo!$B$BMuchas gracias, $n. Estos kits de armadura nos ahorrarán una tonelada en costes de reparación. Aquí tienes tus entradas, ¡te las mereces!', 0),
(@ID, 'esMX', '¡Genial! ¡Esto funcionará muy bien! ¡Acabo de notar una rotura en una tienda de campaña más allá, y uno de estos kits de armadura es justo lo que necesito para arreglarlo!$B$BMuchas gracias, $n. Estos kits de armadura nos ahorrarán una tonelada en costes de reparación. Aquí tienes tus entradas, ¡te las mereces!', 0);
