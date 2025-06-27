-- 10336 Los esbirros de Culuthas
-- https://es.wowhead.com/quest=10336
SET @ID := 10336;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has matado a todos los demonios en las Ruinas de Farahlon?', 0),
(@ID, 'esMX', '¿Has matado a todos los demonios en las Ruinas de Farahlon?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo impresionante.$B$BCon la muerte de los demonios de Culuthas, Zephyrion podrá llevar tranquilamente a su equipo de excavación a las Ruinas de Farahlon.$B$BAcepta esta moneda como muestra de mi agradecimiento.', 0),
(@ID, 'esMX', 'Un trabajo impresionante.$B$BCon la muerte de los demonios de Culuthas, Zephyrion podrá llevar tranquilamente a su equipo de excavación a las Ruinas de Farahlon.$B$BAcepta esta moneda como muestra de mi agradecimiento.', 0);
-- 10337 Cuando las vacas vuelven a casa
-- https://es.wowhead.com/quest=10337
SET @ID := 10337;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Bessy, eres tú?$B$B<El granjero te mira.>$B$BGracias por devolverme a mi Bessy, $n. ¡No podría vivir sin ella!', 0),
(@ID, 'esMX', '¿Bessy, eres tú?$B$B<El granjero te mira.>$B$BGracias por devolverme a mi Bessy, $n. ¡No podría vivir sin ella!', 0);
-- 10338 El cierre de la Forja de Maná Duro
-- https://es.wowhead.com/quest=10338
SET @ID := 10338;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Forja de Maná Duro cerrada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cerraste la forja de maná? Date prisa, no sea que cambie de idea.', 0),
(@ID, 'esMX', '¿Cerraste la forja de maná? Date prisa, no sea que cambie de idea.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya son tres las forjas de maná que has desactivado $n. Kael\'thas debe de estar empezando a temblar en estos momentos.', 0),
(@ID, 'esMX', 'Ya son tres las forjas de maná que has desactivado $n. Kael\'thas debe de estar empezando a temblar en estos momentos.', 0);
-- 10339 El Etereum
-- https://es.wowhead.com/quest=10339
SET @ID := 10339;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, carnal...', 0),
(@ID, 'esMX', 'Bien hecho, carnal...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debemos conseguir todos los datos que tengan en esta zona.', 0),
(@ID, 'esMX', 'Debemos conseguir todos los datos que tengan en esta zona.', 0);
-- 10340 Puesto Devastación
-- https://es.wowhead.com/quest=10340
SET @ID := 10340;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, $gun:una; $r del continente! No te preocupes; ¡Puesto Devastación te puede marear un poco, pero nunca se aleja demasiado!$B$BY solo se ha volcado una vez... O dos.', 0),
(@ID, 'esMX', '¡Vaya, $gun:una; $r del continente! No te preocupes; ¡Puesto Devastación te puede marear un poco, pero nunca se aleja demasiado!$B$BY solo se ha volcado una vez... O dos.', 0);
-- 10341 A por ellos cuando no se pueden defender
-- https://es.wowhead.com/quest=10341
SET @ID := 10341;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado tu tarea, $n?', 0),
(@ID, 'esMX', '¿Has completado tu tarea, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien, $n. El ejército de Kael no se recuperará fácilmente del golpe que les has asestado hoy.', 0),
(@ID, 'esMX', 'Lo has hecho bien, $n. El ejército de Kael no se recuperará fácilmente del golpe que les has asestado hoy.', 0);
-- 10342 Asegurar los esquistos Piel de esquisto
-- https://es.wowhead.com/quest=10342
SET @ID := 10342;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido ya el esquisto? Voy a necesitar mucho para extraer la cantidad de aceite necesaria para el combustible del Cohete abisal X-52.', 0),
(@ID, 'esMX', '¿Has conseguido ya el esquisto? Voy a necesitar mucho para extraer la cantidad de aceite necesaria para el combustible del Cohete abisal X-52.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eso es! Ya tenemos el primer ingrediente.$B$BAhora, si te apetece, pasaremos a algo que le dará al petróleo de esquisto ese puntito extra que lanzará a toda máquina el cohete abisal hacia El Vacío Abisal... o hacia el olvido, lo que primero se encuentre.', 0),
(@ID, 'esMX', '¡Eso es! Ya tenemos el primer ingrediente.$B$BAhora, si te apetece, pasaremos a algo que le dará al petróleo de esquisto ese puntito extra que lanzará a toda máquina el cohete abisal hacia El Vacío Abisal... o hacia el olvido, lo que primero se encuentre.', 0);
-- 10343 La invasión interminable
-- https://es.wowhead.com/quest=10343
SET @ID := 10343;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido los restos del arma utilizada por Kael\'thas contra el poblado?', 0),
(@ID, 'esMX', '¿Has conseguido los restos del arma utilizada por Kael\'thas contra el poblado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Una bomba de maná?$B$B<Morran observa el fragmento en sus manos.>$B$B¡Es increíble! Ni siquiera las mejores mentes de Dalaran podrían haber ideado un arma así. La inmensa magnitud de la alteración debe haber creado una falla en El Vacío Abisal, dando acceso a esas criaturas a nuestra tierra.', 0),
(@ID, 'esMX', '¿Una bomba de maná?$B$B<Morran observa el fragmento en sus manos.>$B$B¡Es increíble! Ni siquiera las mejores mentes de Dalaran podrían haber ideado un arma así. La inmensa magnitud de la alteración debe haber creado una falla en El Vacío Abisal, dando acceso a esas criaturas a nuestra tierra.', 0);
-- 10344 Comandante del aire Grifongar
-- https://es.wowhead.com/quest=10344
SET @ID := 10344;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has hablado con Runetog? Es un buen enano. Mantiene a sus grifos en buena forma y listos para el combate.$B$BSoy Grifongar, comandante del Puesto Devastación. Sé que no es muy bonita, pero esta roca es un punto estratégico vital en la Península del Fuego Infernal. Verás grifos volando por aquí sin parar.$B$B¿Un consejo? Mantén tu equipamiento equipado, tu estómago vacío y tus ojos en el horizonte. Si el Puesto Devastación comienza a tambalearse, ¡sujétate a algo que no se vaya flotando!', 0),
(@ID, 'esMX', '¿Has hablado con Runetog? Es un buen enano. Mantiene a sus grifos en buena forma y listos para el combate.$B$BSoy Grifongar, comandante del Puesto Devastación. Sé que no es muy bonita, pero esta roca es un punto estratégico vital en la Península del Fuego Infernal. Verás grifos volando por aquí sin parar.$B$B¿Un consejo? Mantén tu equipamiento equipado, tu estómago vacío y tus ojos en el horizonte. Si el Puesto Devastación comienza a tambalearse, ¡sujétate a algo que no se vaya flotando!', 0);
-- 10345 La carne sí engaña
-- https://es.wowhead.com/quest=10345
SET @ID := 10345;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Cadáveres marchitos quemados', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Calcinaste los cadáveres?', 0),
(@ID, 'esMX', '¿Calcinaste los cadáveres?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me has salvado el pellejo, $n. El Protectorado sabrá de tu excelente acción, $gamigo mío:amiga mía;.', 0),
(@ID, 'esMX', 'Me has salvado el pellejo, $n. El Protectorado sabrá de tu excelente acción, $gamigo mío:amiga mía;.', 0);
-- 10346 Regresa a La Plataforma Abisal
-- https://es.wowhead.com/quest=10346
SET @ID := 10346;
UPDATE `quest_template_locale` SET `ObjectiveText3` = 'Cañón vil destruido', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sigue habiendo muchos objetivos en la Plataforma Abisal, $n. Agarra un grifo cuando estés preparado para volver.', 0),
(@ID, 'esMX', 'Sigue habiendo muchos objetivos en la Plataforma Abisal, $n. Agarra un grifo cuando estés preparado para volver.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo ha ido por ahí fuera esta vez? Estás en bastante buena forma... ¡quizás lo suficientemente buena para volver otra vez!', 0),
(@ID, 'esMX', '¿Cómo ha ido por ahí fuera esta vez? Estás en bastante buena forma... ¡quizás lo suficientemente buena para volver otra vez!', 0);
-- 10347 Regresa a La Plataforma Abisal
-- https://es.wowhead.com/quest=10347
SET @ID := 10347;
UPDATE `quest_template_locale` SET `ObjectiveText3` = 'Cañón vil destruido', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La Legión no debe pensar que está segura en lo alto de la Plataforma Abisal. ¡Debemos atacar repetidamente!', 0),
(@ID, 'esMX', 'La Legión no debe pensar que está segura en lo alto de la Plataforma Abisal. ¡Debemos atacar repetidamente!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los otros jinetes del viento hablan muy bien de ti, $n. Has conseguido unas cuantas muertes en la Plataforma Abisal. ¡Sigue trabajando así!', 0),
(@ID, 'esMX', 'Los otros jinetes del viento hablan muy bien de ti, $n. Has conseguido unas cuantas muertes en la Plataforma Abisal. ¡Sigue trabajando así!', 0);
-- 10348 Nuevas oportunidades
-- https://es.wowhead.com/quest=10348
SET @ID := 10348;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido las hierbas?', 0),
(@ID, 'esMX', '¿Has conseguido las hierbas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Interesante elección, ¿no crees? Las propiedades de sanación tenían que ser milagrosas. Cobro bastante dinero por una flor de aspecto bastante común.', 0),
(@ID, 'esMX', 'Interesante elección, ¿no crees? Las propiedades de sanación tenían que ser milagrosas. Cobro bastante dinero por una flor de aspecto bastante común.', 0);
-- 10349 La Vinculadora terrestre
-- https://es.wowhead.com/quest=10349
SET @ID := 10349;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Es una pieza del fragmento de cristal gigantesco de la Cresta Cielo Estrellado?', 0),
(@ID, 'esMX', '¿Es una pieza del fragmento de cristal gigantesco de la Cresta Cielo Estrellado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, fantástico!$B$BLlevo mucho tiempo esperando conseguirlo, pero Tola\'thion no hace nada. Se supone que debería estar ahí fuera ayudándome a investigar lo que está pasando en la Cresta Cielo Estrellado. En lugar de eso, no hace que mandarme forasteros como tú, no te ofendas.$B$BSi me das el cristal, quizás pueda encontrar el vínculo entre él y los colosos.', 0),
(@ID, 'esMX', '¡Oh, fantástico!$B$BLlevo mucho tiempo esperando conseguirlo, pero Tola\'thion no hace nada. Se supone que debería estar ahí fuera ayudándome a investigar lo que está pasando en la Cresta Cielo Estrellado. En lugar de eso, no hace que mandarme forasteros como tú, no te ofendas.$B$BSi me das el cristal, quizás pueda encontrar el vínculo entre él y los colosos.', 0);
-- 10350 Maestro Behomat
-- https://es.wowhead.com/quest=10350
SET @ID := 10350;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, finalmente has venido. Soy Behomat y te instruiré en las formas de las artes $gdel:de la; $C. Ruada me habló de tu juicio contra el devastador y estoy impresionado. Y tengo un regalo para ti.$B$BLo que hemos rescatado de los restos del Exodar es poco y debemos darlo a los más capaces. Coge un arma que se adapte a tu estilo de lucha y llévala con el conocimiento que te has ganado.$B$BY hablando de estilos de lucha, es hora de que aprendas algo nuevo.', 0),
(@ID, 'esMX', 'Ah, finalmente has venido. Soy Behomat y te instruiré en las formas de las artes $gdel:de la; $C. Ruada me habló de tu juicio contra el devastador y estoy impresionado. Y tengo un regalo para ti.$B$BLo que hemos rescatado de los restos del Exodar es poco y debemos darlo a los más capaces. Coge un arma que se adapte a tu estilo de lucha y llévala con el conocimiento que te has ganado.$B$BY hablando de estilos de lucha, es hora de que aprendas algo nuevo.', 0);
-- 10351 Remedios naturales
-- https://es.wowhead.com/quest=10351
SET @ID := 10351;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Cresta Cielo Estrellado revitalizada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Funcionó? ¿Qué has averiguado? ¿Has descubierto qué o quién está detrás de lo ocurrido en la Cresta Cielo Estrellado?', 0),
(@ID, 'esMX', '¿Funcionó? ¿Qué has averiguado? ¿Has descubierto qué o quién está detrás de lo ocurrido en la Cresta Cielo Estrellado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Goliathon? ¿Pathaleon el Calculador?$B$B¿¡KAEL\'THAS!?$B$B¿Tiene algo que ver el príncipe Kael\'thas en esto?$B$B<La vinculadora terrestre se enfurece.>$B$B¡Qué locura ha hecho! ¡Dejar caer cristales gigantes del cielo y diezmar la tierra solo puede ser obra de un loco!$B$BTe puedo asegurar que la Expedición Cenarion les hará frente si intentan volver a hacerlo.$B$BEstamos en deuda contigo, $n.', 0),
(@ID, 'esMX', '¿Goliathon? ¿Pathaleon el Calculador?$B$B¿¡KAEL\'THAS!?$B$B¿Tiene algo que ver el príncipe Kael\'thas en esto?$B$B<La vinculadora terrestre se enfurece.>$B$B¡Qué locura ha hecho! ¡Dejar caer cristales gigantes del cielo y diezmar la tierra solo puede ser obra de un loco!$B$BTe puedo asegurar que la Expedición Cenarion les hará frente si intentan volver a hacerlo.$B$BEstamos en deuda contigo, $n.', 0);
-- 10353 Arconus el Insaciable
-- https://es.wowhead.com/quest=10353
SET @ID := 10353;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estado, carnal? ¿Cuál es tu estado?', 0),
(@ID, 'esMX', '¿Estado, carnal? ¿Cuál es tu estado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Y Ya-six? ¿Lo consiguió?$B$BEsperemos que sí. No conseguí enviarles refuerzos... El Etereum tiene toda la zona cubierta.$B$BPerdona, casi me olvido de lo de tu recompensa.', 0),
(@ID, 'esMX', '¿Y Ya-six? ¿Lo consiguió?$B$BEsperemos que sí. No conseguí enviarles refuerzos... El Etereum tiene toda la zona cubierta.$B$BPerdona, casi me olvido de lo de tu recompensa.', 0);
-- 10355 Carne marchita
-- https://es.wowhead.com/quest=10355
SET @ID := 10355;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes las muestras?', 0),
(@ID, 'esMX', '¿Traes las muestras?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Ruam examina las muestras, el semblante afligido.>$B$BEs justo lo que me temía, $n. El entorno cada vez más seco se está cobrando un alto precio sobre las criaturas que no están hechas para vivir fuera de un medio pantanoso. Habrá que seguir vigilando el área y tratar el asunto con la Expedición Cenarion para ver si se puede hacer algo.', 0),
(@ID, 'esMX', '<Ruam examina las muestras, el semblante afligido.>$B$BEs justo lo que me temía, $n. El entorno cada vez más seco se está cobrando un alto precio sobre las criaturas que no están hechas para vivir fuera de un medio pantanoso. Habrá que seguir vigilando el área y tratar el asunto con la Expedición Cenarion para ver si se puede hacer algo.', 0);
-- 10365 El cierre de la Forja de Maná Ara
-- https://es.wowhead.com/quest=10365
SET @ID := 10365;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Forja de Maná Ara cerrada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado la tarea que te encargué, $n?', 0),
(@ID, 'esMX', '¿Has completado la tarea que te encargué, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿La Legión Ardiente está confabulada con Kael? ¡Ja! A Voren\'thal le va a encantar esa información.$B$B¿Crees que los miles de peregrinos que han venido desde Azeroth quieren estar aliados con la Legión Ardiente? ¡Yo creo que no!', 0),
(@ID, 'esMX', '¿La Legión Ardiente está confabulada con Kael? ¡Ja! A Voren\'thal le va a encantar esa información.$B$B¿Crees que los miles de peregrinos que han venido desde Azeroth quieren estar aliados con la Legión Ardiente? ¡Yo creo que no!', 0);
-- 10366 Jol
-- https://es.wowhead.com/quest=10366
SET @ID := 10366;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$N, te estaba esperando.$B$BTullas ha cantado tus alabanzas y estoy ansiosa por continuar tu entrenamiento en el camino de la Luz. Cuando estés $glisto:lista; para desbloquear una mayor comprensión de tus habilidades y poder, te guiaré.', 0),
(@ID, 'esMX', '$N, te estaba esperando.$B$BTullas ha cantado tus alabanzas y estoy ansiosa por continuar tu entrenamiento en el camino de la Luz. Cuando estés $glisto:lista; para desbloquear una mayor comprensión de tus habilidades y poder, te guiaré.', 0);
-- 10367 Un traidor entre nosotros
-- https://es.wowhead.com/quest=10367
SET @ID := 10367;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste la llave, $n?', 0),
(@ID, 'esMX', '¿Conseguiste la llave, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Pronto mi pueblo será libre gracias a ti.', 0),
(@ID, 'esMX', 'Gracias, $n. Pronto mi pueblo será libre gracias a ti.', 0);
-- 10368 Los ancianos Zarrapucha
-- https://es.wowhead.com/quest=10368
SET @ID := 10368;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Morod liberado', `ObjectiveText2` = 'Akoru liberado', `ObjectiveText3` = 'Aylaan liberado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, $n. ¿Has liberado a los ancianos Zarrapucha?', 0),
(@ID, 'esMX', 'Dime, $n. ¿Has liberado a los ancianos Zarrapucha?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ya puedo sentirlo, $n! Los espíritus están volviendo a nosotros.', 0),
(@ID, 'esMX', '¡Ya puedo sentirlo, $n! Los espíritus están volviendo a nosotros.', 0);
-- 10369 La desaparición de Arzeth
-- https://es.wowhead.com/quest=10369
SET @ID := 10369;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo has hecho, $n? ¿Ha muerto Arzeth?', 0),
(@ID, 'esMX', '¿Lo has hecho, $n? ¿Ha muerto Arzeth?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es cierto, $n. En otros tiempos yo era Naladu el Vigilante de la Tierra.$B$BFui yo quien traicionó a los demás ancianos Zarrapucha a cambio de promesas de poder vacías. Ahora puedes despreciarme si lo deseas. Lo que importa es que mi tribu vuelve a ser libre y que los espíritus han vuelto con nosotros.$B$BNo volveré junto a mi tribu pero al menos puedo morir en paz. Que el espíritu de la tierra encuentre un nuevo servidor entre mis hermanos.', 0),
(@ID, 'esMX', 'Es cierto, $n. En otros tiempos yo era Naladu el Vigilante de la Tierra.$B$BFui yo quien traicionó a los demás ancianos Zarrapucha a cambio de promesas de poder vacías. Ahora puedes despreciarme si lo deseas. Lo que importa es que mi tribu vuelve a ser libre y que los espíritus han vuelto con nosotros.$B$BNo volveré junto a mi tribu pero al menos puedo morir en paz. Que el espíritu de la tierra encuentre un nuevo servidor entre mis hermanos.', 0);
-- 10371 Yorus Cebadiz
-- https://es.tbc.wowhead.com/quest=10371
SET @ID := 10371;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja! Así que oíste hablar de mi desafío, ¿verdad?$B$BBien, siéntate y escucha. Toma un trago y saboréalo... puede ser lo último que bebas.', 0),
(@ID, 'esMX', '¡Ja! Así que oíste hablar de mi desafío, ¿verdad?$B$BBien, siéntate y escucha. Toma un trago y saboréalo... puede ser lo último que bebas.', 0);
-- 10372 Una investigación discreta
-- https://es.wowhead.com/quest=10372
SET @ID := 10372;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Empezaba a preguntarme si Zelanis recibió esa carta.$B$BBien. Pongámonos a trabajar.', 0),
(@ID, 'esMX', 'Empezaba a preguntarme si Zelanis recibió esa carta.$B$BBien. Pongámonos a trabajar.', 0);
-- 10380 Un oscuro pacto
-- https://es.wowhead.com/quest=10380
SET @ID := 10380;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido éxito en tu tarea, $N?', 0),
(@ID, 'esMX', '¿Has tenido éxito en tu tarea, $N?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que está hecho. Venimos aquí, les damos caza y los matamos conforme lo ordenan nuestros maestros. Es un trabajo sin cuartel.$B$BA veces no puedes evitar hacerte alguna pregunta.', 0),
(@ID, 'esMX', 'Así que está hecho. Venimos aquí, les damos caza y los matamos conforme lo ordenan nuestros maestros. Es un trabajo sin cuartel.$B$BA veces no puedes evitar hacerte alguna pregunta.', 0);
-- 10381 Se acabaron los Aldor
-- https://es.wowhead.com/quest=10381
SET @ID := 10381;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La mala noticia que traes llena mi corazón de pesadumbre. Dos de nuestros enemigos más letales se han unido y uno de los hijos más queridos de Shattrath se ha descarriado.', 0),
(@ID, 'esMX', 'La mala noticia que traes llena mi corazón de pesadumbre. Dos de nuestros enemigos más letales se han unido y uno de los hijos más queridos de Shattrath se ha descarriado.', 0);
-- 10382 ¡Ve al frente!
-- https://es.wowhead.com/quest=10382
SET @ID := 10382;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c. ¡Me alegro de que ese enano gruñón por fin se haya dignado enviar algo de ayuda!', 0),
(@ID, 'esMX', 'Saludos, $c. ¡Me alegro de que ese enano gruñón por fin se haya dignado enviar algo de ayuda!', 0);
-- 10384 Datos de El Etereum
-- https://es.wowhead.com/quest=10384
SET @ID := 10384;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has recuperado la célula de datos?', 0),
(@ID, 'esMX', '¿Has recuperado la célula de datos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Acercas la célula de datos para que Ameer pueda leer los planes.>$B$BNada... ¡Malditos sean! ¡Son listos pero no tanto como Ameer!$B$BEstoy a punto de pedirte algo bastante peligroso. Lo entenderé si no quieres seguir, ser de carne.', 0),
(@ID, 'esMX', '<Acercas la célula de datos para que Ameer pueda leer los planes.>$B$BNada... ¡Malditos sean! ¡Son listos pero no tanto como Ameer!$B$BEstoy a punto de pedirte algo bastante peligroso. Lo entenderé si no quieres seguir, ser de carne.', 0);
-- 10385 Potencial de daño cerebral = Alto
-- https://es.wowhead.com/quest=10385
SET @ID := 10385;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has recuperado los datos del repetidor?', 0),
(@ID, 'esMX', '¿Has recuperado los datos del repetidor?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La razón de la existencia del Protectorado está ahora completamente realizada.$B$B¡El Etereum no están aquí para cazar a Dimensius! ¡Están aquí para convertirse en vacío!$B$BManipulan la energía de vacío de esta forja de maná para vincular su propia energía a una criatura conocida como un acechador del Nexo.$B$BSeguro que usan un protoacelerador para completar la transformación.', 0),
(@ID, 'esMX', 'La razón de la existencia del Protectorado está ahora completamente realizada.$B$B¡El Etereum no están aquí para cazar a Dimensius! ¡Están aquí para convertirse en vacío!$B$BManipulan la energía de vacío de esta forja de maná para vincular su propia energía a una criatura conocida como un acechador del Nexo.$B$BSeguro que usan un protoacelerador para completar la transformación.', 0);
-- 10388 Regresa a Thrallmar
-- https://es.wowhead.com/quest=10388
SET @ID := 10388;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n, ¡has llegado justo a tiempo! Nuestros exploradores han descubierto que las posiciones de la Legión en la colina de ahí atrás en realidad son \'campamentos de forja\'. Allí es donde los demonios fabrican sus atracadores viles infernales. Si nos movemos con rapidez contra ellos, ¡podremos interrumpir su producción!', 0),
(@ID, 'esMX', 'Ah, $n, ¡has llegado justo a tiempo! Nuestros exploradores han descubierto que las posiciones de la Legión en la colina de ahí atrás en realidad son \'campamentos de forja\'. Allí es donde los demonios fabrican sus atracadores viles infernales. Si nos movemos con rapidez contra ellos, ¡podremos interrumpir su producción!', 0);
