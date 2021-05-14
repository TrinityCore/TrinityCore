-- 9635 ¡El extractor de motas Zapacelerador!
-- https://es.wowhead.com/quest=9635
SET @ID := 9635;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes ya esas piezas? Me espera algo de buceo.', 0),
(@ID, 'esMX', '¿Tienes ya esas piezas? Me espera algo de buceo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bueno! Ahora si tuviéramos un bucle elástico, una abrazadera de pergamino, un tubo que aspire y un lazo de lona adhesiva. ¡Entonces sí que podríamos fabricar algo!$B$BVale, vale, supongo que te has ganado esto, $n. ¡Que te diviertas!', 0),
(@ID, 'esMX', '¡Bueno! Ahora si tuviéramos un bucle elástico, una abrazadera de pergamino, un tubo que aspire y un lazo de lona adhesiva. ¡Entonces sí que podríamos fabricar algo!$B$BVale, vale, supongo que te has ganado esto, $n. ¡Que te diviertas!', 0);
-- 9636 ¡El extractor de motas Zapacelerador!
-- https://es.wowhead.com/quest=9636
SET @ID := 9636;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya tienes esas partes? ¡Tengo que arreglar una bobina de compresión antes de que Anacoreta Ahuurn comience a respirarme en el cuello!', 0),
(@ID, 'esMX', '¿Ya tienes esas partes? ¡Tengo que arreglar una bobina de compresión antes de que Anacoreta Ahuurn comience a respirarme en el cuello!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Brillante! Y realmente... ¿qué ingeniero tiene suficientes piezas de repuesto por ahí? Ooh, ¿quizás podría vender el extra y comprarme un poco de ese helado de fresa de Tigule y Foror? ¡Me encantan las fresas! ¿Crees que tienen alguno por aquí?$B$BVale, vale, supongo que te lo has ganado, $n. ¡A divertirse!', 0),
(@ID, 'esMX', '¡Brillante! Y realmente... ¿qué ingeniero tiene suficientes piezas de repuesto por ahí? Ooh, ¿quizás podría vender el extra y comprarme un poco de ese helado de fresa de Tigule y Foror? ¡Me encantan las fresas! ¿Crees que tienen alguno por aquí?$B$BVale, vale, supongo que te lo has ganado, $n. ¡A divertirse!', 0);
-- 9637 La petición de Kalynna
-- https://es.wowhead.com/quest=9637
SET @ID := 9637;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has obtenido los tomos que busco, $n?', 0),
(@ID, 'esMX', '¿Has obtenido los tomos que busco, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, $n. He deseado estos libros durante mucho tiempo. Es una suerte que pudiéramos ayudarnos mutuamente.', 0),
(@ID, 'esMX', 'Excelente, $n. He deseado estos libros durante mucho tiempo. Es una suerte que pudiéramos ayudarnos mutuamente.', 0);
-- 9638 En buenas manos
-- https://es.wowhead.com/quest=9638
SET @ID := 9638;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Acaso no ves que estoy ocupado? ¿Qué quieres?', 0),
(@ID, 'esMX', '¿Acaso no ves que estoy ocupado? ¿Qué quieres?', 0);
-- 9639 Kamsis
-- https://es.wowhead.com/quest=9639
SET @ID := 9639;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El diario del que hablas... me enviaron a buscarlo, ¿verdad?', 0),
(@ID, 'esMX', 'El diario del que hablas... me enviaron a buscarlo, ¿verdad?', 0);
-- 9640 La sombra de Aran
-- https://es.wowhead.com/quest=9640
SET @ID := 9640;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No buscabas un diario o algo así?', 0),
(@ID, 'esMX', '¿No buscabas un diario o algo así?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado lo que buscabas? Porque buscabas algo ¿no?', 0),
(@ID, 'esMX', '¿Has encontrado lo que buscabas? Porque buscabas algo ¿no?', 0);
-- 9641 Fragmentos de cristal irradiado
-- https://es.wowhead.com/quest=9641
SET @ID := 9641;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has reunido los fragmentos de cristal de las criaturas de Bruma de sangre?', 0),
(@ID, 'esMX', '¿Has reunido los fragmentos de cristal de las criaturas de Bruma de sangre?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien. Con estos tenemos la materia prima para otro lote de cristales de mejora.$B$BElige uno de los tres cristales que puedo hacer. Me parece que cada uno es idóneo para acechar diferentes tipos de presa.', 0),
(@ID, 'esMX', 'Muy bien. Con estos tenemos la materia prima para otro lote de cristales de mejora.$B$BElige uno de los tres cristales que puedo hacer. Me parece que cada uno es idóneo para acechar diferentes tipos de presa.', 0);
-- 9642 Más fragmentos de cristal irradiado
-- https://es.wowhead.com/quest=9642
SET @ID := 9642;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si tienes más fragmentos de cristal irradiado, con mucho gusto te los cambiaré por uno de mis cristales.', 0),
(@ID, 'esMX', 'Si tienes más fragmentos de cristal irradiado, con mucho gusto te los cambiaré por uno de mis cristales.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, aquí están los cristales que tengo, $n. Úsalos bien.', 0),
(@ID, 'esMX', 'Muy bien, aquí están los cristales que tengo, $n. Úsalos bien.', 0);
-- 9643 Parras constrictoras
-- https://es.wowhead.com/quest=9643
SET @ID := 9643;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido las parras constrictoras?', 0),
(@ID, 'esMX', '¿Has conseguido las parras constrictoras?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parecen lo suficientemente resistentes. Gracias por tu ayuda, $n. Tu contribución a la defensa de la Avanzada de Sangre no caerá en el olvido.', 0),
(@ID, 'esMX', 'Parecen lo suficientemente resistentes. Gracias por tu ayuda, $n. Tu contribución a la defensa de la Avanzada de Sangre no caerá en el olvido.', 0);
-- 9644 Nocturno
-- https://es.wowhead.com/quest=9644
SET @ID := 9644;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué novedades traes, $n?', 0),
(@ID, 'esMX', '¿Qué novedades traes, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto es asombroso! No solo has traído el Diario de Medivh, sino que también has recuperado un fragmento de su esencia misma.$B$BPor débil que sea esta esencia persistente, nos revelará información vital sobre Medivh. No olvidaremos esto, $n.', 0),
(@ID, 'esMX', '¡Esto es asombroso! No solo has traído el Diario de Medivh, sino que también has recuperado un fragmento de su esencia misma.$B$BPor débil que sea esta esencia persistente, nos revelará información vital sobre Medivh. No olvidaremos esto, $n.', 0);
-- 9645 El Bancal del Maestro
-- https://es.wowhead.com/quest=9645
SET @ID := 9645;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has regresado! ¿Qué noticias traes?', 0),
(@ID, 'esMX', '¡Has regresado! ¿Qué noticias traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es una lástima que los agentes que enviamos sucumbieran ante la magia de Karazhan. Al menos averiguaste qué buscaban.', 0),
(@ID, 'esMX', 'Es una lástima que los agentes que enviamos sucumbieran ante la magia de Karazhan. Al menos averiguaste qué buscaban.', 0);
-- 9646 SE BUSCA: Garraletal
-- https://es.wowhead.com/quest=9646
SET @ID := 9646;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿En qué puedo ayudarte, $c?', 0),
(@ID, 'esMX', '¿En qué puedo ayudarte, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien. Por lo que he oído no tuvo que ser un combate fácil. Tu recompensa es más que merecida, $n.', 0),
(@ID, 'esMX', 'Muy bien. Por lo que he oído no tuvo que ser un combate fácil. Tu recompensa es más que merecida, $n.', 0);
-- 9647 Sacrificar a los aleteadores
-- https://es.wowhead.com/quest=9647
SET @ID := 9647;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has sacrificado las polillas?', 0),
(@ID, 'esMX', '¿Has sacrificado las polillas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En su momento, tendremos que idear un plan para devolver las especies a su estado nativo pero, por ahora, sacrificar periódicamente unos cuantos es lo mejor a lo que podemos aspirar. Gracias por tu ayuda, $n.', 0),
(@ID, 'esMX', 'En su momento, tendremos que idear un plan para devolver las especies a su estado nativo pero, por ahora, sacrificar periódicamente unos cuantos es lo mejor a lo que podemos aspirar. Gracias por tu ayuda, $n.', 0);
-- 9648 La colección de champiñones de Mac'Aree
-- https://es.wowhead.com/quest=9648
SET @ID := 9648;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Recuerda, los champiñones que te pedí son únicos y solo se encuentran en su respectivo entorno de Bruma de Sangre.', 0),
(@ID, 'esMX', 'Recuerda, los champiñones que te pedí son únicos y solo se encuentran en su respectivo entorno de Bruma de Sangre.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, te avisé, ¿no? Espero que este pago te compense por las molestias que puedas haber sufrido. Regresa aquí cuando te hayas fortalecido y quizás tengamos otro trabajo para ti, ¡champiñones claro!', 0),
(@ID, 'esMX', 'Bueno, te avisé, ¿no? Espero que este pago te compense por las molestias que puedas haber sufrido. Regresa aquí cuando te hayas fortalecido y quizás tengamos otro trabajo para ti, ¡champiñones claro!', 0);
-- 9649 Las lágrimas de Ysera
-- https://es.wowhead.com/quest=9649
SET @ID := 9649;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya estás aquí?', 0),
(@ID, 'esMX', '¿Ya estás aquí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que no fuera una tarea demasiado extenuante, $n. Has vuelto a demostrar tu competencia y consideración, $r. Cuentas con mi agradecimiento y esta pequeña compensación monetaria.', 0),
(@ID, 'esMX', 'Espero que no fuera una tarea demasiado extenuante, $n. Has vuelto a demostrar tu competencia y consideración, $r. Cuentas con mi agradecimiento y esta pequeña compensación monetaria.', 0);
-- 9663 La carrera de Kessel
-- https://es.wowhead.com/quest=9663
SET @ID := 9663;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Gran jefe Semprepino avisado', `ObjectiveText2` = 'Gran jefe Semprepino avisado', `ObjectiveText3` = 'Almirante Odesyus avisado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No es momento de relajarse!', 0),
(@ID, 'esMX', '¡No es momento de relajarse!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Se trataba de una dura prueba para tus habilidades, pero la has pasado con éxito. Para convertirte en soldado de la Mano de Argus, debes pasar esas pruebas.', 0),
(@ID, 'esMX', 'Bien hecho, $n. Se trataba de una dura prueba para tus habilidades, pero la has pasado con éxito. Para convertirte en soldado de la Mano de Argus, debes pasar esas pruebas.', 0);
-- 9664 Nuevas avanzadas
-- https://es.classic.wowhead.com/quest=9664
SET @ID := 9664;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Captura la Torre de la Corona', `ObjectiveText2` = 'Captura la Torre de la Muralla del Este', `ObjectiveText3` = 'Captura la Torre del Paso Norte', `ObjectiveText4` = 'Captura la Torre del Bosque de la Peste', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 9665 Fortalecimiento de nuestras defensas
-- https://es.classic.wowhead.com/quest=9665
SET @ID := 9665;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Captura la Torre de la Corona', `ObjectiveText2` = 'Captura la Torre de la Muralla del Este', `ObjectiveText3` = 'Captura la Torre del Paso Norte', `ObjectiveText4` = 'Captura la Torre del Bosque de la Peste', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Deben ser tontos al pensar que les permitiríamos establecer bases tan cerca de una de nuestras capitales.$B$BDesangraremos sus números hasta que den la vuelta y se retiren hacia el sur.', 0),
(@ID, 'esMX', 'Deben ser tontos al pensar que les permitiríamos establecer bases tan cerca de una de nuestras capitales.$B$BDesangraremos sus números hasta que den la vuelta y se retiren hacia el sur.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas son buenas noticias, $n. Será una lucha constante aquí en las Tierras de la Peste hasta que hayamos rechazado por completo las fuerzas de la Alianza.$B$BHasta ese día, espero contar con tu asistencia continua.', 0),
(@ID, 'esMX', 'Estas son buenas noticias, $n. Será una lucha constante aquí en las Tierras de la Peste hasta que hayamos rechazado por completo las fuerzas de la Alianza.$B$BHasta ese día, espero contar con tu asistencia continua.', 0);
-- 9666 Declaración de poder
-- https://es.wowhead.com/quest=9666
SET @ID := 9666;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Está hecho?', 0),
(@ID, 'esMX', '¿Está hecho?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siento que hayas tenido que hacer eso, $n. La violencia no es algo que nos guste a los draenei pero, algunas veces, es la única forma.$B$BEsa es una de las verdades de la vida que muchos no comprenden hasta que es demasiado tarde. Así fue para nuestro pueblo cuando fuimos asesinados a manos de los orcos.$B$BConvertirse en Mano de Argus es un proceso de renacimiento. Y, con el nacimiento, viene el dolor...', 0),
(@ID, 'esMX', 'Siento que hayas tenido que hacer eso, $n. La violencia no es algo que nos guste a los draenei pero, algunas veces, es la única forma.$B$BEsa es una de las verdades de la vida que muchos no comprenden hasta que es demasiado tarde. Así fue para nuestro pueblo cuando fuimos asesinados a manos de los orcos.$B$BConvertirse en Mano de Argus es un proceso de renacimiento. Y, con el nacimiento, viene el dolor...', 0);
-- 9667 Salvar a la princesa Semprepino
-- https://es.wowhead.com/quest=9667
SET @ID := 9667;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Princesa Semprepino salvada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me queda mucho más tiempo, $n. Pronto me matarán...', 0),
(@ID, 'esMX', 'No me queda mucho más tiempo, $n. Pronto me matarán...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una vez más, has probado que eres todo lo que fue profetizado. Tienes la eterna gratitud del gran jefe $n, y estas reliquias Semprepino para elegir...', 0),
(@ID, 'esMX', 'Una vez más, has probado que eres todo lo que fue profetizado. Tienes la eterna gratitud del gran jefe $n, y estas reliquias Semprepino para elegir...', 0);
-- 9668 Informar al exarca Admetius
-- https://es.wowhead.com/quest=9668
SET @ID := 9668;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tenía el presentimiento de que llegarías lejos, $c. Si deseas progresar aún más, será un placer seguir enseñándote...', 0),
(@ID, 'esMX', 'Tenía el presentimiento de que llegarías lejos, $c. Si deseas progresar aún más, será un placer seguir enseñándote...', 0);
-- 9669 La expedición desaparecida
-- https://es.wowhead.com/quest=9669
SET @ID := 9669;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Fue un desastre terrible...', 0),
(@ID, 'esMX', 'Fue un desastre terrible...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Increíble! ¿Encontraste algún superviviente?$B$B<Achelus baja la voz hasta quedarse en un susurro.>$B$BSeré sincero, $n; nadie más estaba dispuesto a acometer esta misión. Eres $gun:una; valiente $c...', 0),
(@ID, 'esMX', '¡Increíble! ¿Encontraste algún superviviente?$B$B<Achelus baja la voz hasta quedarse en un susurro.>$B$BSeré sincero, $n; nadie más estaba dispuesto a acometer esta misión. Eres $gun:una; valiente $c...', 0);
-- 9670 ¡Viven! A lo mejor...
-- https://es.wowhead.com/quest=9670
SET @ID := 9670;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Investigador de expedición liberado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Alguna suerte?', 0),
(@ID, 'esMX', '¿Alguna suerte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has rescatado a más de medio equipo! Sin duda hablarán de tu hazaña en la Avanzada de Sangre y el exarca se enterará. Gracias otra vez, $n.', 0),
(@ID, 'esMX', '¡Has rescatado a más de medio equipo! Sin duda hablarán de tu hazaña en la Avanzada de Sangre y el exarca se enterará. Gracias otra vez, $n.', 0);
-- 9671 Entrega urgente
-- https://es.wowhead.com/quest=9671
SET @ID := 9671;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Eres $n? ¡Por fin! Ya pensaba que no te iba a encontrar.$B$BTienes un mensaje urgente; lo entregó un almirante humano de Bruma Azur. El almirante Odiseo o algo así..., no me acuerdo. Dijo que sabrías quién es.$B$B<Hermesius se encoge de hombros.>', 0),
(@ID, 'esMX', '¿Eres $n? ¡Por fin! Ya pensaba que no te iba a encontrar.$B$BTienes un mensaje urgente; lo entregó un almirante humano de Bruma Azur. El almirante Odiseo o algo así..., no me acuerdo. Dijo que sabrías quién es.$B$B<Hermesius se encoge de hombros.>', 0);
-- 9672 El legado de la Sangre Maldita
-- https://es.wowhead.com/quest=9672
SET @ID := 9672;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has oído hablar de la Sangre Maldita, $gmarinero:marinera; de agua dulce? No, claro que no. Es la causa del hundimiento de todos esos barcos. La parte del agua que ha quedado inutilizada se conoce como El Arrecife Sangre Maldita, una parte del mundo que no te recomiendo visitar. Yo llevo aquí 20 años.$B$B¡Qué escorbuto ni qué niño muerto! Me morí en estas salvajes orillas, serví de cena a los dragones... pero eso es otra historia. Ahora mismo, tenemos que ayudar a las pobres almas atrapadas en ese arrecife.', 0),
(@ID, 'esMX', '¿Has oído hablar de la Sangre Maldita, $gmarinero:marinera; de agua dulce? No, claro que no. Es la causa del hundimiento de todos esos barcos. La parte del agua que ha quedado inutilizada se conoce como El Arrecife Sangre Maldita, una parte del mundo que no te recomiendo visitar. Yo llevo aquí 20 años.$B$B¡Qué escorbuto ni qué niño muerto! Me morí en estas salvajes orillas, serví de cena a los dragones... pero eso es otra historia. Ahora mismo, tenemos que ayudar a las pobres almas atrapadas en ese arrecife.', 0);
-- 9673 Doma de bestias
-- https://es.wowhead.com/quest=9673
SET @ID := 9673;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que has aprendido un poco, ¿verdad?$B$B<Halthenis te mira con atención.>$B$BServirás bien a la ciudad y a nuestra causa mayor con tus habilidades recién aprendidas. Permíteme un momento para mostrarte cómo entrenar a tu mascota para que haga algunos trucos interesantes, como destripar a tu enemigo, y podrás seguir tu camino.', 0),
(@ID, 'esMX', 'Así que has aprendido un poco, ¿verdad?$B$B<Halthenis te mira con atención.>$B$BServirás bien a la ciudad y a nuestra causa mayor con tus habilidades recién aprendidas. Permíteme un momento para mostrarte cómo entrenar a tu mascota para que haga algunos trucos interesantes, como destripar a tu enemigo, y podrás seguir tu camino.', 0);
-- 9674 Los nagas Sangre Maldita
-- https://es.wowhead.com/quest=9674
SET @ID := 9674;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Son criaturas desagradables...', 0),
(@ID, 'esMX', 'Son criaturas desagradables...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Empiezas bien, pero queda mucho por hacer.', 0),
(@ID, 'esMX', 'Empiezas bien, pero queda mucho por hacer.', 0);
-- 9675 Doma de bestias
-- https://es.wowhead.com/quest=9675
SET @ID := 9675;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saber cómo alimentar y revivir a tu mascota de la muerte no es solo un "bocadito" extra, como lo expresó tu último maestro con tanta suavidad. Aún más, el entrenamiento le permite a tu mascota mejorar de una manera que no podría lograr por sí misma.$B$BYo he aprendido mucho de los fúrbolgs, así que presta atención y te lo transmitiré.', 0),
(@ID, 'esMX', 'Saber cómo alimentar y revivir a tu mascota de la muerte no es solo un "bocadito" extra, como lo expresó tu último maestro con tanta suavidad. Aún más, el entrenamiento le permite a tu mascota mejorar de una manera que no podría lograr por sí misma.$B$BYo he aprendido mucho de los fúrbolgs, así que presta atención y te lo transmitiré.', 0);
-- 9677 El llamamiento del Lord caballero Sangrevalor
-- https://es.wowhead.com/quest=9677
SET @ID := 9677;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bienvenido, joven $giniciado:iniciada;. Que hayas respondido a mi llamado tan pronto es un buen augurio para tí.$B$BDejemos de hacer cortesías, ya que es mejor dejarlas en manos de cortesanos y de su calaña.$B$BTu rápido progreso ha llamado mi atención, $n. Veremos si te has tomado las lecciones en serio.', 0),
(@ID, 'esMX', 'Bienvenido, joven $giniciado:iniciada;. Que hayas respondido a mi llamado tan pronto es un buen augurio para tí.$B$BDejemos de hacer cortesías, ya que es mejor dejarlas en manos de cortesanos y de su calaña.$B$BTu rápido progreso ha llamado mi atención, $n. Veremos si te has tomado las lecciones en serio.', 0);
-- 9678 La primera prueba
-- https://es.wowhead.com/quest=9678
SET @ID := 9678;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Realiza la primera prueba', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que la Luz siempre sea contigo.', 0),
(@ID, 'esMX', 'Que la Luz siempre sea contigo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sé lo que debe estar pasando por tu mente.$B$BSí, envié a Hojafirme para matarte.$B$BNo te ofendas, $n; era una prueba necesaria. Los Caballeros de Sangre somos una hermandad, pero debemos asegurarnos de que nuestros hermanos estén alerta y preparados en todo momento. ¿Fue necesario quitarle la vida a Hojafirme para hacertelo notar?$B$BSí, y eso es una parte tan importante de tu entrenamiento como cualquier ejercicio de espada.', 0),
(@ID, 'esMX', 'Sé lo que debe estar pasando por tu mente.$B$BSí, envié a Hojafirme para matarte.$B$BNo te ofendas, $n; era una prueba necesaria. Los Caballeros de Sangre somos una hermandad, pero debemos asegurarnos de que nuestros hermanos estén alerta y preparados en todo momento. ¿Fue necesario quitarle la vida a Hojafirme para hacertelo notar?$B$BSí, y eso es una parte tan importante de tu entrenamiento como cualquier ejercicio de espada.', 0);
-- 9680 Resucitar el pasado
-- https://es.wowhead.com/quest=9680
SET @ID := 9680;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido el trozo de hueso que necesito, $n?', 0),
(@ID, 'esMX', '¿Has conseguido el trozo de hueso que necesito, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico! Aunque es pequeño, este trozo irradia energía, ¡la siento!', 0),
(@ID, 'esMX', '¡Fantástico! Aunque es pequeño, este trozo irradia energía, ¡la siento!', 0);
-- 9681 Un estudio sobre el poder
-- https://es.wowhead.com/quest=9681
SET @ID := 9681;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida;, joven $n.$B$BEl poder de los Caballeros de Sangre se toma de un ser de inmenso poder.$B$B<El magister señala al gran ser cautivo que está en el centro de la habitación.>$B$B¿No es magnífico? Fue un regalo de nuestro amado Príncipe Kael\'thas, y es la base del dominio de la Luz de los Caballeros de Sangre. Esta criatura nos limita su poder, por lo que hemos ideado un método para reclamarlo en nuestros propios términos.', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida;, joven $n.$B$BEl poder de los Caballeros de Sangre se toma de un ser de inmenso poder.$B$B<El magister señala al gran ser cautivo que está en el centro de la habitación.>$B$B¿No es magnífico? Fue un regalo de nuestro amado Príncipe Kael\'thas, y es la base del dominio de la Luz de los Caballeros de Sangre. Esta criatura nos limita su poder, por lo que hemos ideado un método para reclamarlo en nuestros propios términos.', 0);
-- 9682 Los Desesperados...
-- https://es.wowhead.com/quest=9682
SET @ID := 9682;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No te lamentes por su destino, $n.', 0),
(@ID, 'esMX', 'No te lamentes por su destino, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho un gran servicio a los Desesperados, $n. Tienes que completar una última tarea: destruir al líder de los Sangre Maldita.', 0),
(@ID, 'esMX', 'Has hecho un gran servicio a los Desesperados, $n. Tienes que completar una última tarea: destruir al líder de los Sangre Maldita.', 0);
-- 9683 El fin de la Sangre Maldita
-- https://es.wowhead.com/quest=9683
SET @ID := 9683;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Atoph debe ser destruido!', 0),
(@ID, 'esMX', '¡Atoph debe ser destruido!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has conseguido! Cientos de almas te agradecen lo que has hecho.$B$BPermíteme que te haga una ofrenda...', 0),
(@ID, 'esMX', '¡Lo has conseguido! Cientos de almas te agradecen lo que has hecho.$B$BPermíteme que te haga una ofrenda...', 0);
-- 9684 Buscando la Luz
-- https://es.wowhead.com/quest=9684
SET @ID := 9684;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has hablado con el Magister Astalor Jurasangre?', 0),
(@ID, 'esMX', '¿Has hablado con el Magister Astalor Jurasangre?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Los poderes otorgados por la Luz nunca llegarán \'naturalmente\' a los Caballeros de Sangre, pero no somos tan ingenuos como para ser frustrados por la voluntad de un solo ser, por poderoso que sea.$B$BNuestro dominio de lo arcano ha desbloqueado este camino y estos poderes para ti, $giniciado:iniciada;. Pocos tienen el estómago o la capacidad para manejarlos, pero sé que no defraudarás a la orden.', 0),
(@ID, 'esMX', 'Bien hecho, $n. Los poderes otorgados por la Luz nunca llegarán \'naturalmente\' a los Caballeros de Sangre, pero no somos tan ingenuos como para ser frustrados por la voluntad de un solo ser, por poderoso que sea.$B$BNuestro dominio de lo arcano ha desbloqueado este camino y estos poderes para ti, $giniciado:iniciada;. Pocos tienen el estómago o la capacidad para manejarlos, pero sé que no defraudarás a la orden.', 0);
-- 9685 Redimir a los muertos
-- https://es.wowhead.com/quest=9685
SET @ID := 9685;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Resucitar a Sangrias Hojafirme', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida; de nuevo, $giniciado:iniciada;. Ahora que conoces la verdad sobre la fuente de nuestro poder y has demostrado tu habilidad para manejarlo, te otorgaré la habilidad de resucitar a los caídos en batalla.$B$BMantente fiel a la orden y sobresal en tu entrenamiento y solo continuarás creciendo en poder.', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida; de nuevo, $giniciado:iniciada;. Ahora que conoces la verdad sobre la fuente de nuestro poder y has demostrado tu habilidad para manejarlo, te otorgaré la habilidad de resucitar a los caídos en batalla.$B$BMantente fiel a la orden y sobresal en tu entrenamiento y solo continuarás creciendo en poder.', 0);
-- 9686 La segunda prueba
-- https://es.wowhead.com/quest=9686
SET @ID := 9686;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un Caballero de Sangre preferiría morir antes que someterse al enemigo. Recuerda eso, $n.', 0),
(@ID, 'esMX', 'Un Caballero de Sangre preferiría morir antes que someterse al enemigo. Recuerda eso, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien hecho, $n! Ha demostrado ser $gdigno:digna; de ser miembro de pleno derecho de los Caballeros de Sangre y ascender a la categoría de $gadepto:adepta;. Sin embargo, quedan algunas tareas más antes de que pueda llevarse a cabo la inducción.', 0),
(@ID, 'esMX', '¡Bien hecho, $n! Ha demostrado ser $gdigno:digna; de ser miembro de pleno derecho de los Caballeros de Sangre y ascender a la categoría de $gadepto:adepta;. Sin embargo, quedan algunas tareas más antes de que pueda llevarse a cabo la inducción.', 0);
-- 9687 Recuperando huesos sacros
-- https://es.wowhead.com/quest=9687
SET @ID := 9687;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las guerras de los dragones terminaron hace mucho. Todo cuanto queda son huesos y los agitados restos del linaje de Ysera.', 0),
(@ID, 'esMX', 'Las guerras de los dragones terminaron hace mucho. Todo cuanto queda son huesos y los agitados restos del linaje de Ysera.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un ritual? Los búhicos han vivido en armonía con la tierra durante milenios. ¡Esto es una aberración!$B$BEs una lástima...', 0),
(@ID, 'esMX', '¿Un ritual? Los búhicos han vivido en armonía con la tierra durante milenios. ¡Esto es una aberración!$B$BEs una lástima...', 0);
