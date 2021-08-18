-- 8601 ¡La Horda necesita más pieles de cuero basto!
-- https://es.classic.wowhead.com/quest=8601
SET @ID := 8601;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Práctica, práctica, práctica. Con un cuchillo bien afilado y la habilidad para usarlo llegarás lejos en este mundo, $n. Parece que los bordes de estas pieles están mejor que las últimas. ¿Compraste un cuchillo nuevo?$B$BSea como fuere, te agradecemos tus esfuerzos. He tomado buena nota de tu donación y se aprovechará bien, te lo aseguro. Si te acabas haciendo con más cuero basto, vuelve por aquí y habla conmigo ya que seguramente me hará falta más.', 0),
(@ID, 'esMX', 'Práctica, práctica, práctica. Con un cuchillo bien afilado y la habilidad para usarlo llegarás lejos en este mundo, $n. Parece que los bordes de estas pieles están mejor que las últimas. ¿Compraste un cuchillo nuevo?$B$BSea como fuere, te agradecemos tus esfuerzos. He tomado buena nota de tu donación y se aprovechará bien, te lo aseguro. Si te acabas haciendo con más cuero basto, vuelve por aquí y habla conmigo ya que seguramente me hará falta más.', 0);
-- 8602 Los espaldares de clamatormentas
-- https://es.classic.wowhead.com/quest=8602
SET @ID := 8602;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha recogido los componentes que necesito?', 0),
(@ID, 'esMX', '¿Ha recogido los componentes que necesito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De los materiales que traes y de las escamas de nuestros enemigos Qiraji caídos, te hago estas hombreras, mortal. Que te brinden la protección que necesitas y que verlos infunda miedo en nuestros enemigos.', 0),
(@ID, 'esMX', 'De los materiales que traes y de las escamas de nuestros enemigos Qiraji caídos, te hago estas hombreras, mortal. Que te brinden la protección que necesitas y que verlos infunda miedo en nuestros enemigos.', 0);
-- 8603 Las vestimentas del Oráculo
-- https://es.wowhead.com/quest=8603
SET @ID := 8603;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En su morada de Ahn\'Qiraj, el terrible C\'Thun aguarda dormido apaciblemente.', 0),
(@ID, 'esMX', 'En su morada de Ahn\'Qiraj, el terrible C\'Thun aguarda dormido apaciblemente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No esperaba que regresaras de tu intento, $n.$B$BHas alcanzado un destino más grande que el de la mayoría de los seres inmortales.$B$BAl matar a C\'Thun no solo has salvado a todo Azeroth, también has cambiado el balance de los acontecimientos cósmicos más allá de tu comprensión.$B$BAcepta esta togas como símbolo de la gloria y el peso de las consecuencias que tus acciones acarrearán.$B$BQue su poder te ayude en los retos que te aguardan, ¡$gasesino:asesina; de dioses!', 0),
(@ID, 'esMX', 'No esperaba que regresaras de tu intento, $n.$B$BHas alcanzado un destino más grande que el de la mayoría de los seres inmortales.$B$BAl matar a C\'Thun no solo has salvado a todo Azeroth, también has cambiado el balance de los acontecimientos cósmicos más allá de tu comprensión.$B$BAcepta esta togas como símbolo de la gloria y el peso de las consecuencias que tus acciones acarrearán.$B$BQue su poder te ayude en los retos que te aguardan, ¡$gasesino:asesina; de dioses!', 0);
-- 8604 ¡La Horda necesita vendas de lana!
-- https://es.classic.wowhead.com/quest=8604
SET @ID := 8604;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $c, ¿has vuelto tan rápido con las vendas de lana?', 0),
(@ID, 'esMX', 'Ah, $c, ¿has vuelto tan rápido con las vendas de lana?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes mi agradecimiento, $c, y el agradecimiento de la Horda. Si encuentras más vendas de lana, tráemelas aquí si deseas contribuir aún más al esfuerzo de guerra. Hasta entonces, ¡que tus antepasados velen por ti!', 0),
(@ID, 'esMX', 'Tienes mi agradecimiento, $c, y el agradecimiento de la Horda. Si encuentras más vendas de lana, tráemelas aquí si deseas contribuir aún más al esfuerzo de guerra. Hasta entonces, ¡que tus antepasados velen por ti!', 0);
-- 8605 ¡La Horda necesita más vendas de lana!
-- https://es.classic.wowhead.com/quest=8605
SET @ID := 8605;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Como $c, mereces todos mis respetos, $n! Me aseguraré de que esas vendas van a parar a las manos apropiadas. Cuentas con mi más sincero agradecimiento, así como con el de la Horda.$B$BVe en paz y vuelve si te encuentras con que te sobran vendas de lana. Toda contribución nos viene bien.', 0),
(@ID, 'esMX', '¡Como $c, mereces todos mis respetos, $n! Me aseguraré de que esas vendas van a parar a las manos apropiadas. Cuentas con mi más sincero agradecimiento, así como con el de la Horda.$B$BVe en paz y vuelve si te encuentras con que te sobran vendas de lana. Toda contribución nos viene bien.', 0);
-- 8606 ¡Señuelo!
-- https://es.classic.wowhead.com/quest=8606
SET @ID := 8606;
UPDATE `quest_template_locale` SET `ObjectiveText1` = '¿Para quién trabaja el Número Dos?', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Creo que es posible que hayamos subestimado a estos secuestradores de libros.', 0),
(@ID, 'esMX', 'Creo que es posible que hayamos subestimado a estos secuestradores de libros.', 0);
-- 8607 ¡La Horda necesita vendas de tejido mágico!
-- https://es.classic.wowhead.com/quest=8607
SET @ID := 8607;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No me falles, me dejarías mal, $c! Vuelve lo antes posible con las vendas de tejido mágico de las que hablamos.', 0),
(@ID, 'esMX', '¡No me falles, me dejarías mal, $c! Vuelve lo antes posible con las vendas de tejido mágico de las que hablamos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sorprendente, aunque aceptable. Quizás he subestimado tus facultades, $c. Quizás. Has completado una tarea muy sencilla y por ello recibirás una recompensa aún mayor. Pero que no se te suba a la cabeza. Si realmente quieres demostrar lo que vales, tendrás que volver a salir ahí fuera y traerme otro lote de vendas de tejido mágico.', 0),
(@ID, 'esMX', 'Sorprendente, aunque aceptable. Quizás he subestimado tus facultades, $c. Quizás. Has completado una tarea muy sencilla y por ello recibirás una recompensa aún mayor. Pero que no se te suba a la cabeza. Si realmente quieres demostrar lo que vales, tendrás que volver a salir ahí fuera y traerme otro lote de vendas de tejido mágico.', 0);
-- 8608 ¡La Horda necesita más vendas de tejido mágico!
-- https://es.classic.wowhead.com/quest=8608
SET @ID := 8608;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Asombroso, $c, lo has vuelto a conseguir! Bueno, cierto es que suelen decir que tengo buen olfato para elegir a mis colaboradores. Muy bien, se anotará tu contribución y recibirás los beneficios sociales que tu trabajo merece. Te sugiero que vuelvas de ronda y recolectes otro lote de vendas de tejido mágico si realmente quieres demostrar lo que vales.', 0),
(@ID, 'esMX', '¡Asombroso, $c, lo has vuelto a conseguir! Bueno, cierto es que suelen decir que tengo buen olfato para elegir a mis colaboradores. Muy bien, se anotará tu contribución y recibirás los beneficios sociales que tu trabajo merece. Te sugiero que vuelvas de ronda y recolectes otro lote de vendas de tejido mágico si realmente quieres demostrar lo que vales.', 0);
-- 8609 ¡La Horda necesita vendas de paño rúnico!
-- https://es.classic.wowhead.com/quest=8609
SET @ID := 8609;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Se avecina la guerra, me parece, $c. Te agradezco el tiempo y el esfuerzo que has dedicado a ayudarnos en nuestras tareas de recolección. ¿Has regresado porque ya tienes las vendas de paño rúnico de las que hablamos antes?', 0),
(@ID, 'esMX', 'Se avecina la guerra, me parece, $c. Te agradezco el tiempo y el esfuerzo que has dedicado a ayudarnos en nuestras tareas de recolección. ¿Has regresado porque ya tienes las vendas de paño rúnico de las que hablamos antes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres un orgullo para la Horda, $c. Gracias por tus continuos esfuerzos, ¡de corazón! Tendré que envolver estas nuevas vendas y hacer un recuento para ver cuánto nos falta para el objetivo. Si te apetece, puedes recolectar más vendas de paño rúnico y traérmelas aquí.', 0),
(@ID, 'esMX', 'Eres un orgullo para la Horda, $c. Gracias por tus continuos esfuerzos, ¡de corazón! Tendré que envolver estas nuevas vendas y hacer un recuento para ver cuánto nos falta para el objetivo. Si te apetece, puedes recolectar más vendas de paño rúnico y traérmelas aquí.', 0);
-- 8610 ¡La Horda necesita más vendas de paño rúnico!
-- https://es.classic.wowhead.com/quest=8610
SET @ID := 8610;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muestras un gran altruismo en tus actos, $n. Y con ello probablemente se salven muchas vidas de quienes van a combatir en Ahn\'Qiraj. Gracias y que sepas que cuentas con el agradecimiento de la Horda por tu donación. Si confeccionas o encuentras más vendas de paño rúnico, te ruego pienses en traérmelas aquí.', 0),
(@ID, 'esMX', 'Muestras un gran altruismo en tus actos, $n. Y con ello probablemente se salven muchas vidas de quienes van a combatir en Ahn\'Qiraj. Gracias y que sepas que cuentas con el agradecimiento de la Horda por tu donación. Si confeccionas o encuentras más vendas de paño rúnico, te ruego pienses en traérmelas aquí.', 0);
-- 8611 ¡La Horda necesita filetes de lobo magro!
-- https://es.classic.wowhead.com/quest=8611
SET @ID := 8611;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿De vuelta con esos magros filetes de lobo tan pronto, $c? No me importa si están demasiado hechos o crudos, ¡solo asegúrate de que estén sabrosos y tráemelos rápido!', 0),
(@ID, 'esMX', '¿De vuelta con esos magros filetes de lobo tan pronto, $c? No me importa si están demasiado hechos o crudos, ¡solo asegúrate de que estén sabrosos y tráemelos rápido!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ok, este montón de carne me parece bien. Los salaré y luego los empaquetaré y, con suerte, se mantendrán lo suficientemente frescos como para ser comestibles cuando llegue el momento.$B$BGracias por la contribución, $c. ¿Crees que podrías traerme otro lote?', 0),
(@ID, 'esMX', 'Ok, este montón de carne me parece bien. Los salaré y luego los empaquetaré y, con suerte, se mantendrán lo suficientemente frescos como para ser comestibles cuando llegue el momento.$B$BGracias por la contribución, $c. ¿Crees que podrías traerme otro lote?', 0);
-- 8613 ¡La Horda necesita serviolas moteadas!
-- https://es.classic.wowhead.com/quest=8613
SET @ID := 8613;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Regresaste tan pronto con las serviolas moteadas, $c? ¿T\'acuerdas de cocinarlo bien? N\'estamos sirviendo pescado crudo a los soldados bajo el ardiente sol del desierto, sin duda.', 0),
(@ID, 'esMX', '¿Regresaste tan pronto con las serviolas moteadas, $c? ¿T\'acuerdas de cocinarlo bien? N\'estamos sirviendo pescado crudo a los soldados bajo el ardiente sol del desierto, sin duda.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh sí, esto es lo bueno. L\'empaquetaré muy bien pa\'que no se desperdicie. Gracias por ayudarme así. Creo qu\'eres $gel pescador:la pescadora; número uno por toda esta serviola moteada. Y si pescas y cocinas aún más, tráemelo aquí; ¡M\'aseguraré de que todos sepan que l\'hiciste!', 0),
(@ID, 'esMX', 'Oh sí, esto es lo bueno. L\'empaquetaré muy bien pa\'que no se desperdicie. Gracias por ayudarme así. Creo qu\'eres $gel pescador:la pescadora; número uno por toda esta serviola moteada. Y si pescas y cocinas aún más, tráemelo aquí; ¡M\'aseguraré de que todos sepan que l\'hiciste!', 0);
-- 8614 ¡La Horda necesita más serviolas moteadas!
-- https://es.classic.wowhead.com/quest=8614
SET @ID := 8614;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La pesca más guay, $n! Lo que se dice un trabajo bueno y honesto. ¡Y sin espinas! Gracias por conseguir to\'a esa serviola moteada, colega. ¡Vuelve pronto si cocinas más!', 0),
(@ID, 'esMX', '¡La pesca más guay, $n! Lo que se dice un trabajo bueno y honesto. ¡Y sin espinas! Gracias por conseguir to\'a esa serviola moteada, colega. ¡Vuelve pronto si cocinas más!', 0);
-- 8615 ¡La Horda necesita salmón asado!
-- https://es.classic.wowhead.com/quest=8615
SET @ID := 8615;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has vuelto con el salmón asado, $c? Recuerda, debe estar bien asado; Desafortunadamente, no tengo ningún uso para el pescado crudo.', 0),
(@ID, 'esMX', '¿Has vuelto con el salmón asado, $c? Recuerda, debe estar bien asado; Desafortunadamente, no tengo ningún uso para el pescado crudo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por demostrar tu interés en ayudar con el esfuerzo bélico, $c. Muchos simplemente ignorarían nuestras necesidades y optarían por obtener ganancias. Pero no cuentan con la gratitud de la Horda, como tú ahora. Sus corazones no están llenos, ya que el tuyo debe estar lleno del orgullo que proviene de la generosidad desinteresada.$B$BNuevamente, te lo agradezco. Si encuentra tiempo para ayudarnos más, antes de que finalicen nuestros preparativos, estaré aquí esperando.', 0),
(@ID, 'esMX', 'Gracias por demostrar tu interés en ayudar con el esfuerzo bélico, $c. Muchos simplemente ignorarían nuestras necesidades y optarían por obtener ganancias. Pero no cuentan con la gratitud de la Horda, como tú ahora. Sus corazones no están llenos, ya que el tuyo debe estar lleno del orgullo que proviene de la generosidad desinteresada.$B$BNuevamente, te lo agradezco. Si encuentra tiempo para ayudarnos más, antes de que finalicen nuestros preparativos, estaré aquí esperando.', 0);
-- 8619 Alborhondo el Ancestro
-- https://es.wowhead.com/quest=8619
SET @ID := 8619;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(@ID, 'esMX', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0);
-- 8620 La única receta
-- https://es.classic.wowhead.com/quest=8620
SET @ID := 8620;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me pongo los pantalones como tú, una pierna y luego la otra. Excepto cuando tengo los pantalones puestos, entonces hago boyas de arcanita. ¡Boyas de arcanita, bebé!', 0),
(@ID, 'esMX', 'Me pongo los pantalones como tú, una pierna y luego la otra. Excepto cuando tengo los pantalones puestos, entonces hago boyas de arcanita. ¡Boyas de arcanita, bebé!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico! ¡No puedo creer que hayas pasado por el lío! ¿Eres una especie de máquina? Si fuera yo, probablemente habría dejado que el mundo se derrumbara.$B$BTe doy mi turbante, $gseñor:señora;. Ninguna buena acción debe quedar sin recompensa.', 0),
(@ID, 'esMX', '¡Fantástico! ¡No puedo creer que hayas pasado por el lío! ¿Eres una especie de máquina? Si fuera yo, probablemente habría dejado que el mundo se derrumbara.$B$BTe doy mi turbante, $gseñor:señora;. Ninguna buena acción debe quedar sin recompensa.', 0);
-- 8621 Los guardapiés de clamatormentas
-- https://es.classic.wowhead.com/quest=8621
SET @ID := 8621;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has adquirido los artículos que te pedí, $n?', 0),
(@ID, 'esMX', '¿Has adquirido los artículos que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien, $n. Has probado que no eres $gun:una; mortal $gordinario:ordinaria;.$B$BTe los doy con la confianza de que te ayudarán a aplastar al vil qiraji.', 0),
(@ID, 'esMX', 'Lo has hecho bien, $n. Has probado que no eres $gun:una; mortal $gordinario:ordinaria;.$B$BTe los doy con la confianza de que te ayudarán a aplastar al vil qiraji.', 0);
-- 8622 El camisote de clamatormentas
-- https://es.classic.wowhead.com/quest=8622
SET @ID := 8622;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En su morada en Ahn\'Qiraj, el pavoroso C\'Thun aguarda dormido.', 0),
(@ID, 'esMX', 'En su morada en Ahn\'Qiraj, el pavoroso C\'Thun aguarda dormido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No esperaba que volvieras de tu intento, $n.$B$BHas cumplido un destino más grande que el de la mayoría de los seres inmortales.$B$BAl matar a C\'Thun, no solo has salvado todo Azeroth, sino que también has inclinado la balanza de los eventos cósmicos más allá de tu comprensión.$B$BAcepta esta coraza como símbolo de la gloria y la carga que vendrán como consecuencia de tus acciones.$B$B¡Que su poder te ayude en los desafíos que te esperan, asesino de dioses!', 0),
(@ID, 'esMX', 'No esperaba que volvieras de tu intento, $n.$B$BHas cumplido un destino más grande que el de la mayoría de los seres inmortales.$B$BAl matar a C\'Thun, no solo has salvado todo Azeroth, sino que también has inclinado la balanza de los eventos cósmicos más allá de tu comprensión.$B$BAcepta esta coraza como símbolo de la gloria y la carga que vendrán como consecuencia de tus acciones.$B$B¡Que su poder te ayude en los desafíos que te esperan, asesino de dioses!', 0);
-- 8623 La diadema de clamatormentas
-- https://es.classic.wowhead.com/quest=8623
SET @ID := 8623;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me trajiste los componentes que te pedí, $n?', 0),
(@ID, 'esMX', '¿Me trajiste los componentes que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has logrado! Los susurros de los Emperadores Gemelos han cesado.$B$BToma esto como recompensa. El mero hecho de verlo infundirá miedo en los corazones de los Qiraji... les recordará a sus líderes caídos y $gal:a la; mortal que los mató.', 0),
(@ID, 'esMX', '¡Lo has logrado! Los susurros de los Emperadores Gemelos han cesado.$B$BToma esto como recompensa. El mero hecho de verlo infundirá miedo en los corazones de los Qiraji... les recordará a sus líderes caídos y $gal:a la; mortal que los mató.', 0);
-- 8624 Los leotardos de clamatormentas
-- https://es.classic.wowhead.com/quest=8624
SET @ID := 8624;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me trajiste los componentes que te pedí, $n?', 0),
(@ID, 'esMX', '¿Me trajiste los componentes que te pedí, $n?', 0);
-- 8625 Las hombreras enigma
-- https://es.classic.wowhead.com/quest=8625
SET @ID := 8625;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me trajiste los componentes que te pedí?', 0),
(@ID, 'esMX', '¿Me trajiste los componentes que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De los materiales que traes y de las escamas de nuestros enemigos Qiraji caídos, te hago estas hombreras, mortal. Que te brinden la protección que necesitas y que al verte infunda miedo en nuestros enemigos.', 0),
(@ID, 'esMX', 'De los materiales que traes y de las escamas de nuestros enemigos Qiraji caídos, te hago estas hombreras, mortal. Que te brinden la protección que necesitas y que al verte infunda miedo en nuestros enemigos.', 0);
-- 8626 Los guardapiés de asediador
-- https://es.classic.wowhead.com/quest=8626
SET @ID := 8626;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me trajiste los componentes que te pedí, $n?', 0),
(@ID, 'esMX', '¿Me trajiste los componentes que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien, $n. Has probado que no eres $gun:una; mortal $gordinario:ordinaria;.$B$BTe los doy con la confianza de que te ayudarán a aplastar al vil qiraji.', 0),
(@ID, 'esMX', 'Lo has hecho bien, $n. Has probado que no eres $gun:una; mortal $gordinario:ordinaria;.$B$BTe los doy con la confianza de que te ayudarán a aplastar al vil qiraji.', 0);
-- 8627 La coraza del Vengador
-- https://es.classic.wowhead.com/quest=8627
SET @ID := 8627;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En su morada de Ahn\'Qiraj, el terrible C\'Thun aguarda dormido apaciblemente.', 0),
(@ID, 'esMX', 'En su morada de Ahn\'Qiraj, el terrible C\'Thun aguarda dormido apaciblemente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No esperaba que regresaras de tu intento, $n.$B$BHas alcanzado un destino más grande que el de la mayoría de los seres inmortales.$B$BAl matar a C\'Thun no solo has salvado a todo Azeroth, también has cambiado el balance de los acontecimientos cósmicos más allá de tu comprensión.$B$BAcepta esta togas como símbolo de la gloria y el peso de las consecuencias que tus acciones acarrearán.$B$BQue su poder te ayude en los retos que te aguardan, ¡$gasesino:asesina; de dioses!', 0),
(@ID, 'esMX', 'No esperaba que regresaras de tu intento, $n.$B$BHas alcanzado un destino más grande que el de la mayoría de los seres inmortales.$B$BAl matar a C\'Thun no solo has salvado a todo Azeroth, también has cambiado el balance de los acontecimientos cósmicos más allá de tu comprensión.$B$BAcepta esta togas como símbolo de la gloria y el peso de las consecuencias que tus acciones acarrearán.$B$BQue su poder te ayude en los retos que te aguardan, ¡$gasesino:asesina; de dioses!', 0);
-- 8628 La corona del Vengador
-- https://es.classic.wowhead.com/quest=8628
SET @ID := 8628;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me trajiste los componentes que te pedí?', 0),
(@ID, 'esMX', '¿Me trajiste los componentes que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De los materiales que traes y de las escamas de nuestros enemigos Qiraji caídos, te hago estas hombreras, mortal. Que te brinden la protección que necesitas y que al verte infunda miedo en nuestros enemigos.', 0),
(@ID, 'esMX', 'De los materiales que traes y de las escamas de nuestros enemigos Qiraji caídos, te hago estas hombreras, mortal. Que te brinden la protección que necesitas y que al verte infunda miedo en nuestros enemigos.', 0);
-- 8629 Las musleras del Vengador
-- https://es.classic.wowhead.com/quest=8629
SET @ID := 8629;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me trajiste los componentes que te pedí, $n?', 0),
(@ID, 'esMX', '¿Me trajiste los componentes que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí... la piel del gusano será una excelente capa protectora. Combinado con las partes más fuertes de los Qiraji que hemos destruido en nuestro camino hacia aquí, esto debería ser una formidable pieza de armadura. ¡Que te ayude a afrontar los horrores indescriptibles que te aguardan en el interior!', 0),
(@ID, 'esMX', 'Sí... la piel del gusano será una excelente capa protectora. Combinado con las partes más fuertes de los Qiraji que hemos destruido en nuestro camino hacia aquí, esto debería ser una formidable pieza de armadura. ¡Que te ayude a afrontar los horrores indescriptibles que te aguardan en el interior!', 0);
-- 8630 Los espaldares del Vengador
-- https://es.classic.wowhead.com/quest=8630
SET @ID := 8630;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me trajiste los componentes que te pedí?', 0),
(@ID, 'esMX', '¿Me trajiste los componentes que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De los materiales que traes y de las escamas de nuestros enemigos Qiraji caídos, te hago estas hombreras, mortal. Que te brinden la protección que necesitas y que al verte infunda miedo en nuestros enemigos.', 0),
(@ID, 'esMX', 'De los materiales que traes y de las escamas de nuestros enemigos Qiraji caídos, te hago estas hombreras, mortal. Que te brinden la protección que necesitas y que al verte infunda miedo en nuestros enemigos.', 0);
-- 8631 Los leotardos enigma
-- https://es.classic.wowhead.com/quest=8631
SET @ID := 8631;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me trajiste los componentes que te pedí, $n?', 0),
(@ID, 'esMX', '¿Me trajiste los componentes que te pedí, $n?', 0);
-- 8632 El aro enigma
-- https://es.classic.wowhead.com/quest=8632
SET @ID := 8632;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me trajiste los componentes que te pedí, $n?', 0),
(@ID, 'esMX', '¿Me trajiste los componentes que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has logrado! Los susurros de los Emperadores Gemelos han cesado.$B$BToma esto como recompensa. El mero hecho de verlo infundirá miedo en los corazones de los Qiraji... les recordará a sus líderes caídos y $gal:a la; mortal que los mató.', 0),
(@ID, 'esMX', '¡Lo has logrado! Los susurros de los Emperadores Gemelos han cesado.$B$BToma esto como recompensa. El mero hecho de verlo infundirá miedo en los corazones de los Qiraji... les recordará a sus líderes caídos y $gal:a la; mortal que los mató.', 0);
-- 8633 Togas Enigma
-- https://es.classic.wowhead.com/quest=8633
SET @ID := 8633;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En su morada de Ahn\'Qiraj, el terrible C\'Thun aguarda dormido apaciblemente.', 0),
(@ID, 'esMX', 'En su morada de Ahn\'Qiraj, el terrible C\'Thun aguarda dormido apaciblemente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No esperaba que regresaras de tu intento, $n.$B$BHas alcanzado un destino más grande que el de la mayoría de los seres inmortales.$B$BAl matar a C\'Thun no solo has salvado a todo Azeroth, también has cambiado el balance de los acontecimientos cósmicos más allá de tu comprensión.$B$BAcepta esta togas como símbolo de la gloria y el peso de las consecuencias que tus acciones acarrearán.$B$BQue su poder te ayude en los retos que te aguardan, ¡$gasesino:asesina; de dioses!', 0),
(@ID, 'esMX', 'No esperaba que regresaras de tu intento, $n.$B$BHas alcanzado un destino más grande que el de la mayoría de los seres inmortales.$B$BAl matar a C\'Thun no solo has salvado a todo Azeroth, también has cambiado el balance de los acontecimientos cósmicos más allá de tu comprensión.$B$BAcepta esta togas como símbolo de la gloria y el peso de las consecuencias que tus acciones acarrearán.$B$BQue su poder te ayude en los retos que te aguardan, ¡$gasesino:asesina; de dioses!', 0);
-- 8634 Las botas enigma
-- https://es.classic.wowhead.com/quest=8634
SET @ID := 8634;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me trajiste los componentes que te pedí, $n?', 0),
(@ID, 'esMX', '¿Me trajiste los componentes que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien, $n. Has probado que no eres $gun:una; mortal $gordinario:ordinaria;.$B$BTe los doy con la confianza de que te ayudarán a aplastar al vil qiraji.', 0),
(@ID, 'esMX', 'Lo has hecho bien, $n. Has probado que no eres $gun:una; mortal $gordinario:ordinaria;.$B$BTe los doy con la confianza de que te ayudarán a aplastar al vil qiraji.', 0);
-- 8635 Parterroca el Ancestro
-- https://es.wowhead.com/quest=8635
SET @ID := 8635;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las batallas de eras pasadas son las semillas de las que crecen las leyendas. El tuyo es un tiempo de héroes, joven. Que tu propia leyenda tome raíces y crezca con fuerza.$B$BTe deseo lo mejor, $n, y te ofrezco esta muestra...', 0),
(@ID, 'esMX', 'Las batallas de eras pasadas son las semillas de las que crecen las leyendas. El tuyo es un tiempo de héroes, joven. Que tu propia leyenda tome raíces y crezca con fuerza.$B$BTe deseo lo mejor, $n, y te ofrezco esta muestra...', 0);
-- 8636 Rocaestruendo el Ancestro
-- https://es.classic.wowhead.com/quest=8636
SET @ID := 8636;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La materia de la vida está condenada a morir y volver a la tierra, pero la materia del espíritu vive toda la eternidad. Te deseo lo mejor, $n, y te ofrezco esta muestra...', 0),
(@ID, 'esMX', 'La materia de la vida está condenada a morir y volver a la tierra, pero la materia del espíritu vive toda la eternidad. Te deseo lo mejor, $n, y te ofrezco esta muestra...', 0);
-- 8637 Las botas de mortífero
-- https://es.classic.wowhead.com/quest=8637
SET @ID := 8637;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me trajiste los componentes que te pedí, $n?', 0),
(@ID, 'esMX', '¿Me trajiste los componentes que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien, $n. Has probado que no eres $gun:una; mortal $gordinario:ordinaria;.$B$BTe los doy con la confianza de que te ayudarán a aplastar al vil qiraji.', 0),
(@ID, 'esMX', 'Lo has hecho bien, $n. Has probado que no eres $gun:una; mortal $gordinario:ordinaria;.$B$BTe los doy con la confianza de que te ayudarán a aplastar al vil qiraji.', 0);
-- 8638 El jubón de mortífero
-- https://es.classic.wowhead.com/quest=8638
SET @ID := 8638;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En su morada de Ahn\'Qiraj, el terrible C\'Thun aguarda dormido apaciblemente.', 0),
(@ID, 'esMX', 'En su morada de Ahn\'Qiraj, el terrible C\'Thun aguarda dormido apaciblemente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No esperaba que regresaras de tu intento, $n.$B$BHas alcanzado un destino más grande que el de la mayoría de los seres inmortales.$B$BAl matar a C\'Thun no solo has salvado a todo Azeroth, también has cambiado el balance de los acontecimientos cósmicos más allá de tu comprensión.$B$BAcepta esta togas como símbolo de la gloria y el peso de las consecuencias que tus acciones acarrearán.$B$BQue su poder te ayude en los retos que te aguardan, ¡$gasesino:asesina; de dioses!', 0),
(@ID, 'esMX', 'No esperaba que regresaras de tu intento, $n.$B$BHas alcanzado un destino más grande que el de la mayoría de los seres inmortales.$B$BAl matar a C\'Thun no solo has salvado a todo Azeroth, también has cambiado el balance de los acontecimientos cósmicos más allá de tu comprensión.$B$BAcepta esta togas como símbolo de la gloria y el peso de las consecuencias que tus acciones acarrearán.$B$BQue su poder te ayude en los retos que te aguardan, ¡$gasesino:asesina; de dioses!', 0);
-- 8639 El yelmo de mortífero
-- https://es.classic.wowhead.com/quest=8639
SET @ID := 8639;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me trajiste los componentes que te pedí, $n?', 0),
(@ID, 'esMX', '¿Me trajiste los componentes que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has logrado! Los susurros de los Emperadores Gemelos han cesado.$B$BToma esto como recompensa. El mero hecho de verlo infundirá miedo en los corazones de los Qiraji... les recordará a sus líderes caídos y $gal:a la; mortal que los mató.', 0),
(@ID, 'esMX', '¡Lo has logrado! Los susurros de los Emperadores Gemelos han cesado.$B$BToma esto como recompensa. El mero hecho de verlo infundirá miedo en los corazones de los Qiraji... les recordará a sus líderes caídos y $gal:a la; mortal que los mató.', 0);
-- 8640 Los leotardos de mortífero
-- https://es.classic.wowhead.com/quest=8640
SET @ID := 8640;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me trajiste los componentes que te pedí, $n?', 0),
(@ID, 'esMX', '¿Me trajiste los componentes que te pedí, $n?', 0);
-- 8641 Las bufas de mortífero
-- https://es.classic.wowhead.com/quest=8641
SET @ID := 8641;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me trajiste los componentes que te pedí?', 0),
(@ID, 'esMX', '¿Me trajiste los componentes que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De los materiales que traes y de las escamas de nuestros enemigos Qiraji caídos, te hago estas hombreras, mortal. Que te brinden la protección que necesitas y que al verte infunda miedo en nuestros enemigos.', 0),
(@ID, 'esMX', 'De los materiales que traes y de las escamas de nuestros enemigos Qiraji caídos, te hago estas hombreras, mortal. Que te brinden la protección que necesitas y que al verte infunda miedo en nuestros enemigos.', 0);
