-- 2581 Papadas de hiena risitas
-- https://es.classic.wowhead.com/quest=2581
SET @ID := 2581;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Apestas, $n. ¿Has estado por terrenos sulfurosos? ¡¿Y dónde están mis componentes?!', 0),
(@ID, 'esMX', 'Apestas, $n. ¿Has estado por terrenos sulfurosos? ¡¿Y dónde están mis componentes?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo te encuentras, $n? Irradias el aura de la hiena risitas, tu fuerza ¡no tiene parangón entre los mortales!$B$BDesgraciadamente, con los componentes que me trajiste, solo pude hacer suficiente polvo para una pastilla. Necesitaré más componentes si te hiciera falta otra pastilla.', 0),
(@ID, 'esMX', '¿Cómo te encuentras, $n? Irradias el aura de la hiena risitas, tu fuerza ¡no tiene parangón entre los mortales!$B$BDesgraciadamente, con los componentes que me trajiste, solo pude hacer suficiente polvo para una pastilla. Necesitaré más componentes si te hiciera falta otra pastilla.', 0);
-- 2582 Ira de las Eras
-- https://es.classic.wowhead.com/quest=2582
SET @ID := 2582;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los órganos de las bestias?', 0),
(@ID, 'esMX', '¿Tienes los órganos de las bestias?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Aquí tienes! Recuerda, úsala con moderación. Si necesitas más, ven a verme cuando hayas acabado con la que tienes ahora.', 0),
(@ID, 'esMX', '¡Aquí tienes! Recuerda, úsala con moderación. Si necesitas más, ven a verme cuando hayas acabado con la que tienes ahora.', 0);
-- 2583 La vitalidad del jabalí
-- https://es.classic.wowhead.com/quest=2583
SET @ID := 2583;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Dónde están los órganos, $n?!', 0),
(@ID, 'esMX', '¡¿Dónde están los órganos, $n?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El espíritu del jabalí ilumina tu ser, $n! Me pregunto... ¿crees que eres tan invulnerable como estas bestias?', 0),
(@ID, 'esMX', '¡El espíritu del jabalí ilumina tu ser, $n! Me pregunto... ¿crees que eres tan invulnerable como estas bestias?', 0);
-- 2584 El espíritu del jabalí
-- https://es.classic.wowhead.com/quest=2584
SET @ID := 2584;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Dónde están los órganos, $n?!', 0),
(@ID, 'esMX', '¡¿Dónde están los órganos, $n?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debo advertirte, $n, no intentes mezclar las fórmulas que he creado. Las propiedades químicas de la fórmula ingerida en último lugar siempre prevalecen sobre encantamientos anteriores, por lo que se anularían los efectos de las fórmulas precedentes.', 0),
(@ID, 'esMX', 'Debo advertirte, $n, no intentes mezclar las fórmulas que he creado. Las propiedades químicas de la fórmula ingerida en último lugar siempre prevalecen sobre encantamientos anteriores, por lo que se anularían los efectos de las fórmulas precedentes.', 0);
-- 2585 El golpe decisivo
-- https://es.classic.wowhead.com/quest=2585
SET @ID := 2585;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Dónde están los órganos, $n?!', 0),
(@ID, 'esMX', '¡¿Dónde están los órganos, $n?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Fascinante. Este ha sido el polvo más difícil de analizar.$B$BToma esta pizca de sal residual y colócala debajo de tu lengua. Deberías sentir una leve sensación de euforia seguida de un estado de agilidad y velocidad nunca visto.', 0),
(@ID, 'esMX', 'Fascinante. Este ha sido el polvo más difícil de analizar.$B$BToma esta pizca de sal residual y colócala debajo de tu lengua. Deberías sentir una leve sensación de euforia seguida de un estado de agilidad y velocidad nunca visto.', 0);
-- 2586 La sal del Scorpok
-- https://es.classic.wowhead.com/quest=2586
SET @ID := 2586;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Dónde están los órganos, $n?!', 0),
(@ID, 'esMX', '¡¿Dónde están los órganos, $n?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Aquí titnes un poco de polvo de scorpok. El resto lo utilizaré en mi investigación.$B$BSiempre que necesites más polvo de scorpok, vuelve a verme y llegaremos a un acuerdo.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Aquí titnes un poco de polvo de scorpok. El resto lo utilizaré en mi investigación.$B$BSiempre que necesites más polvo de scorpok, vuelve a verme y llegaremos a un acuerdo.', 0);
-- 2601 El bocado de basilisco
-- https://es.classic.wowhead.com/quest=2601
SET @ID := 2601;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Vuelves con los órganos que te pedí?', 0),
(@ID, 'esMX', '¿Vuelves con los órganos que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Maravilloso, $n! Te ofrezco probar las entrañas del basilisco Rocarroja.$B$BSi el compuesto fuera de tu agrado, siempre se puede hacer más... previo pago.', 0),
(@ID, 'esMX', '¡Maravilloso, $n! Te ofrezco probar las entrañas del basilisco Rocarroja.$B$BSi el compuesto fuera de tu agrado, siempre se puede hacer más... previo pago.', 0);
-- 2602 La mente infalible
-- https://es.classic.wowhead.com/quest=2602
SET @ID := 2602;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Vuelves con los órganos que te pedí?', 0),
(@ID, 'esMX', '¿Vuelves con los órganos que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, sí, dame un momento y más compuesto estará listo para tu consumo, $n.$B$BTómalo... y $n, no intentes consumir estos brebajes experimentales muy rápido. Los resultados pueden ser desastrosos.', 0),
(@ID, 'esMX', 'Sí, sí, dame un momento y más compuesto estará listo para tu consumo, $n.$B$BTómalo... y $n, no intentes consumir estos brebajes experimentales muy rápido. Los resultados pueden ser desastrosos.', 0);
-- 2603 El vigor del buitre
-- https://es.classic.wowhead.com/quest=2603
SET @ID := 2603;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me hagas perder el tiempo, $n. No tenemos nada de qué hablar, a menos que hayas recuperado los objetos que te pedí.', 0),
(@ID, 'esMX', 'No me hagas perder el tiempo, $n. No tenemos nada de qué hablar, a menos que hayas recuperado los objetos que te pedí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Soberbio! Me pondré a trabajar de inmediato. ¡Quizás encuentre una cura para muchos de los males que afligen al mundo!$B$BAh, sí, tu recompensa, claro; si te hiciera falta más chicle, vuelve aquí y te asignaré otra tarea.', 0),
(@ID, 'esMX', '¡Soberbio! Me pondré a trabajar de inmediato. ¡Quizás encuentre una cura para muchos de los males que afligen al mundo!$B$BAh, sí, tu recompensa, claro; si te hiciera falta más chicle, vuelve aquí y te asignaré otra tarea.', 0);
-- 2604 Dominación espiritual
-- https://es.classic.wowhead.com/quest=2604
SET @ID := 2604;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me hagas perder el tiempo, $n. No tenemos nada de qué hablar, a menos que hayas recuperado los objetos que te pedí.', 0),
(@ID, 'esMX', 'No me hagas perder el tiempo, $n. No tenemos nada de qué hablar, a menos que hayas recuperado los objetos que te pedí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Quizás algún día pueda aislar las enzimas activas de este ensayo y producir un resultado mucho más eficiente. Desafortunadamente, tendrás que conformarte con lo que actualmente soy capaz de producir. Vuelve a verme si necesitas más chicle de molleja.', 0),
(@ID, 'esMX', 'Quizás algún día pueda aislar las enzimas activas de este ensayo y producir un resultado mucho más eficiente. Desafortunadamente, tendrás que conformarte con lo que actualmente soy capaz de producir. Vuelve a verme si necesitas más chicle de molleja.', 0);
-- 2608 Toque de Zanzil
-- https://es.classic.wowhead.com/quest=2608
SET @ID := 2608;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando estés $glisto:lista; para el examen, acuéstate en el suelo y comenzaré la flebotomía.', 0),
(@ID, 'esMX', 'Cuando estés $glisto:lista; para el examen, acuéstate en el suelo y comenzaré la flebotomía.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dame un momento para hablar con mis colegas, $n. Dr. Montgomery, Sr. Noarm, ¡tengamos una conferencia!', 0),
(@ID, 'esMX', 'Dame un momento para hablar con mis colegas, $n. Dr. Montgomery, Sr. Noarm, ¡tengamos una conferencia!', 0);
-- 2609 Toque de Zanzil
-- https://es.classic.wowhead.com/quest=2609
SET @ID := 2609;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si quieres curar la \'itis\', tendrás que esforzarte más que eso, $n. ¿Dónde están los reactivos para la cura?', 0),
(@ID, 'esMX', 'Si quieres curar la \'itis\', tendrás que esforzarte más que eso, $n. ¿Dónde están los reactivos para la cura?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué estoy haciendo? ¿Qué parece que estoy haciendo? Estoy ideando una cura para tu \'itis\'. ¡No te indignes conmigo ahora, $n!$B$BSolo unos segundos más. ¡Aquí! Sólo rocio esto, ummm, un medicamento con un olor fantástico y estarás como $gnuevo:nueva;.', 0),
(@ID, 'esMX', '¿Qué estoy haciendo? ¿Qué parece que estoy haciendo? Estoy ideando una cura para tu \'itis\'. ¡No te indignes conmigo ahora, $n!$B$BSolo unos segundos más. ¡Aquí! Sólo rocio esto, ummm, un medicamento con un olor fantástico y estarás como $gnuevo:nueva;.', 0);
-- 2621 El deshonrado
-- https://es.classic.wowhead.com/quest=2621
SET @ID := 2621;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La garra de Thrall... El recuerdo aún está vívido en mi memoria.$B$B<El comandante Ruag se sacude la cabeza.>$B$BFue terrible lo que le ocurrió a ese regimiento. La Horda perdió a algunos de sus mejores soldados cuando aniquilaron a ese batallón.', 0),
(@ID, 'esMX', 'La garra de Thrall... El recuerdo aún está vívido en mi memoria.$B$B<El comandante Ruag se sacude la cabeza.>$B$BFue terrible lo que le ocurrió a ese regimiento. La Horda perdió a algunos de sus mejores soldados cuando aniquilaron a ese batallón.', 0);
-- 2622 Las órdenes perdidas
-- https://es.classic.wowhead.com/quest=2622
SET @ID := 2622;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hablador del pan... pant.. pantano...', 0),
(@ID, 'esMX', 'Hablador del pan... pant.. pantano...', 0);
-- 2623 La voz del pantano
-- https://es.classic.wowhead.com/quest=2623
SET @ID := 2623;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A la espera de órdenes.', 0),
(@ID, 'esMX', 'A la espera de órdenes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es aún peor de lo que me imaginaba. Diecinueve de mis hombres podrían haberse ahorrado la agonía que sufrieron. ¡Si yo no hubiera actuado de forma tan irracional!$B$B¡Tienes que ayudarlos, $n! A mí me es imposible.', 0),
(@ID, 'esMX', 'Es aún peor de lo que me imaginaba. Diecinueve de mis hombres podrían haberse ahorrado la agonía que sufrieron. ¡Si yo no hubiera actuado de forma tan irracional!$B$B¡Tienes que ayudarlos, $n! A mí me es imposible.', 0);
-- 2681 Las piedras que nos vinculan
-- https://es.classic.wowhead.com/quest=2681
SET @ID := 2681;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Sirvientes de Razelikh liberados', `ObjectiveText2` = 'Sirvientes de Grol liberados', `ObjectiveText3` = 'Sirvientes de Allistarj liberados', `ObjectiveText4` = 'Sirvientes de Sevine liberados', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No es una tarea fácil, $n. ¡No te rindas!', 0),
(@ID, 'esMX', 'No es una tarea fácil, $n. ¡No te rindas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has logrado, $n! Las pobres almas torturadas al fin descansan en paz.$B$BNuestro trabajo aún no se ha acabado, $n. Tenemos mucho de que hablar y mucho que hacer.', 0),
(@ID, 'esMX', '¡Lo has logrado, $n! Las pobres almas torturadas al fin descansan en paz.$B$BNuestro trabajo aún no se ha acabado, $n. Tenemos mucho de que hablar y mucho que hacer.', 0);
-- 2701 Los héroes de los antiguos
-- https://es.classic.wowhead.com/quest=2701
SET @ID := 2701;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estás cegado temporalmente por las centellas y el brillo.', 0),
(@ID, 'esMX', 'Estás cegado temporalmente por las centellas y el brillo.', 0);
-- 2702 Los héroes de los antiguos
-- https://es.classic.wowhead.com/quest=2702
SET @ID := 2702;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Desde luego, has cumplido con todos nosotros. Mereces algo más que nuestro agradecimiento.', 0),
(@ID, 'esMX', 'Desde luego, has cumplido con todos nosotros. Mereces algo más que nuestro agradecimiento.', 0);
-- 2721 Kirith
-- https://es.classic.wowhead.com/quest=2721
SET @ID := 2721;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Trebor? ¿Te envía Trebor?', 0),
(@ID, 'esMX', '¿Trebor? ¿Te envía Trebor?', 0);
-- 2742 ¡Capturaron a Rin'ji!
-- https://es.classic.wowhead.com/quest=2742
SET @ID := 2742;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Rin\'ji está asustado!', 0),
(@ID, 'esMX', '¡Rin\'ji está asustado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta tablilla debe de ser el secreto del que hablaba Rin\'ji.$B$BTiene unos símbolos extraños que no puedes descifrar.', 0),
(@ID, 'esMX', 'Esta tablilla debe de ser el secreto del que hablaba Rin\'ji.$B$BTiene unos símbolos extraños que no puedes descifrar.', 0);
-- 2743 La cubierta de la Oscuridad
-- https://es.classic.wowhead.com/quest=2743
SET @ID := 2743;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El señor demoníaco hace gala de una astucia tan calculadora como su brutalidad, $n.', 0),
(@ID, 'esMX', 'El señor demoníaco hace gala de una astucia tan calculadora como su brutalidad, $n.', 0);
-- 2744 El cazademonios
-- https://es.classic.wowhead.com/quest=2744
SET @ID := 2744;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué estás haciendo aquí?', 0),
(@ID, 'esMX', '¿Qué estás haciendo aquí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te ayudaré. Aunque, no creo que entiendas completamente a qué te enfrentas.', 0),
(@ID, 'esMX', 'Te ayudaré. Aunque, no creo que entiendas completamente a qué te enfrentas.', 0);
-- 2745 Infíltrate en el castillo
-- https://es.classic.wowhead.com/quest=2745
SET @ID := 2745;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué demo...? ¡No vuelvas a asustarme así! ¡Y baja la voz! En el nombre de las Sombras, ¿por qué demonios has tenido que acercarte tan sigilosamente? ¿No ves que tengo mucho trabajo, imbécil?$B$B¿Qué quieres decir? ¿Que qué estoy haciendo? Estoy esperando a que se abra el próximo Portal Oscuro, ¿qué te parece a ti que estoy haciendo? Di lo que tengas que decir y lárgate de aquí... antes de que los guardias nos vean a los dos aquí escondidos juntos en los matorrales. Tengo una reputación que mantener.', 0),
(@ID, 'esMX', '¿Qué demo...? ¡No vuelvas a asustarme así! ¡Y baja la voz! En el nombre de las Sombras, ¿por qué demonios has tenido que acercarte tan sigilosamente? ¿No ves que tengo mucho trabajo, imbécil?$B$B¿Qué quieres decir? ¿Que qué estoy haciendo? Estoy esperando a que se abra el próximo Portal Oscuro, ¿qué te parece a ti que estoy haciendo? Di lo que tengas que decir y lárgate de aquí... antes de que los guardias nos vean a los dos aquí escondidos juntos en los matorrales. Tengo una reputación que mantener.', 0);
-- 2746 Objetos importantes
-- https://es.classic.wowhead.com/quest=2746
SET @ID := 2746;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Llevo un par de semanas vigilando a Lescovar. Trias nunca ha confiado en él, pero nosotros no sospechábamos que estaba involucrado con la Hermandad Defias. De hecho, pensábamos que tenía algo que ver con el Martillo Crepuscular. De cualquier forma, se ha vuelto tan peligroso que esta ciudad ya no puede contenerle, y ahí es donde entramos nosotros.$B$BConsígueme esos objetos y podremos poner en marcha mi plan.', 0),
(@ID, 'esMX', 'Llevo un par de semanas vigilando a Lescovar. Trias nunca ha confiado en él, pero nosotros no sospechábamos que estaba involucrado con la Hermandad Defias. De hecho, pensábamos que tenía algo que ver con el Martillo Crepuscular. De cualquier forma, se ha vuelto tan peligroso que esta ciudad ya no puede contenerle, y ahí es donde entramos nosotros.$B$BConsígueme esos objetos y podremos poner en marcha mi plan.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto será perfecto, $n. Buen trabajo.$B$BTengo lo demás que necesito en mi talega... gracias a la Luz que conozco a un sastre, para que me haga una bolsa de seda. Me estaba quedando sin espacio por tener que cargar con todas mis cosas de un lado para otro.$B$BPero antes de que aparezca el robot espía, hablemos de los detalles para que sepas lo que tienes que hacer.', 0),
(@ID, 'esMX', 'Esto será perfecto, $n. Buen trabajo.$B$BTengo lo demás que necesito en mi talega... gracias a la Luz que conozco a un sastre, para que me haga una bolsa de seda. Me estaba quedando sin espacio por tener que cargar con todas mis cosas de un lado para otro.$B$BPero antes de que aparezca el robot espía, hablemos de los detalles para que sepas lo que tienes que hacer.', 0);
-- 2751 Almenas barbáricas
-- https://es.classic.wowhead.com/quest=2751
SET @ID := 2751;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bronce, $n! ¡¡Más bronce!!', 0),
(@ID, 'esMX', '¡Bronce, $n! ¡¡Más bronce!!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La línea de sangre se desvanecerá, ¡pero quizás la leyenda de Omosh continúe!$B$BHas probado que eres $gherrero:herrera;, $n. ¡Para el herrero la recompensa es la satisfacción de ver sus armas y armaduras cubiertas con la sangre de sus enemigos!$B$B¡Que los petos que crees para las generaciones venideras se empapen con la sangre de tus enemigos!', 0),
(@ID, 'esMX', 'La línea de sangre se desvanecerá, ¡pero quizás la leyenda de Omosh continúe!$B$BHas probado que eres $gherrero:herrera;, $n. ¡Para el herrero la recompensa es la satisfacción de ver sus armas y armaduras cubiertas con la sangre de sus enemigos!$B$B¡Que los petos que crees para las generaciones venideras se empapen con la sangre de tus enemigos!', 0);
-- 2752 Espaldares de hierro
-- https://es.classic.wowhead.com/quest=2752
SET @ID := 2752;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muéstrame tu dedicación, $r.', 0),
(@ID, 'esMX', 'Muéstrame tu dedicación, $r.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estás orgulloso de Orokk, $n. ¡Lee, aprende las hombreras de hierro!', 0),
(@ID, 'esMX', 'Estás orgulloso de Orokk, $n. ¡Lee, aprende las hombreras de hierro!', 0);
-- 2753 ¡Aplástalos!
-- https://es.classic.wowhead.com/quest=2753
SET @ID := 2753;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Sus cráneos se romperán bajo el peso de tus botas!', 0),
(@ID, 'esMX', '¡Sus cráneos se romperán bajo el peso de tus botas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Le recuerdas a Orokk a su abuelo, el Jefe Gorokk de Omosh! Lee, aprende la bota de hierro.', 0),
(@ID, 'esMX', '¡Le recuerdas a Orokk a su abuelo, el Jefe Gorokk de Omosh! Lee, aprende la bota de hierro.', 0);
-- 2754 Cuernos de frenesí
-- https://es.classic.wowhead.com/quest=2754
SET @ID := 2754;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muéstrale al hierro quién manda, $n!', 0),
(@ID, 'esMX', '¡Muéstrale al hierro quién manda, $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Asombroso! ¡Has aprendido el camino de Omosh, $n!', 0),
(@ID, 'esMX', '¡Asombroso! ¡Has aprendido el camino de Omosh, $n!', 0);
-- 2755 Las alegrías de los Omosh
-- https://es.classic.wowhead.com/quest=2755
SET @ID := 2755;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Pantalones Orokk.>$B$BHa pasado mucho tiempo desde que Orokk hizo la danza de la alegría Omosh. ¡Aprende ahora, $n!', 0),
(@ID, 'esMX', '<Pantalones Orokk.>$B$BHa pasado mucho tiempo desde que Orokk hizo la danza de la alegría Omosh. ¡Aprende ahora, $n!', 0);
-- 2756 Los viejos hábitos
-- https://es.classic.wowhead.com/quest=2756
SET @ID := 2756;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Aturk, como el tiempo, no espera a nadie! ¡Date prisa, $gtonto:tonta;!', 0),
(@ID, 'esMX', '¡Aturk, como el tiempo, no espera a nadie! ¡Date prisa, $gtonto:tonta;!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que no eres más que otro lemming complaciente del Jefe de Guerra, $n. Que decepcionante.$B$BCuánto anhelo una muerte gloriosa en el campo de batalla. En cambio, estoy atrapado aquí, por orden de Thrall, ¡para enseñar a los bebés cómo hacer manualidades! ¡Mira y aprende, $gniño:niña;!', 0),
(@ID, 'esMX', 'Parece que no eres más que otro lemming complaciente del Jefe de Guerra, $n. Que decepcionante.$B$BCuánto anhelo una muerte gloriosa en el campo de batalla. En cambio, estoy atrapado aquí, por orden de Thrall, ¡para enseñar a los bebés cómo hacer manualidades! ¡Mira y aprende, $gniño:niña;!', 0);
-- 2757 ¡Bahía del Botín o nada!
-- https://es.classic.wowhead.com/quest=2757
SET @ID := 2757;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una raza rara tu especie, $gamigo:amiga;. Déjame ver esa insignia.', 0),
(@ID, 'esMX', 'Una raza rara tu especie, $gamigo:amiga;. Déjame ver esa insignia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por el pelo de la espalda de Pezuña Negra, ¡finalmente, $guno digno:una digna; de la Orden de Mithril!', 0),
(@ID, 'esMX', 'Por el pelo de la espalda de Pezuña Negra, ¡finalmente, $guno digno:una digna; de la Orden de Mithril!', 0);
