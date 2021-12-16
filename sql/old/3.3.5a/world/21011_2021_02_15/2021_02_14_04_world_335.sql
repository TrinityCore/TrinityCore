-- 5051 Dos mitades hacen una
-- https://es.classic.wowhead.com/quest=5051
SET @ID := 5051;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'John, no dejes que te atrapen los necrófagos... no dejes que me atrapen los necrófagos... horribles necrófagos... nuestro talismán nos mantendrá a salvo.', 0),
(@ID, 'esMX', 'John, no dejes que te atrapen los necrófagos... no dejes que me atrapen los necrófagos... horribles necrófagos... nuestro talismán nos mantendrá a salvo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entregas el talismán de buena suerte vuelto a reunir al fantasma de Janice Piedra Mácula. En cuanto lo tiene en sus manos observas un cambio casi inmediato. Su forma etérea emite brillos trémulos y te mira con unos ojos claros pero tristes.$B$B"Me has liberado... ya no necesito este talismán. Por favor, cógelo, quizás te dé el consuelo que me ha dado a mí."', 0),
(@ID, 'esMX', 'Entregas el talismán de buena suerte vuelto a reunir al fantasma de Janice Piedra Mácula. En cuanto lo tiene en sus manos observas un cambio casi inmediato. Su forma etérea emite brillos trémulos y te mira con unos ojos claros pero tristes.$B$B"Me has liberado... ya no necesito este talismán. Por favor, cógelo, quizás te dé el consuelo que me ha dado a mí."', 0);
-- 5052 Esquirlas de sangre de Agamaggan
-- https://es.classic.wowhead.com/quest=5052
SET @ID := 5052;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestras tribus se reúnen en las espinosas regiones de Los Baldíos <gruñe> porque hay lugares sagrados, aunque ninguno tan sagrado como Rajacieno. El cuerpo de Agamaggan compensa por todo Rajacieno, <gruñe> pero la Zahúrda está especialmente protegida ¡porque la entrada está hecha con sus enormes fauces! <Gruñe> ¡Se tragará enterito a todo aquel que no le sea leal y escupirá su cuerpo después de masticarlo! <Gruñe>$B$BAgamaggan nos dejó su cuerpo para protegernos y entrega su espíritu para que podamos protegerlo a él. <Gruñe>', 0),
(@ID, 'esMX', 'Nuestras tribus se reúnen en las espinosas regiones de Los Baldíos <gruñe> porque hay lugares sagrados, aunque ninguno tan sagrado como Rajacieno. El cuerpo de Agamaggan compensa por todo Rajacieno, <gruñe> pero la Zahúrda está especialmente protegida ¡porque la entrada está hecha con sus enormes fauces! <Gruñe> ¡Se tragará enterito a todo aquel que no le sea leal y escupirá su cuerpo después de masticarlo! <Gruñe>$B$BAgamaggan nos dejó su cuerpo para protegernos y entrega su espíritu para que podamos protegerlo a él. <Gruñe>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, entiendes. <Gruñe> Mis palabras no cayeron en oídos sordos, $r. Puede que Quebrantadientes esté enjaulado ¡pero no hay jaula que detenga el poder de Agamaggan!$B$BEl contacto con el fragmento, solo tocarlo... ha pasado tanto tiempo, $r.$B$B¿Tienes idea de lo que se siente? ¿Que te aparten de tu poder?$B$BPero ya contaremos esa historia en otra ocasión. Te prometí información. Te prometí el poder de Agamaggan. Mi propio pueblo me dio la espalda, a mí, a Quebrantadientes. Ahora, te envío para que mi furia caiga sobre ellos.', 0),
(@ID, 'esMX', 'Ah, entiendes. <Gruñe> Mis palabras no cayeron en oídos sordos, $r. Puede que Quebrantadientes esté enjaulado ¡pero no hay jaula que detenga el poder de Agamaggan!$B$BEl contacto con el fragmento, solo tocarlo... ha pasado tanto tiempo, $r.$B$B¿Tienes idea de lo que se siente? ¿Que te aparten de tu poder?$B$BPero ya contaremos esa historia en otra ocasión. Te prometí información. Te prometí el poder de Agamaggan. Mi propio pueblo me dio la espalda, a mí, a Quebrantadientes. Ahora, te envío para que mi furia caiga sobre ellos.', 0);
-- 5059 Encierro
-- https://es.classic.wowhead.com/quest=5059
SET @ID := 5059;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La puerta de la letrina ha comenzado a astillarse en los bordes del marco, como si hubieran intentado forzarla varias veces y con insistencia. En este momento está cerrada desde fuera.$B$B¡Cuando mueves la puerta oyes un gemido gutural en el interior! Sea lo que sea, no parece muy amistoso.', 0),
(@ID, 'esMX', 'La puerta de la letrina ha comenzado a astillarse en los bordes del marco, como si hubieran intentado forzarla varias veces y con insistencia. En este momento está cerrada desde fuera.$B$B¡Cuando mueves la puerta oyes un gemido gutural en el interior! Sea lo que sea, no parece muy amistoso.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con la llave que encontraste en el esqueleto de la que fue la señora Dalson abres la puerta de la letrina. Un necrófago sanguinario salta fuera de la letrina, debe de haber estado ahí atrapado desde hace mucho tiempo.$B$BEl desgarrador grito del necrófago al advertir tu presencia deja claro que el antiguo granjero Dalson ya no puede ser salvado.', 0),
(@ID, 'esMX', 'Con la llave que encontraste en el esqueleto de la que fue la señora Dalson abres la puerta de la letrina. Un necrófago sanguinario salta fuera de la letrina, debe de haber estado ahí atrapado desde hace mucho tiempo.$B$BEl desgarrador grito del necrófago al advertir tu presencia deja claro que el antiguo granjero Dalson ya no puede ser salvado.', 0);
-- 5060 Encierro
-- https://es.classic.wowhead.com/quest=5060
SET @ID := 5060;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes ante ti un armario extremadamente fuerte y robusto, cerrado con un candado. La parte delantera del armario tiene marcas y arañazos muy profundos. Podría pensarse que son el resultado de numerosos y violentos intentos fallidos por desvelar los secretos que encierra el armario.$B$BSi quieres abrirlo tendrás que encontrar la llave.', 0),
(@ID, 'esMX', 'Tienes ante ti un armario extremadamente fuerte y robusto, cerrado con un candado. La parte delantera del armario tiene marcas y arañazos muy profundos. Podría pensarse que son el resultado de numerosos y violentos intentos fallidos por desvelar los secretos que encierra el armario.$B$BSi quieres abrirlo tendrás que encontrar la llave.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La llave que has cogido de los restos del necrófago que fue el granjero Dalson encaja a la perfección en el candado. Las puertas del armario se abren y muestran varios objetos que siguen intactos y que parecen bastante valiosos.', 0),
(@ID, 'esMX', 'La llave que has cogido de los restos del necrófago que fue el granjero Dalson encaja a la perfección en el candado. Las puertas del armario se abren y muestran varios objetos que siguen intactos y que parecen bastante valiosos.', 0);
-- 5061 Forma acuática
-- https://es.classic.wowhead.com/quest=5061
SET @ID := 5061;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu regreso a Darnassus no está libre de presagios, aunque necesitaré una prueba de tus lecciones aprendidas en Claro de Luna antes de enseñarte tu forma acuática. $B$B¿Traes el colgante del león marino?', 0),
(@ID, 'esMX', 'Tu regreso a Darnassus no está libre de presagios, aunque necesitaré una prueba de tus lecciones aprendidas en Claro de Luna antes de enseñarte tu forma acuática. $B$B¿Traes el colgante del león marino?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy impresionante, $n. Estás $glisto:lista; para aprender tu forma acuática, y es un placer para mí enseñártela.$B$BAdemás, en reconocimiento a tu logro durante las dos pruebas, te entrego este artículo. Espero que lo encuentres util en tu equipamiento como $gprotector:protectora; de la naturaleza y $gguardián:guardiana; del equilibrio.', 0),
(@ID, 'esMX', 'Muy impresionante, $n. Estás $glisto:lista; para aprender tu forma acuática, y es un placer para mí enseñártela.$B$BAdemás, en reconocimiento a tu logro durante las dos pruebas, te entrego este artículo. Espero que lo encuentres util en tu equipamiento como $gprotector:protectora; de la naturaleza y $gguardián:guardiana; del equilibrio.', 0);
-- 5062 El fuego Sagrado
-- https://es.classic.wowhead.com/quest=5062
SET @ID := 5062;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que Motega Pirocabello envía noticias de Arikara... eso es mala señal.$B$B<Magatha mira a su alrededor.>$B$BArikara es una criatura muy peligrosa cuyo único propósito es castigar a todo aquel que haya cometido actos abyectos.$B$B<Magatha sonríe.>', 0),
(@ID, 'esMX', 'Así que Motega Pirocabello envía noticias de Arikara... eso es mala señal.$B$B<Magatha mira a su alrededor.>$B$BArikara es una criatura muy peligrosa cuyo único propósito es castigar a todo aquel que haya cometido actos abyectos.$B$B<Magatha sonríe.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, has recogido la cantidad necesaria de pitas incendiarias. Esta rara hierba que solo se encuentra en Las Mil Agujas servirá para encender el fuego sagrado de la vida.$B$B<Magatha comienza a encantar las pitas incendiarias.>', 0),
(@ID, 'esMX', 'Bien, has recogido la cantidad necesaria de pitas incendiarias. Esta rara hierba que solo se encuentra en Las Mil Agujas servirá para encender el fuego sagrado de la vida.$B$B<Magatha comienza a encantar las pitas incendiarias.>', 0);
-- 5063 Almete del Sabio Escarlata
-- https://es.classic.wowhead.com/quest=5063
SET @ID := 5063;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A menos que tengas todo lo que necesito, estás perdiendo mi tiempo.', 0),
(@ID, 'esMX', 'A menos que tengas todo lo que necesito, estás perdiendo mi tiempo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Asombroso! Ha debido tomarte semanas reunir esos componentes... ¿y cómo encontraste un pellejo de Bestia prístino?!?$B$B¡Disfruta la gorra, $n!', 0),
(@ID, 'esMX', '¡Asombroso! Ha debido tomarte semanas reunir esos componentes... ¿y cómo encontraste un pellejo de Bestia prístino?!?$B$B¡Disfruta la gorra, $n!', 0);
-- 5064 Espiando a los Tótem Siniestro
-- https://es.classic.wowhead.com/quest=5064
SET @ID := 5064;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has descubierto qué está tramando el clan Tótem Siniestro?', 0),
(@ID, 'esMX', '¿Has descubierto qué está tramando el clan Tótem Siniestro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gran tótem espiritual! ¡Qué malas noticias! Debo empezar a prepararme para lo que sea que se avecina.$B$B$n, como te prometí, aquí tienes la recompensa por tu valerosa ayuda.', 0),
(@ID, 'esMX', '¡Gran tótem espiritual! ¡Qué malas noticias! Debo empezar a prepararme para lo que sea que se avecina.$B$B$n, como te prometí, aquí tienes la recompensa por tu valerosa ayuda.', 0);
-- Un llamamiento a las armas: las Tierras de la Peste
-- 5066, 5090, 10373
-- https://es.classic.wowhead.com/quest=5066
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5066, 5090, 10373) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5066, 'esES', '$gBienvenido:Bienvenida; a las Tierras de la Peste, $ghéroe:heroína;. Esta es una de las fronteras más peligrosas de Azeroth, especialmente con la amenaza inminente de la Plaga en nuestro norte y noreste. ¡Me alegra saber que el clarín del deber y el servicio al bien mayor no cayó en oídos sordos contigo!$B$BSi estás $glisto:lista; para ensuciarte las manos, entonces hay mucho que hacer aquí para $glos héroes dispuestos:las heroínas dispuestas; y capaces en el borde de las Tierras de la Peste.', 0),
(5090, 'esES', '$gBienvenido:Bienvenida; a las Tierras de la Peste, $ghéroe:heroína;. Esta es una de las fronteras más peligrosas de Azeroth, especialmente con la amenaza inminente de la Plaga en nuestro norte y noreste. ¡Me alegra saber que el clarín del deber y el servicio al bien mayor no cayó en oídos sordos contigo!$B$BSi estás $glisto:lista; para ensuciarte las manos, entonces hay mucho que hacer aquí para $glos héroes dispuestos:las heroínas dispuestas; y capaces en el borde de las Tierras de la Peste.', 0),
(10373, 'esES', '$gBienvenido:Bienvenida; a las Tierras de la Peste, $ghéroe:heroína;. Esta es una de las fronteras más peligrosas de Azeroth, especialmente con la amenaza inminente de la Plaga en nuestro norte y noreste. ¡Me alegra saber que el clarín del deber y el servicio al bien mayor no cayó en oídos sordos contigo!$B$BSi estás $glisto:lista; para ensuciarte las manos, entonces hay mucho que hacer aquí para $glos héroes dispuestos:las heroínas dispuestas; y capaces en el borde de las Tierras de la Peste.', 0),
(5066, 'esMX', '$gBienvenido:Bienvenida; a las Tierras de la Peste, $ghéroe:heroína;. Esta es una de las fronteras más peligrosas de Azeroth, especialmente con la amenaza inminente de la Plaga en nuestro norte y noreste. ¡Me alegra saber que el clarín del deber y el servicio al bien mayor no cayó en oídos sordos contigo!$B$BSi estás $glisto:lista; para ensuciarte las manos, entonces hay mucho que hacer aquí para $glos héroes dispuestos:las heroínas dispuestas; y capaces en el borde de las Tierras de la Peste.', 0),
(5090, 'esMX', '$gBienvenido:Bienvenida; a las Tierras de la Peste, $ghéroe:heroína;. Esta es una de las fronteras más peligrosas de Azeroth, especialmente con la amenaza inminente de la Plaga en nuestro norte y noreste. ¡Me alegra saber que el clarín del deber y el servicio al bien mayor no cayó en oídos sordos contigo!$B$BSi estás $glisto:lista; para ensuciarte las manos, entonces hay mucho que hacer aquí para $glos héroes dispuestos:las heroínas dispuestas; y capaces en el borde de las Tierras de la Peste.', 0),
(10373, 'esMX', '$gBienvenido:Bienvenida; a las Tierras de la Peste, $ghéroe:heroína;. Esta es una de las fronteras más peligrosas de Azeroth, especialmente con la amenaza inminente de la Plaga en nuestro norte y noreste. ¡Me alegra saber que el clarín del deber y el servicio al bien mayor no cayó en oídos sordos contigo!$B$BSi estás $glisto:lista; para ensuciarte las manos, entonces hay mucho que hacer aquí para $glos héroes dispuestos:las heroínas dispuestas; y capaces en el borde de las Tierras de la Peste.', 0);
-- 5091 Un llamamiento a las armas: las Tierras de la Peste
-- Fix male/female
SET @ID := 5091;
UPDATE `quest_offer_reward_locale` SET `RewardText` = '$gBienvenido:Bienvenida; a las Tierras de la Peste, $ghéroe:heroína;. Esta es una de las fronteras más peligrosas de Azeroth, especialmente con la amenaza inminente de la Plaga en nuestro norte y noreste. ¡Me alegra saber que el clarín del deber y el servicio al bien mayor no cayó en oídos sordos contigo!$B$BSi estás $glisto:lista; para ensuciarte las manos, entonces hay mucho que hacer aquí para $glos héroes dispuestos:las heroínas dispuestas; y capaces en el borde de las Tierras de la Peste.', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- Un llamamiento a las armas: las Tierras de la Peste
-- 5093, 5094, 5095, 10374
-- https://es.classic.wowhead.com/quest=5093
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5093, 5094, 5095, 10374) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5093, 'esES', '$gBienvenido:Bienvenida; a las Tierras de la Peste. Esta es una de las fronteras más peligrosas de Azeroth, especialmente por la amenaza de la Plaga que se avecina desde el este. Me alegro de que hayas escuchado la llamada del deber y hayas venido a prestar servicio a la Horda.$B$BSi estás $gpreparado:preparada; para ponerte manos a la obra, hay mucho que puedes hacer aquí, en la frontera de las Tierras de la Peste.', 0),
(5094, 'esES', '$gBienvenido:Bienvenida; a las Tierras de la Peste. Esta es una de las fronteras más peligrosas de Azeroth, especialmente por la amenaza de la Plaga que se avecina desde el este. Me alegro de que hayas escuchado la llamada del deber y hayas venido a prestar servicio a la Horda.$B$BSi estás $gpreparado:preparada; para ponerte manos a la obra, hay mucho que puedes hacer aquí, en la frontera de las Tierras de la Peste.', 0),
(5095, 'esES', '$gBienvenido:Bienvenida; a las Tierras de la Peste. Esta es una de las fronteras más peligrosas de Azeroth, especialmente por la amenaza de la Plaga que se avecina desde el este. Me alegro de que hayas escuchado la llamada del deber y hayas venido a prestar servicio a la Horda.$B$BSi estás $gpreparado:preparada; para ponerte manos a la obra, hay mucho que puedes hacer aquí, en la frontera de las Tierras de la Peste.', 0),
(10374, 'esES', '$gBienvenido:Bienvenida; a las Tierras de la Peste. Esta es una de las fronteras más peligrosas de Azeroth, especialmente por la amenaza de la Plaga que se avecina desde el este. Me alegro de que hayas escuchado la llamada del deber y hayas venido a prestar servicio a la Horda.$B$BSi estás $gpreparado:preparada; para ponerte manos a la obra, hay mucho que puedes hacer aquí, en la frontera de las Tierras de la Peste.', 0),
(5093, 'esMX', '$gBienvenido:Bienvenida; a las Tierras de la Peste. Esta es una de las fronteras más peligrosas de Azeroth, especialmente por la amenaza de la Plaga que se avecina desde el este. Me alegro de que hayas escuchado la llamada del deber y hayas venido a prestar servicio a la Horda.$B$BSi estás $gpreparado:preparada; para ponerte manos a la obra, hay mucho que puedes hacer aquí, en la frontera de las Tierras de la Peste.', 0),
(5094, 'esMX', '$gBienvenido:Bienvenida; a las Tierras de la Peste. Esta es una de las fronteras más peligrosas de Azeroth, especialmente por la amenaza de la Plaga que se avecina desde el este. Me alegro de que hayas escuchado la llamada del deber y hayas venido a prestar servicio a la Horda.$B$BSi estás $gpreparado:preparada; para ponerte manos a la obra, hay mucho que puedes hacer aquí, en la frontera de las Tierras de la Peste.', 0),
(5095, 'esMX', '$gBienvenido:Bienvenida; a las Tierras de la Peste. Esta es una de las fronteras más peligrosas de Azeroth, especialmente por la amenaza de la Plaga que se avecina desde el este. Me alegro de que hayas escuchado la llamada del deber y hayas venido a prestar servicio a la Horda.$B$BSi estás $gpreparado:preparada; para ponerte manos a la obra, hay mucho que puedes hacer aquí, en la frontera de las Tierras de la Peste.', 0),
(10374, 'esMX', '$gBienvenido:Bienvenida; a las Tierras de la Peste. Esta es una de las fronteras más peligrosas de Azeroth, especialmente por la amenaza de la Plaga que se avecina desde el este. Me alegro de que hayas escuchado la llamada del deber y hayas venido a prestar servicio a la Horda.$B$BSi estás $gpreparado:preparada; para ponerte manos a la obra, hay mucho que puedes hacer aquí, en la frontera de las Tierras de la Peste.', 0);
-- 5067 Leotardos de Arcana
-- https://es.classic.wowhead.com/quest=5067
SET @ID := 5067;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A menos que tengas todo lo que necesito, estás perdiendo mi tiempo.', 0),
(@ID, 'esMX', 'A menos que tengas todo lo que necesito, estás perdiendo mi tiempo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pocas tareas más improbables que esta he visto completadas por mortales. ¡Disfruta de la gloria de mi obra! ¡Obtén tu recompensa!', 0),
(@ID, 'esMX', 'Pocas tareas más improbables que esta he visto completadas por mortales. ¡Disfruta de la gloria de mi obra! ¡Obtén tu recompensa!', 0);
-- 5068 Coraza Sed de Sangre
-- https://es.classic.wowhead.com/quest=5068
SET @ID := 5068;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A menos que tengas todo lo que necesito, estás perdiendo mi tiempo.', 0),
(@ID, 'esMX', 'A menos que tengas todo lo que necesito, estás perdiendo mi tiempo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pensé que estaría muerto y enterrado antes de ver este día.$B$BUn logro de esta magnitud solo puede ser eclipsado por su recompensa.', 0),
(@ID, 'esMX', 'Pensé que estaría muerto y enterrado antes de ver este día.$B$BUn logro de esta magnitud solo puede ser eclipsado por su recompensa.', 0);
-- 5081 La misión de Maxwell
-- https://es.classic.wowhead.com/quest=5081
SET @ID := 5081;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Novedades?', 0),
(@ID, 'esMX', '¿Novedades?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. Como mínimo, nos has dado más tiempo, un tiempo precioso, precioso.', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. Como mínimo, nos has dado más tiempo, un tiempo precioso, precioso.', 0);
-- 5083 Aguardiente Nevada
-- https://es.classic.wowhead.com/quest=5083
SET @ID := 5083;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué has encontrado?', 0),
(@ID, 'esMX', '¿Qué has encontrado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo obtuviste de los Nevada?', 0),
(@ID, 'esMX', '¿Lo obtuviste de los Nevada?', 0);
-- 5084 Sucumbir a la corrupción
-- https://es.classic.wowhead.com/quest=5084
SET @ID := 5084;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En la caldera burbujea una sustancia putrefacta y de olor repulsivo...', 0),
(@ID, 'esMX', 'En la caldera burbujea una sustancia putrefacta y de olor repulsivo...', 0);
-- 5085 Baba misteriosa
-- https://es.classic.wowhead.com/quest=5085
SET @ID := 5085;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que hayas encontrado algo, $n. ¡Los Nevada son cada vez más agresivos!', 0),
(@ID, 'esMX', 'Espero que hayas encontrado algo, $n. ¡Los Nevada son cada vez más agresivos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes muchos recursos, $n. ¿Crees que los furbolgs Nevada han estado en el campamento Muertobosque?', 0),
(@ID, 'esMX', 'Tienes muchos recursos, $n. ¿Crees que los furbolgs Nevada han estado en el campamento Muertobosque?', 0);
-- 5086 Horrores tóxicos
-- https://es.classic.wowhead.com/quest=5086
SET @ID := 5086;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Creo que estamos empezando a averiguar qué ha pasado aquí, $n.', 0),
(@ID, 'esMX', 'Creo que estamos empezando a averiguar qué ha pasado aquí, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo que compararlo con la sustancia que encontraste en la caldera, entonces sabremos algo más.', 0),
(@ID, 'esMX', 'Tengo que compararlo con la sustancia que encontraste en la caldera, entonces sabremos algo más.', 0);
-- 5087 Corredores Nevada
-- https://es.classic.wowhead.com/quest=5087
SET @ID := 5087;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Veremos lo que ocurre cuando los Nevada se queden sin su aguardiente!', 0),
(@ID, 'esMX', '¡Veremos lo que ocurre cuando los Nevada se queden sin su aguardiente!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Donova examina el contenido del cajón.>$B$BMe pregunto si el consumo de esta sustancia hace a los furbolgs más agresivos. Parecen mucho más grandes...', 0),
(@ID, 'esMX', '<Donova examina el contenido del cajón.>$B$BMe pregunto si el consumo de esta sustancia hace a los furbolgs más agresivos. Parecen mucho más grandes...', 0);
-- 5088 Arikara
-- https://es.classic.wowhead.com/quest=5088
SET @ID := 5088;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has matado a la despiadada serpiente Arikara, $n?', 0),
(@ID, 'esMX', '¿Has matado a la despiadada serpiente Arikara, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto no tiene sentido. ¿Por qué iba Arikara a andar tras Cairne Pezuña de Sangre? Magatha no puede estar equivocada, es una de nuestras chamanes más poderosas.$B$B<Motega niega con la cabeza.>$B$BSea como sea, tu hazaña en favor de la Horda no pasará inadvertida. Por favor, elige uno de estos como recompensa por tu ayuda.', 0),
(@ID, 'esMX', 'Esto no tiene sentido. ¿Por qué iba Arikara a andar tras Cairne Pezuña de Sangre? Magatha no puede estar equivocada, es una de nuestras chamanes más poderosas.$B$B<Motega niega con la cabeza.>$B$BSea como sea, tu hazaña en favor de la Horda no pasará inadvertida. Por favor, elige uno de estos como recompensa por tu ayuda.', 0);
-- 5089 Orden del general Drakkisath
-- https://es.classic.wowhead.com/quest=5089
SET @ID := 5089;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes ahí, $n?', 0),
(@ID, 'esMX', '¿Qué tienes ahí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La trama se complica...', 0),
(@ID, 'esMX', 'La trama se complica...', 0);
-- 5092 Despejar el camino
-- https://es.classic.wowhead.com/quest=5092
SET @ID := 5092;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Quiero que te prepares para lo peor, $n, profundiza. La tarea que tenemos por delante no será fácil. A medida que reunimos nuestras fuerzas aquí para eventualmente atacar a la Plaga, ¡serás parte de nuestro esfuerzo que los llevará a luchar! ¡Tu misión en la Colina de las Penas iniciará nuestro camino hacia la victoria!', 0),
(@ID, 'esMX', 'Quiero que te prepares para lo peor, $n, profundiza. La tarea que tenemos por delante no será fácil. A medida que reunimos nuestras fuerzas aquí para eventualmente atacar a la Plaga, ¡serás parte de nuestro esfuerzo que los llevará a luchar! ¡Tu misión en la Colina de las Penas iniciará nuestro camino hacia la victoria!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Misión cumplida, $n! Buena jugada, buena jugada.$B$BDéjame recompensarte por tu trabajo con algunas monedas de las arcas de Ventormenta. Te recomendaría gastar el dinero en algo que te ayude en tu próxima misión... la que te llevará a las ruinas de Andorhal.$B$B¡Deberás estar $gpreparado:preparada;! ¡Mantente alerta!', 0),
(@ID, 'esMX', '¡Misión cumplida, $n! Buena jugada, buena jugada.$B$BDéjame recompensarte por tu trabajo con algunas monedas de las arcas de Ventormenta. Te recomendaría gastar el dinero en algo que te ayude en tu próxima misión... la que te llevará a las ruinas de Andorhal.$B$B¡Deberás estar $gpreparado:preparada;! ¡Mantente alerta!', 0);
-- 5096 Distracción Escarlata
-- https://es.classic.wowhead.com/quest=5096
SET @ID := 5096;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una ejecución perfecta, $n. Tu ataque a la Cruzada Escarlata nos dará algo de tiempo. He enviado a uno de mis mejores exploradores para vigilar el campamento y asegurarnos de que las fuerzas de la Cruzada que vinieron a reforzar la posición se tragarán el anzuelo.$B$BCuando se aligere la presión a la que estamos sometidos deberíamos poder arriesgarnos a adentrarnos en Andorhal, una misión realmente importante. Por todos tus éxitos hasta la fecha, me encantaría que fueras tú quien se encargara también esta vez de la misión.', 0),
(@ID, 'esMX', 'Una ejecución perfecta, $n. Tu ataque a la Cruzada Escarlata nos dará algo de tiempo. He enviado a uno de mis mejores exploradores para vigilar el campamento y asegurarnos de que las fuerzas de la Cruzada que vinieron a reforzar la posición se tragarán el anzuelo.$B$BCuando se aligere la presión a la que estamos sometidos deberíamos poder arriesgarnos a adentrarnos en Andorhal, una misión realmente importante. Por todos tus éxitos hasta la fecha, me encantaría que fueras tú quien se encargara también esta vez de la misión.', 0);
-- 5097 Todas las atalayas
-- https://es.classic.wowhead.com/quest=5097
SET @ID := 5097;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Torre Uno marcada', `ObjectiveText2` = 'Torre Dos marcada', `ObjectiveText3` = 'Torre Tres marcada', `ObjectiveText4` = 'Torre Cuatro marcada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una vez que las torres estén marcadas, se convertirán en objetivos de máxima prioridad para nuestro ataque a Andorhal. Sospecho que una vez que neutralicemos las torres, surgirá la principal amenaza de Andorhal. ¡A partir de ese momento, tendremos una lucha directa por el control de la ciudad!$B$Bhas vuelto para informar del éxito, ¿no? No olvides también la antorcha de aviso; debemos mantener el control de nuestro material.', 0),
(@ID, 'esMX', 'Una vez que las torres estén marcadas, se convertirán en objetivos de máxima prioridad para nuestro ataque a Andorhal. Sospecho que una vez que neutralicemos las torres, surgirá la principal amenaza de Andorhal. ¡A partir de ese momento, tendremos una lucha directa por el control de la ciudad!$B$Bhas vuelto para informar del éxito, ¿no? No olvides también la antorcha de aviso; debemos mantener el control de nuestro material.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Mis sacerdotes informan de que nuestros rastreadores están recibiendo señales muy fuertes de las cuatro torres! No sé si debería decirlo, pero creo que has realizado otra misión con total y completo éxito. ¡Buena jugada de nuevo, $n!$B$BCon las torres marcadas, podemos pasar a los preparativos para el ataque. ¡Ha llegado el momento de combatir a la Plaga!', 0),
(@ID, 'esMX', '¡Mis sacerdotes informan de que nuestros rastreadores están recibiendo señales muy fuertes de las cuatro torres! No sé si debería decirlo, pero creo que has realizado otra misión con total y completo éxito. ¡Buena jugada de nuevo, $n!$B$BCon las torres marcadas, podemos pasar a los preparativos para el ataque. ¡Ha llegado el momento de combatir a la Plaga!', 0);
-- 5098 Todas las atalayas
-- https://es.classic.wowhead.com/quest=5098
SET @ID := 5098;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Torre Uno marcada', `ObjectiveText2` = 'Torre Dos marcada', `ObjectiveText3` = 'Torre Tres marcada', `ObjectiveText4` = 'Torre Cuatro marcada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una vez que las torres estén marcadas, se convertirán en objetivos de máxima prioridad para nuestro ataque a Andorhal. Sospecho que una vez que neutralicemos las torres, surgirá la principal amenaza de Andorhal. ¡A partir de ese momento, tendremos una lucha directa por el control de la ciudad!$B$Bhas vuelto para informar del éxito, ¿no? No olvides también la antorcha de aviso; debemos mantener el control de nuestro material.', 0),
(@ID, 'esMX', 'Una vez que las torres estén marcadas, se convertirán en objetivos de máxima prioridad para nuestro ataque a Andorhal. Sospecho que una vez que neutralicemos las torres, surgirá la principal amenaza de Andorhal. ¡A partir de ese momento, tendremos una lucha directa por el control de la ciudad!$B$Bhas vuelto para informar del éxito, ¿no? No olvides también la antorcha de aviso; debemos mantener el control de nuestro material.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Mis brujos informan de que nuestros rastreadores están recibiendo señales muy fuertes de las cuatro torres! No sé si debería decirlo, pero creo que has realizado otra misión con total y completo éxito. ¡Buena jugada de nuevo, $n!$B$BCon las torres marcadas, podemos pasar a los preparativos para el ataque. ¡Ha llegado el momento de combatir a la Plaga!', 0),
(@ID, 'esMX', '¡Mis brujos informan de que nuestros rastreadores están recibiendo señales muy fuertes de las cuatro torres! No sé si debería decirlo, pero creo que has realizado otra misión con total y completo éxito. ¡Buena jugada de nuevo, $n!$B$BCon las torres marcadas, podemos pasar a los preparativos para el ataque. ¡Ha llegado el momento de combatir a la Plaga!', 0);
-- 5102 Muerte al general Drakkisath
-- https://es.classic.wowhead.com/quest=5102
SET @ID := 5102;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Está hecho?', 0),
(@ID, 'esMX', '¿Está hecho?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Claro, ahora atacaremos a sus jefes dragones. ¡Muy bien, valiente soldado de la Alianza! ¡Pero que muy bien!', 0),
(@ID, 'esMX', 'Claro, ahora atacaremos a sus jefes dragones. ¡Muy bien, valiente soldado de la Alianza! ¡Pero que muy bien!', 0);
-- 5103 Muerte abrasadora
-- https://es.classic.wowhead.com/quest=5103
SET @ID := 5103;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que...', 0),
(@ID, 'esMX', 'Que...', 0);
-- 5121 Gran Jefe Nevada
-- https://es.classic.wowhead.com/quest=5121
SET @ID := 5121;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Quizás descubras más en Poblado Nevada, $n.', 0),
(@ID, 'esMX', 'Quizás descubras más en Poblado Nevada, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchas gracias, $n. Espero volver a mis estudios sin tener que preocuparme por nuevas emboscadas. Por favor, acepta esto como recompensa.', 0),
(@ID, 'esMX', 'Muchas gracias, $n. Espero volver a mis estudios sin tener que preocuparme por nuevas emboscadas. Por favor, acepta esto como recompensa.', 0);
-- 5122 El medallón de Fe
-- https://es.classic.wowhead.com/quest=5122
SET @ID := 5122;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El poder de esta capilla me da la fuerza para resistir la corrupción que habita en mi corazón. Si cedo, me convertiré en un caballero de la muerte. Pero hay un medallón, el medallón de fe, que me dará la fuerza que necesito para partir.$B$BPor favor, $n, recupera el medallón. Está en manos de Malor el Fanático, un miembro demente de la Cruzada Escarlata, que reside en las profundidades del Bastión Escarlata en Stratholme occidental.', 0),
(@ID, 'esMX', 'El poder de esta capilla me da la fuerza para resistir la corrupción que habita en mi corazón. Si cedo, me convertiré en un caballero de la muerte. Pero hay un medallón, el medallón de fe, que me dará la fuerza que necesito para partir.$B$BPor favor, $n, recupera el medallón. Está en manos de Malor el Fanático, un miembro demente de la Cruzada Escarlata, que reside en las profundidades del Bastión Escarlata en Stratholme occidental.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has conseguido el medallón! Ahora podré abandonar por fin la capilla y cumplir con mi deber.$B$BEse deber es matar a la bestia que ayudó en mi corrupción y en la de tantos de mis hermanos y hermanas, ¡el Barón Osahendido!', 0),
(@ID, 'esMX', '¡Has conseguido el medallón! Ahora podré abandonar por fin la capilla y cumplir con mi deber.$B$BEse deber es matar a la bestia que ayudó en mi corrupción y en la de tantos de mis hermanos y hermanas, ¡el Barón Osahendido!', 0);
-- 5123 La pieza final
-- https://es.classic.wowhead.com/quest=5123
SET @ID := 5123;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto, $n?', 0),
(@ID, 'esMX', '¿Qué es esto, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me pregunto qué significa todo esto... No entiendo nada...', 0),
(@ID, 'esMX', 'Me pregunto qué significa todo esto... No entiendo nada...', 0);
-- 5124 Guanteletes de placas ígneas
-- https://es.classic.wowhead.com/quest=5124
SET @ID := 5124;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El tiempo es dinero, $n y tampoco tengo mucho.', 0),
(@ID, 'esMX', 'El tiempo es dinero, $n y tampoco tengo mucho.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Como prometí, $N, ¡aquí está tu receta! También voy a agregar algo extra por todo tu arduo trabajo y dedicación. ¿¿Qué voy a hacer con esto de todos modos???', 0),
(@ID, 'esMX', 'Como prometí, $N, ¡aquí está tu receta! También voy a agregar algo extra por todo tu arduo trabajo y dedicación. ¿¿Qué voy a hacer con esto de todos modos???', 0);
-- 5125 La estimación de Aurius
-- https://es.classic.wowhead.com/quest=5125
SET @ID := 5125;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, me estoy muriendo... pero mi alma está salvada. Por eso, te debo más de lo que jamás podré expresar. Por favor, acepta esto, ¡y sigue luchando... valiente $c!', 0),
(@ID, 'esMX', '$n, me estoy muriendo... pero mi alma está salvada. Por eso, te debo más de lo que jamás podré expresar. Por favor, acepta esto, ¡y sigue luchando... valiente $c!', 0);
-- 5126 La historia de Lorax
-- https://es.classic.wowhead.com/quest=5126
SET @ID := 5126;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Lorax se ríe.>', 0),
(@ID, 'esMX', '<Lorax se ríe.>', 0);
-- 5127 La forja demoníaca
-- https://es.classic.wowhead.com/quest=5127
SET @ID := 5127;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No tientes...', 0),
(@ID, 'esMX', 'No tientes...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestro pacto no rompiste. El alma que me llevé. La recompensa que haré.', 0),
(@ID, 'esMX', 'Nuestro pacto no rompiste. El alma que me llevé. La recompensa que haré.', 0);
