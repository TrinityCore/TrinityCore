-- 1021 ¡Vil sátiro! ¡Dríades en peligro!
-- https://es.classic.wowhead.com/quest=1021
SET @ID := 1021;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A juzgar por la herida abierta en el costado, Anilia está al borde de la muerte.', 0),
(@ID, 'esMX', 'A juzgar por la herida abierta en el costado, Anilia está al borde de la muerte.', 0);
-- 1022 La Vega del Aullido
-- https://es.classic.wowhead.com/quest=1022
SET @ID := 1022;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El tomo del santuario es un objeto misterioso. No es un libro en el sentido tradicional. Las hojas del tomo fueron bendecidas por la propia Mel\'Thandris, y registra eventos importantes en sus páginas.$B$BMe cuesta explicarlo. Si vas al santuario, lo entenderás.', 0),
(@ID, 'esMX', 'El tomo del santuario es un objeto misterioso. No es un libro en el sentido tradicional. Las hojas del tomo fueron bendecidas por la propia Mel\'Thandris, y registra eventos importantes en sus páginas.$B$BMe cuesta explicarlo. Si vas al santuario, lo entenderás.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Libro de Mel\'Thandris funciona de extraña manera. Los acontecimientos que registra, los que muestra... Nadie entiende realmente por qué hace lo que hace.$B$BNo obstante, es evidente que lo que la sacerdotisa Cantoestelar recibió, esta Guadaña de Elune, merece algo más de investigación.', 0),
(@ID, 'esMX', 'El Libro de Mel\'Thandris funciona de extraña manera. Los acontecimientos que registra, los que muestra... Nadie entiende realmente por qué hace lo que hace.$B$BNo obstante, es evidente que lo que la sacerdotisa Cantoestelar recibió, esta Guadaña de Elune, merece algo más de investigación.', 0);
-- 1031 La Rama de Cenarius
-- https://es.classic.wowhead.com/quest=1031
SET @ID := 1031;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Los has encontrado? ¿Qué dijo Anilia? ¿Donde esta ella?', 0),
(@ID, 'esMX', '¿Los has encontrado? ¿Qué dijo Anilia? ¿Donde esta ella?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Anilia murió? No... ¡eso no puede ser! Fue ayer cuando estábamos corriendo y jugando juntos en el bosque.$B$BSupongo que esos días se acabaron...', 0),
(@ID, 'esMX', '¿Anilia murió? No... ¡eso no puede ser! Fue ayer cuando estábamos corriendo y jugando juntos en el bosque.$B$BSupongo que esos días se acabaron...', 0);
-- 1032 ¡Muerte a los sátiros!
-- https://es.classic.wowhead.com/quest=1032
SET @ID := 1032;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te lo ruego, ayúdame a vengar la muerte de Anilia.', 0),
(@ID, 'esMX', 'Te lo ruego, ayúdame a vengar la muerte de Anilia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, amable $r. El espíritu de mi hermana se llena de gozo con tus esfuerzos.', 0),
(@ID, 'esMX', 'Gracias, amable $r. El espíritu de mi hermana se llena de gozo con tus esfuerzos.', 0);
-- 1036 ¡Adelante, pillín!
-- https://es.classic.wowhead.com/quest=1036
SET @ID := 1036;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gQuieto:Quieta; ahí, canalla. He escuchado muchas cosas sobre ti. Bueno, si no eres $gamigo:amiga; de Bahía del Botín, podrías tener un lugar especial con los Bucaneros Velasangre.$B$BArrrrr...', 0),
(@ID, 'esMX', '$gQuieto:Quieta; ahí, canalla. He escuchado muchas cosas sobre ti. Bueno, si no eres $gamigo:amiga; de Bahía del Botín, podrías tener un lugar especial con los Bucaneros Velasangre.$B$BArrrrr...', 0);
-- 4621 ¡Adelante, almirante!
-- https://es.classic.wowhead.com/quest=4621
SET @ID := 4621;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ya volviste, maldito alquitrán! ¿Has hecho lo que te he ordenado? Si nos fallas, estarás caminando por la tabla.$B$BArrrrr...', 0),
(@ID, 'esMX', '¡Ya volviste, maldito alquitrán! ¿Has hecho lo que te he ordenado? Si nos fallas, estarás caminando por la tabla.$B$BArrrrr...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Alto ahí, almirante $n! ¡Eres un pirata de piratas, $gmuchacho:muchacha;!$B$BMe alegra el corazón darte este sombrero. ¡Nunca encontrarás uno igual en ninguna parte, y todos los que te miran verán que eres un almirante de la Armada Velasangre!', 0),
(@ID, 'esMX', '¡Alto ahí, almirante $n! ¡Eres un pirata de piratas, $gmuchacho:muchacha;!$B$BMe alegra el corazón darte este sombrero. ¡Nunca encontrarás uno igual en ninguna parte, y todos los que te miran verán que eres un almirante de la Armada Velasangre!', 0);
-- 1037 Velinde Cantoestelar
-- https://es.classic.wowhead.com/quest=1037
SET @ID := 1037;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Velinde Cantoestelar? Que la sacerdotisa lleva algún tiempo desaparecida no es ningún secreto. Pero en cuanto a más detalles sobre los acontecimientos que rodearon su partida... haría falta una razón de peso para divulgar tal información.', 0),
(@ID, 'esMX', '¿Velinde Cantoestelar? Que la sacerdotisa lleva algún tiempo desaparecida no es ningún secreto. Pero en cuanto a más detalles sobre los acontecimientos que rodearon su partida... haría falta una razón de peso para divulgar tal información.', 0);
-- 1038 Las pertenencias de Velinde
-- https://es.classic.wowhead.com/quest=1038
SET @ID := 1038;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué has descubierto?', 0),
(@ID, 'esMX', '¿Qué has descubierto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que la desaparición de Velinde es aún más preocupante de lo que parecía en un principio. Aún así, no quiero pensar que haya tenido un mal final. Quizás nos beneficiaría contactar con ella.$B$B$n, como has demostrado tu interés en este asunto, quisiera pedirte tu ayuda.', 0),
(@ID, 'esMX', 'Parece que la desaparición de Velinde es aún más preocupante de lo que parecía en un principio. Aún así, no quiero pensar que haya tenido un mal final. Quizás nos beneficiaría contactar con ella.$B$B$n, como has demostrado tu interés en este asunto, quisiera pedirte tu ayuda.', 0);
-- 1039 El puerto de Los Baldíos
-- https://es.classic.wowhead.com/quest=1039
SET @ID := 1039;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$r, ¿eh? He de admitir que no solemos tener a muchos de los tuyos por aquí. Estás buscando a alguien, ¿eh? Dame un momento, seguro que lo tengo escrito en alguno de mis libros.$B$BPero la gente que pasa por aquí es mucha, así que necesito un momento.', 0),
(@ID, 'esMX', '$r, ¿eh? He de admitir que no solemos tener a muchos de los tuyos por aquí. Estás buscando a alguien, ¿eh? Dame un momento, seguro que lo tengo escrito en alguno de mis libros.$B$BPero la gente que pasa por aquí es mucha, así que necesito un momento.', 0);
-- 1040 Pasaje a Bahía del Botín
-- https://es.classic.wowhead.com/quest=1040
SET @ID := 1040;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? Vaya, no tienes pinta de traer mercancía para enviar, así que o buscas trabajo en mi caravana, y ahora no hay ninguno, o te has equivocado de goblin.$B$B¿De qué se trata?', 0),
(@ID, 'esMX', '¿Sí? Vaya, no tienes pinta de traer mercancía para enviar, así que o buscas trabajo en mi caravana, y ahora no hay ninguno, o te has equivocado de goblin.$B$B¿De qué se trata?', 0);
-- 8330 Las posesiones de Solanian
-- https://es.classic.wowhead.com/quest=8330
SET @ID := 8330;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido la oportunidad de encontrar mis pertenencias? Una vez que reafirmemos nuestro dominio sobre la Isla del Caminante, te necesitaré en mi trabajo. Por ahora, sin embargo, debo vigilar la Fuente del Sol... o lo que queda de ella.', 0),
(@ID, 'esMX', '¿Has tenido la oportunidad de encontrar mis pertenencias? Una vez que reafirmemos nuestro dominio sobre la Isla del Caminante, te necesitaré en mi trabajo. Por ahora, sin embargo, debo vigilar la Fuente del Sol... o lo que queda de ella.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, sabía que serías $gperfecto:perfecta; para la tarea. Una vez que sea seguro hacer uso de nuestras instalaciones al aire libre en la isla, haré un buen uso de estas cosas.$B$BComo mencioné, siéntete libre de quedarte con la cartera. Además, esta pieza de equipo puede resultarte útil. ¡Considérelo una amplia compensación por una simple tarea realizada con diligencia!', 0),
(@ID, 'esMX', 'Bien hecho, sabía que serías $gperfecto:perfecta; para la tarea. Una vez que sea seguro hacer uso de nuestras instalaciones al aire libre en la isla, haré un buen uso de estas cosas.$B$BComo mencioné, siéntete libre de quedarte con la cartera. Además, esta pieza de equipo puede resultarte útil. ¡Considérelo una amplia compensación por una simple tarea realizada con diligencia!', 0);
-- 8345 Santuario de Dath'Remar
-- https://es.classic.wowhead.com/quest=8345
SET @ID := 8345;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Placa del Santuario de Dath\'Remar leída', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has leído la placa del santuario, $c?', 0),
(@ID, 'esMX', '¿Has leído la placa del santuario, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n, gracias por compartir su experiencia en el Santuario de Dath\'Remar. En primer lugar, debes ser $gfelicitado:felicitada; por tu sentido del deber y respeto; te será de gran utilidad no solo aquí, sino también en todo Azeroth.$B$BEn cuanto a la extraña sensación, sin duda es una parte que contribuye a la mancha que ha caído sobre la Isla del Caminante. Lo vigilaremos; ¡Gracias por avisarnos!', 0),
(@ID, 'esMX', 'Ah, $n, gracias por compartir su experiencia en el Santuario de Dath\'Remar. En primer lugar, debes ser $gfelicitado:felicitada; por tu sentido del deber y respeto; te será de gran utilidad no solo aquí, sino también en todo Azeroth.$B$BEn cuanto a la extraña sensación, sin duda es una parte que contribuye a la mancha que ha caído sobre la Isla del Caminante. Lo vigilaremos; ¡Gracias por avisarnos!', 0);
-- 8334 Agresividad
-- https://es.classic.wowhead.com/quest=8334
SET @ID := 8334;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es mejor que aprendas sobre la supervivencia, y los costos de la supervivencia, ahora que después. Tomar decisiones difíciles es algo a lo que tendrás que acostumbrarte como $r.$B$BNo había nadie allí para nosotros cuando la Plaga partió nuestras casas en dos. Fuimos nosotros y solo nosotros los que nos levantamos con esfuerzo.', 0),
(@ID, 'esMX', 'Es mejor que aprendas sobre la supervivencia, y los costos de la supervivencia, ahora que después. Tomar decisiones difíciles es algo a lo que tendrás que acostumbrarte como $r.$B$BNo había nadie allí para nosotros cuando la Plaga partió nuestras casas en dos. Fuimos nosotros y solo nosotros los que nos levantamos con esfuerzo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me alegro en absoluto de la muerte de los tiernos, pero demuestra que estás a punto para tu tarea más importante en la Isla del Caminante del Sol. Toma esto y úsalo bien; necesitarás objetos de calidad y tener la mente despierta para la misión que te espera. De ella depende que recuperemos el control de la isla.', 0),
(@ID, 'esMX', 'No me alegro en absoluto de la muerte de los tiernos, pero demuestra que estás a punto para tu tarea más importante en la Isla del Caminante del Sol. Toma esto y úsalo bien; necesitarás objetos de calidad y tener la mente despierta para la misión que te espera. De ella depende que recuperemos el control de la isla.', 0);
-- 8335 Felendren el Desterrado
-- https://es.wowhead.com/quest=8335
SET @ID := 8335;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Óyeme bien: Felendren el Desterrado no es sino el síntoma de un problema mucho mayor. Su muerte resolverá los problemas inmediatos, pero todos los elfos de sangre estamos expuestos a sufrir su mismo destino si nos dejamos dominar por nuestras adicciones.', 0),
(@ID, 'esMX', 'Óyeme bien: Felendren el Desterrado no es sino el síntoma de un problema mucho mayor. Su muerte resolverá los problemas inmediatos, pero todos los elfos de sangre estamos expuestos a sufrir su mismo destino si nos dejamos dominar por nuestras adicciones.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La cabeza de Felendren... Acabas de ganarte una mención honorífica, $n. Has tenido éxito donde otros, como el propio Felendren, han fallado miserablemente. Puede que haya llegado el momento de convertirte en miembro de la sociedad de los elfos de sangre.$B$BEsta cabeza significa que eres capaz de sobrevivir a los mayores peligros de Canción Eterna... Y créeme, son muchos.', 0),
(@ID, 'esMX', 'La cabeza de Felendren... Acabas de ganarte una mención honorífica, $n. Has tenido éxito donde otros, como el propio Felendren, han fallado miserablemente. Puede que haya llegado el momento de convertirte en miembro de la sociedad de los elfos de sangre.$B$BEsta cabeza significa que eres capaz de sobrevivir a los mayores peligros de Canción Eterna... Y créeme, son muchos.', 0);
-- 8338 Esquirla arcana mácula
-- https://es.classic.wowhead.com/quest=8338
SET @ID := 8338;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por tu actitud, diría que vienes por un asunto de cierta urgencia. ¿Puedo ayudarte en algo?', 0),
(@ID, 'esMX', 'Por tu actitud, diría que vienes por un asunto de cierta urgencia. ¿Puedo ayudarte en algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es muy interesante, y con eso quiero decir que es más inquietante que otra cosa.$B$BRecuperar el control de la isla tras la destrucción de La Fuente del Sol ha sido todo un desafío. Sospecho que lo que sea que está corrompiendo la isla se encuentra en el corazón de la misma; esta esquirla puede ayudarnos a descubrir qué está pasando.$B$BHas hecho muy bien en traérmela, $n. Acepta esto como pago de tu diligencia. Gracias.', 0),
(@ID, 'esMX', 'Esto es muy interesante, y con eso quiero decir que es más inquietante que otra cosa.$B$BRecuperar el control de la isla tras la destrucción de La Fuente del Sol ha sido todo un desafío. Sospecho que lo que sea que está corrompiendo la isla se encuentra en el corazón de la misma; esta esquirla puede ayudarnos a descubrir qué está pasando.$B$BHas hecho muy bien en traérmela, $n. Acepta esto como pago de tu diligencia. Gracias.', 0);
-- 8347 Ayudando a los avanzados
-- https://es.classic.wowhead.com/quest=8347
SET @ID := 8347;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Saludos, $c! Había oído que $gun:una; joven $r que estuvo al servicio de la magistrix Erona iba a venir para echarnos una mano a los avanzados. Agradecemos la ayuda, sobre todo si es de alguien que ha demostrado ser tan competente como tú.$B$BTengo un par de cosas que encargarte.', 0),
(@ID, 'esMX', '¡Saludos, $c! Había oído que $gun:una; joven $r que estuvo al servicio de la magistrix Erona iba a venir para echarnos una mano a los avanzados. Agradecemos la ayuda, sobre todo si es de alguien que ha demostrado ser tan competente como tú.$B$BTengo un par de cosas que encargarte.', 0);
-- 9704 Ejecutados por los desdichados
-- https://es.wowhead.com/quest=9704
SET @ID := 9704;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Robaron todas las pertenencias de la avanzada salvo un paquete. Parece coincidir con la descripción que Alarion dio del paquete de Erona.', 0),
(@ID, 'esMX', 'Robaron todas las pertenencias de la avanzada salvo un paquete. Parece coincidir con la descripción que Alarion dio del paquete de Erona.', 0);
-- 9705 Recuperación de paquete
-- https://es.wowhead.com/quest=9705
SET @ID := 9705;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué has encontrado, $n?', 0),
(@ID, 'esMX', '¿Qué has encontrado, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por La Fuente del Sol! Es el tercer avanzado que perdemos este mes.$B$BAgradezco tu valor al adentrarte en la Calle del Alba. Los guardias necesitan mantener una vigilancia estrecha sobre esos malditos desdichados.', 0),
(@ID, 'esMX', '¡Por La Fuente del Sol! Es el tercer avanzado que perdemos este mes.$B$BAgradezco tu valor al adentrarte en la Calle del Alba. Los guardias necesitan mantener una vigilancia estrecha sobre esos malditos desdichados.', 0);
-- 8350 El encargo
-- https://es.classic.wowhead.com/quest=8350
SET @ID := 8350;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bienvenido a mi posada, $c. ¿Vienes a traerme algo?', 0),
(@ID, 'esMX', 'Bienvenido a mi posada, $c. ¿Vienes a traerme algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por entregar esto tan rápidamente.$B$BPonte $gcómodo:cómoda; mientras estás aquí. Si no lo has hecho ya, coge una piedra de hogar y vincúlate a esta posada. La piedra te permite volver a una posada una vez cada media hora. Si pierdes la piedra, no tienes más que volver a una posada; el tabernero te dará otra piedra de hogar gustosamente.', 0),
(@ID, 'esMX', 'Gracias por entregar esto tan rápidamente.$B$BPonte $gcómodo:cómoda; mientras estás aquí. Si no lo has hecho ya, coge una piedra de hogar y vincúlate a esta posada. La piedra te permite volver a una posada una vez cada media hora. Si pierdes la piedra, no tienes más que volver a una posada; el tabernero te dará otra piedra de hogar gustosamente.', 0);
-- 8472 Avería grave
-- https://es.classic.wowhead.com/quest=8472
SET @ID := 8472;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido reunir los núcleos arcanos, $n?', 0),
(@ID, 'esMX', '¿Has conseguido reunir los núcleos arcanos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Ahora que nuestros sagrarios arcanos solo están activos parcialmente, estos núcleos de poder nos van a ser muy útiles.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Ahora que nuestros sagrarios arcanos solo están activos parcialmente, estos núcleos de poder nos van a ser muy útiles.', 0);
-- 8463 Cristales de maná inestables
-- https://es.classic.wowhead.com/quest=8463
SET @ID := 8463;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes los cristales robados?', 0),
(@ID, 'esMX', '¿Traes los cristales robados?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n.', 0),
(@ID, 'esMX', 'Excelente trabajo, $n.', 0);
-- 8468 Se busca: Thaelis el Hambriento
-- https://es.classic.wowhead.com/quest=8468
SET @ID := 8468;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que enseñarme?', 0),
(@ID, 'esMX', '¿Tienes algo que enseñarme?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El canalla de Thaelis ha recibido su merecido por fin. Buen trabajo, $n. Esperemos que los desdichados estén tranquilitos una temporada.', 0),
(@ID, 'esMX', 'El canalla de Thaelis ha recibido su merecido por fin. Buen trabajo, $n. Esperemos que los desdichados estén tranquilitos una temporada.', 0);
-- 8895 Entrega para el Sagrario del Norte
-- https://es.classic.wowhead.com/quest=8895
SET @ID := 8895;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $c?', 0),
(@ID, 'esMX', '¿Sí, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Esperaba esta carta.', 0),
(@ID, 'esMX', 'Gracias, $n. Esperaba esta carta.', 0);
