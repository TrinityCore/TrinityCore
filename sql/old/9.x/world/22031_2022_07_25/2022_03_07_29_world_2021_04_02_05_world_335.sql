-- Venaplata el Ancestro
-- 8642, 8643, 8644, 8645, 8647, 8648, 8650, 8651, 8652, 8653, 8654
-- https://es.wowhead.com/quest=8642
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8642, 8643, 8644, 8645, 8647, 8648, 8650, 8651, 8652, 8653, 8654) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8642, 'esES', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(8643, 'esES', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(8644, 'esES', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(8645, 'esES', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(8647, 'esES', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(8648, 'esES', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(8650, 'esES', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(8651, 'esES', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(8652, 'esES', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(8653, 'esES', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(8654, 'esES', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(8642, 'esMX', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(8643, 'esMX', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(8644, 'esMX', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(8645, 'esMX', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(8647, 'esMX', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(8648, 'esMX', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(8650, 'esMX', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(8651, 'esMX', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(8652, 'esMX', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(8653, 'esMX', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(8654, 'esMX', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0);
-- Las grebas del Vengador
-- 8655, 8660, 8665
-- https://es.classic.wowhead.com/quest=8655
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8655, 8660, 8665) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8655, 'esES', '¿Me trajiste los componentes que te pedí, $n?', 0),
(8660, 'esES', '¿Me trajiste los componentes que te pedí, $n?', 0),
(8665, 'esES', '¿Me trajiste los componentes que te pedí, $n?', 0),
(8655, 'esMX', '¿Me trajiste los componentes que te pedí, $n?', 0),
(8660, 'esMX', '¿Me trajiste los componentes que te pedí, $n?', 0),
(8665, 'esMX', '¿Me trajiste los componentes que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8655, 8660, 8665) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8655, 'esES', 'Lo has hecho bien, $n. Has probado que no eres $gun:una; mortal $gordinario:ordinaria;.$B$BTe los doy con la confianza de que te ayudarán a aplastar al vil qiraji.', 0),
(8660, 'esES', 'Lo has hecho bien, $n. Has probado que no eres $gun:una; mortal $gordinario:ordinaria;.$B$BTe los doy con la confianza de que te ayudarán a aplastar al vil qiraji.', 0),
(8665, 'esES', 'Lo has hecho bien, $n. Has probado que no eres $gun:una; mortal $gordinario:ordinaria;.$B$BTe los doy con la confianza de que te ayudarán a aplastar al vil qiraji.', 0),
(8655, 'esMX', 'Lo has hecho bien, $n. Has probado que no eres $gun:una; mortal $gordinario:ordinaria;.$B$BTe los doy con la confianza de que te ayudarán a aplastar al vil qiraji.', 0),
(8660, 'esMX', 'Lo has hecho bien, $n. Has probado que no eres $gun:una; mortal $gordinario:ordinaria;.$B$BTe los doy con la confianza de que te ayudarán a aplastar al vil qiraji.', 0),
(8665, 'esMX', 'Lo has hecho bien, $n. Has probado que no eres $gun:una; mortal $gordinario:ordinaria;.$B$BTe los doy con la confianza de que te ayudarán a aplastar al vil qiraji.', 0);
-- El camisote de asediador
-- 8656, 8666
-- https://es.classic.wowhead.com/quest=8656
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8656, 8666) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8656, 'esES', 'En su morada de Ahn\'Qiraj, el terrible C\'Thun aguarda dormido apaciblemente.', 0),
(8666, 'esES', 'En su morada de Ahn\'Qiraj, el terrible C\'Thun aguarda dormido apaciblemente.', 0),
(8656, 'esMX', 'En su morada de Ahn\'Qiraj, el terrible C\'Thun aguarda dormido apaciblemente.', 0),
(8666, 'esMX', 'En su morada de Ahn\'Qiraj, el terrible C\'Thun aguarda dormido apaciblemente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8656, 8666) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8656, 'esES', 'No esperaba que regresaras de tu intento, $n.$B$BHas alcanzado un destino más grande que el de la mayoría de los seres inmortales.$B$BAl matar a C\'Thun no solo has salvado a todo Azeroth, también has cambiado el balance de los acontecimientos cósmicos más allá de tu comprensión.$B$BAcepta esta togas como símbolo de la gloria y el peso de las consecuencias que tus acciones acarrearán.$B$BQue su poder te ayude en los retos que te aguardan, ¡$gasesino:asesina; de dioses!', 0),
(8666, 'esES', 'No esperaba que regresaras de tu intento, $n.$B$BHas alcanzado un destino más grande que el de la mayoría de los seres inmortales.$B$BAl matar a C\'Thun no solo has salvado a todo Azeroth, también has cambiado el balance de los acontecimientos cósmicos más allá de tu comprensión.$B$BAcepta esta togas como símbolo de la gloria y el peso de las consecuencias que tus acciones acarrearán.$B$BQue su poder te ayude en los retos que te aguardan, ¡$gasesino:asesina; de dioses!', 0),
(8656, 'esMX', 'No esperaba que regresaras de tu intento, $n.$B$BHas alcanzado un destino más grande que el de la mayoría de los seres inmortales.$B$BAl matar a C\'Thun no solo has salvado a todo Azeroth, también has cambiado el balance de los acontecimientos cósmicos más allá de tu comprensión.$B$BAcepta esta togas como símbolo de la gloria y el peso de las consecuencias que tus acciones acarrearán.$B$BQue su poder te ayude en los retos que te aguardan, ¡$gasesino:asesina; de dioses!', 0),
(8666, 'esMX', 'No esperaba que regresaras de tu intento, $n.$B$BHas alcanzado un destino más grande que el de la mayoría de los seres inmortales.$B$BAl matar a C\'Thun no solo has salvado a todo Azeroth, también has cambiado el balance de los acontecimientos cósmicos más allá de tu comprensión.$B$BAcepta esta togas como símbolo de la gloria y el peso de las consecuencias que tus acciones acarrearán.$B$BQue su poder te ayude en los retos que te aguardan, ¡$gasesino:asesina; de dioses!', 0);
-- La diadema de asediador
-- 8657, 8662, 8667
-- https://es.classic.wowhead.com/quest=8657
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8657, 8662, 8667) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8657, 'esES', '¿Me trajiste los componentes que te pedí, $n?', 0),
(8662, 'esES', '¿Me trajiste los componentes que te pedí, $n?', 0),
(8667, 'esES', '¿Me trajiste los componentes que te pedí, $n?', 0),
(8657, 'esMX', '¿Me trajiste los componentes que te pedí, $n?', 0),
(8662, 'esMX', '¿Me trajiste los componentes que te pedí, $n?', 0),
(8667, 'esMX', '¿Me trajiste los componentes que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8657, 8662, 8667) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8657, 'esES', '¡Lo has logrado! Los susurros de los Emperadores Gemelos han cesado.$B$BToma esto como recompensa. El mero hecho de verlo infundirá miedo en los corazones de los Qiraji... les recordará a sus líderes caídos y $gal:a la; mortal que los mató.', 0),
(8662, 'esES', '¡Lo has logrado! Los susurros de los Emperadores Gemelos han cesado.$B$BToma esto como recompensa. El mero hecho de verlo infundirá miedo en los corazones de los Qiraji... les recordará a sus líderes caídos y $gal:a la; mortal que los mató.', 0),
(8667, 'esES', '¡Lo has logrado! Los susurros de los Emperadores Gemelos han cesado.$B$BToma esto como recompensa. El mero hecho de verlo infundirá miedo en los corazones de los Qiraji... les recordará a sus líderes caídos y $gal:a la; mortal que los mató.', 0),
(8657, 'esMX', '¡Lo has logrado! Los susurros de los Emperadores Gemelos han cesado.$B$BToma esto como recompensa. El mero hecho de verlo infundirá miedo en los corazones de los Qiraji... les recordará a sus líderes caídos y $gal:a la; mortal que los mató.', 0),
(8662, 'esMX', '¡Lo has logrado! Los susurros de los Emperadores Gemelos han cesado.$B$BToma esto como recompensa. El mero hecho de verlo infundirá miedo en los corazones de los Qiraji... les recordará a sus líderes caídos y $gal:a la; mortal que los mató.', 0),
(8667, 'esMX', '¡Lo has logrado! Los susurros de los Emperadores Gemelos han cesado.$B$BToma esto como recompensa. El mero hecho de verlo infundirá miedo en los corazones de los Qiraji... les recordará a sus líderes caídos y $gal:a la; mortal que los mató.', 0);
-- 8658 Los leotardos de asediador
-- https://es.classic.wowhead.com/quest=8658
SET @ID := 8658;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me trajiste los componentes que te pedí, $n?', 0),
(@ID, 'esMX', '¿Me trajiste los componentes que te pedí, $n?', 0);
-- Los espaldares de asediador
-- 8659, 8664, 8669
-- https://es.classic.wowhead.com/quest=8659
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8659, 8664, 8669) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8659, 'esES', '¿Me trajiste los componentes que te pedí?', 0),
(8664, 'esES', '¿Me trajiste los componentes que te pedí?', 0),
(8669, 'esES', '¿Me trajiste los componentes que te pedí?', 0),
(8659, 'esMX', '¿Me trajiste los componentes que te pedí?', 0),
(8664, 'esMX', '¿Me trajiste los componentes que te pedí?', 0),
(8669, 'esMX', '¿Me trajiste los componentes que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8659, 8664, 8669) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8659, 'esES', 'De los materiales que traes y de las escamas de nuestros enemigos Qiraji caídos, te hago estas hombreras, mortal. Que te brinden la protección que necesitas y que al verte infunda miedo en nuestros enemigos.', 0),
(8664, 'esES', 'De los materiales que traes y de las escamas de nuestros enemigos Qiraji caídos, te hago estas hombreras, mortal. Que te brinden la protección que necesitas y que al verte infunda miedo en nuestros enemigos.', 0),
(8669, 'esES', 'De los materiales que traes y de las escamas de nuestros enemigos Qiraji caídos, te hago estas hombreras, mortal. Que te brinden la protección que necesitas y que al verte infunda miedo en nuestros enemigos.', 0),
(8659, 'esMX', 'De los materiales que traes y de las escamas de nuestros enemigos Qiraji caídos, te hago estas hombreras, mortal. Que te brinden la protección que necesitas y que al verte infunda miedo en nuestros enemigos.', 0),
(8664, 'esMX', 'De los materiales que traes y de las escamas de nuestros enemigos Qiraji caídos, te hago estas hombreras, mortal. Que te brinden la protección que necesitas y que al verte infunda miedo en nuestros enemigos.', 0),
(8669, 'esMX', 'De los materiales que traes y de las escamas de nuestros enemigos Qiraji caídos, te hago estas hombreras, mortal. Que te brinden la protección que necesitas y que al verte infunda miedo en nuestros enemigos.', 0);
-- Las calzas clamacondenas
-- 8663, 8668
-- https://es.classic.wowhead.com/quest=8663
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8663, 8668) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8663, 'esES', '¿Me trajiste los componentes que te pedí, $n?', 0),
(8668, 'esES', '¿Me trajiste los componentes que te pedí, $n?', 0),
(8663, 'esMX', '¿Me trajiste los componentes que te pedí, $n?', 0),
(8668, 'esMX', '¿Me trajiste los componentes que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8663, 8668) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8663, 'esES', 'Sí... la piel del gusano será una excelente capa protectora. Combinado con las partes más fuertes de los Qiraji que hemos destruido en nuestro camino hacia aquí, esto debería ser una formidable pieza de armadura. ¡Que te ayude a afrontar los horrores indescriptibles que te aguardan en el interior!', 0),
(8668, 'esES', 'Sí... la piel del gusano será una excelente capa protectora. Combinado con las partes más fuertes de los Qiraji que hemos destruido en nuestro camino hacia aquí, esto debería ser una formidable pieza de armadura. ¡Que te ayude a afrontar los horrores indescriptibles que te aguardan en el interior!', 0),
(8663, 'esMX', 'Sí... la piel del gusano será una excelente capa protectora. Combinado con las partes más fuertes de los Qiraji que hemos destruido en nuestro camino hacia aquí, esto debería ser una formidable pieza de armadura. ¡Que te ayude a afrontar los horrores indescriptibles que te aguardan en el interior!', 0),
(8668, 'esMX', 'Sí... la piel del gusano será una excelente capa protectora. Combinado con las partes más fuertes de los Qiraji que hemos destruido en nuestro camino hacia aquí, esto debería ser una formidable pieza de armadura. ¡Que te ayude a afrontar los horrores indescriptibles que te aguardan en el interior!', 0);
-- Tótem de Runa el Ancestro
-- 8670, 8671, 8672, 8673, 8674, 8675, 8676, 8677, 8678, 8679, 8680, 8681, 8682, 8683, 8684, 8685, 8686
-- https://es.wowhead.com/quest=8670
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8670, 8671, 8672, 8673, 8674, 8675, 8676, 8677, 8678, 8679, 8680, 8681, 8682, 8683, 8684, 8685, 8686) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8670, 'esES', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8671, 'esES', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8672, 'esES', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8673, 'esES', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8674, 'esES', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8675, 'esES', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8676, 'esES', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8677, 'esES', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8678, 'esES', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8679, 'esES', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8680, 'esES', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8681, 'esES', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8682, 'esES', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8683, 'esES', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8684, 'esES', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8685, 'esES', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8686, 'esES', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8670, 'esMX', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8671, 'esMX', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8672, 'esMX', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8673, 'esMX', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8674, 'esMX', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8675, 'esMX', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8676, 'esMX', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8677, 'esMX', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8678, 'esMX', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8679, 'esMX', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8680, 'esMX', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8681, 'esMX', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8682, 'esMX', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8683, 'esMX', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8684, 'esMX', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8685, 'esMX', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0),
(8686, 'esMX', 'Tu espíritu arde lleno de vida, joven $c. Acepto el homenaje que me rindes, y te ofrezco a cambio esta muestra...', 0);
-- 8687 Objetivo: los tuneladores de Colmen'Zora
-- https://es.classic.wowhead.com/quest=8687
SET @ID := 8687;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que decirme, $c?', 0),
(@ID, 'esMX', '¿Tienes algo que decirme, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. Sin sus tuneladores, los silítidos tendrán dificultades para reparar cualquier daño infligido a la estructura de su colmena. Supongo que querrás una nueva tarea.', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. Sin sus tuneladores, los silítidos tendrán dificultades para reparar cualquier daño infligido a la estructura de su colmena. Supongo que querrás una nueva tarea.', 0);
-- 8688 Fuerteviento el Ancestro
-- https://es.wowhead.com/quest=8688
SET @ID := 8688;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(@ID, 'esMX', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0);
-- El embozo de sabiduría infinita
-- 8689, 8690, 8691, 8692, 8693, 8694, 8695, 8696
-- https://es.classic.wowhead.com/quest=8689
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8689, 8690, 8691, 8692, 8693, 8694, 8695, 8696) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8689, 'esES', '¿Trajiste los materiales para la capa, $n?', 0),
(8690, 'esES', '¿Trajiste los materiales para la capa, $n?', 0),
(8691, 'esES', '¿Trajiste los materiales para la capa, $n?', 0),
(8692, 'esES', '¿Trajiste los materiales para la capa, $n?', 0),
(8693, 'esES', '¿Trajiste los materiales para la capa, $n?', 0),
(8694, 'esES', '¿Trajiste los materiales para la capa, $n?', 0),
(8695, 'esES', '¿Trajiste los materiales para la capa, $n?', 0),
(8696, 'esES', '¿Trajiste los materiales para la capa, $n?', 0),
(8689, 'esMX', '¿Trajiste los materiales para la capa, $n?', 0),
(8690, 'esMX', '¿Trajiste los materiales para la capa, $n?', 0),
(8691, 'esMX', '¿Trajiste los materiales para la capa, $n?', 0),
(8692, 'esMX', '¿Trajiste los materiales para la capa, $n?', 0),
(8693, 'esMX', '¿Trajiste los materiales para la capa, $n?', 0),
(8694, 'esMX', '¿Trajiste los materiales para la capa, $n?', 0),
(8695, 'esMX', '¿Trajiste los materiales para la capa, $n?', 0),
(8696, 'esMX', '¿Trajiste los materiales para la capa, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8689, 8690, 8691, 8692, 8693, 8694, 8695, 8696) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8689, 'esES', 'Ah, sí... este mantón está impecable.$B$BToma esta capa, $n. Que te proteja de la magia repugnante de los qiraji.', 0),
(8690, 'esES', 'Ah, sí... este mantón está impecable.$B$BToma esta capa, $n. Que te proteja de la magia repugnante de los qiraji.', 0),
(8691, 'esES', 'Ah, sí... este mantón está impecable.$B$BToma esta capa, $n. Que te proteja de la magia repugnante de los qiraji.', 0),
(8692, 'esES', 'Ah, sí... este mantón está impecable.$B$BToma esta capa, $n. Que te proteja de la magia repugnante de los qiraji.', 0),
(8693, 'esES', 'Ah, sí... este mantón está impecable.$B$BToma esta capa, $n. Que te proteja de la magia repugnante de los qiraji.', 0),
(8694, 'esES', 'Ah, sí... este mantón está impecable.$B$BToma esta capa, $n. Que te proteja de la magia repugnante de los qiraji.', 0),
(8695, 'esES', 'Ah, sí... este mantón está impecable.$B$BToma esta capa, $n. Que te proteja de la magia repugnante de los qiraji.', 0),
(8696, 'esES', 'Ah, sí... este mantón está impecable.$B$BToma esta capa, $n. Que te proteja de la magia repugnante de los qiraji.', 0),
(8689, 'esMX', 'Ah, sí... este mantón está impecable.$B$BToma esta capa, $n. Que te proteja de la magia repugnante de los qiraji.', 0),
(8690, 'esMX', 'Ah, sí... este mantón está impecable.$B$BToma esta capa, $n. Que te proteja de la magia repugnante de los qiraji.', 0),
(8691, 'esMX', 'Ah, sí... este mantón está impecable.$B$BToma esta capa, $n. Que te proteja de la magia repugnante de los qiraji.', 0),
(8692, 'esMX', 'Ah, sí... este mantón está impecable.$B$BToma esta capa, $n. Que te proteja de la magia repugnante de los qiraji.', 0),
(8693, 'esMX', 'Ah, sí... este mantón está impecable.$B$BToma esta capa, $n. Que te proteja de la magia repugnante de los qiraji.', 0),
(8694, 'esMX', 'Ah, sí... este mantón está impecable.$B$BToma esta capa, $n. Que te proteja de la magia repugnante de los qiraji.', 0),
(8695, 'esMX', 'Ah, sí... este mantón está impecable.$B$BToma esta capa, $n. Que te proteja de la magia repugnante de los qiraji.', 0),
(8696, 'esMX', 'Ah, sí... este mantón está impecable.$B$BToma esta capa, $n. Que te proteja de la magia repugnante de los qiraji.', 0);
-- El anillo de sabiduría infinita
-- 8697, 8698, 8699, 8700, 8701, 8702, 8703, 8704
-- https://es.classic.wowhead.com/quest=8697
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8697, 8698, 8699, 8700, 8701, 8702, 8703, 8704) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8697, 'esES', '¿Me trajiste el anillo y los materiales, $n?', 0),
(8698, 'esES', '¿Me trajiste el anillo y los materiales, $n?', 0),
(8699, 'esES', '¿Me trajiste el anillo y los materiales, $n?', 0),
(8700, 'esES', '¿Me trajiste el anillo y los materiales, $n?', 0),
(8701, 'esES', '¿Me trajiste el anillo y los materiales, $n?', 0),
(8702, 'esES', '¿Me trajiste el anillo y los materiales, $n?', 0),
(8703, 'esES', '¿Me trajiste el anillo y los materiales, $n?', 0),
(8704, 'esES', '¿Me trajiste el anillo y los materiales, $n?', 0),
(8697, 'esMX', '¿Me trajiste el anillo y los materiales, $n?', 0),
(8698, 'esMX', '¿Me trajiste el anillo y los materiales, $n?', 0),
(8699, 'esMX', '¿Me trajiste el anillo y los materiales, $n?', 0),
(8700, 'esMX', '¿Me trajiste el anillo y los materiales, $n?', 0),
(8701, 'esMX', '¿Me trajiste el anillo y los materiales, $n?', 0),
(8702, 'esMX', '¿Me trajiste el anillo y los materiales, $n?', 0),
(8703, 'esMX', '¿Me trajiste el anillo y los materiales, $n?', 0),
(8704, 'esMX', '¿Me trajiste el anillo y los materiales, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8697, 8698, 8699, 8700, 8701, 8702, 8703, 8704) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8697, 'esES', 'Cambiaré la gema del anillo por ti. Descubrirás que el efecto es mucho más... agradable.', 0),
(8698, 'esES', 'Cambiaré la gema del anillo por ti. Descubrirás que el efecto es mucho más... agradable.', 0),
(8699, 'esES', 'Cambiaré la gema del anillo por ti. Descubrirás que el efecto es mucho más... agradable.', 0),
(8700, 'esES', 'Cambiaré la gema del anillo por ti. Descubrirás que el efecto es mucho más... agradable.', 0),
(8701, 'esES', 'Cambiaré la gema del anillo por ti. Descubrirás que el efecto es mucho más... agradable.', 0),
(8702, 'esES', 'Cambiaré la gema del anillo por ti. Descubrirás que el efecto es mucho más... agradable.', 0),
(8703, 'esES', 'Cambiaré la gema del anillo por ti. Descubrirás que el efecto es mucho más... agradable.', 0),
(8704, 'esES', 'Cambiaré la gema del anillo por ti. Descubrirás que el efecto es mucho más... agradable.', 0),
(8697, 'esMX', 'Cambiaré la gema del anillo por ti. Descubrirás que el efecto es mucho más... agradable.', 0),
(8698, 'esMX', 'Cambiaré la gema del anillo por ti. Descubrirás que el efecto es mucho más... agradable.', 0),
(8699, 'esMX', 'Cambiaré la gema del anillo por ti. Descubrirás que el efecto es mucho más... agradable.', 0),
(8700, 'esMX', 'Cambiaré la gema del anillo por ti. Descubrirás que el efecto es mucho más... agradable.', 0),
(8701, 'esMX', 'Cambiaré la gema del anillo por ti. Descubrirás que el efecto es mucho más... agradable.', 0),
(8702, 'esMX', 'Cambiaré la gema del anillo por ti. Descubrirás que el efecto es mucho más... agradable.', 0),
(8703, 'esMX', 'Cambiaré la gema del anillo por ti. Descubrirás que el efecto es mucho más... agradable.', 0),
(8704, 'esMX', 'Cambiaré la gema del anillo por ti. Descubrirás que el efecto es mucho más... agradable.', 0);
-- El mazo de sabiduría infinita
-- 8705, 8706, 8707, 8708, 8709, 8710, 8711, 8712
-- https://es.classic.wowhead.com/quest=8705
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8705, 8706, 8707, 8708, 8709, 8710, 8711, 8712) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8705, 'esES', '¿Me trajiste los componentes que necesito, $n?', 0),
(8706, 'esES', '¿Me trajiste los componentes que necesito, $n?', 0),
(8707, 'esES', '¿Me trajiste los componentes que necesito, $n?', 0),
(8708, 'esES', '¿Me trajiste los componentes que necesito, $n?', 0),
(8709, 'esES', '¿Me trajiste los componentes que necesito, $n?', 0),
(8710, 'esES', '¿Me trajiste los componentes que necesito, $n?', 0),
(8711, 'esES', '¿Me trajiste los componentes que necesito, $n?', 0),
(8712, 'esES', '¿Me trajiste los componentes que necesito, $n?', 0),
(8705, 'esMX', '¿Me trajiste los componentes que necesito, $n?', 0),
(8706, 'esMX', '¿Me trajiste los componentes que necesito, $n?', 0),
(8707, 'esMX', '¿Me trajiste los componentes que necesito, $n?', 0),
(8708, 'esMX', '¿Me trajiste los componentes que necesito, $n?', 0),
(8709, 'esMX', '¿Me trajiste los componentes que necesito, $n?', 0),
(8710, 'esMX', '¿Me trajiste los componentes que necesito, $n?', 0),
(8711, 'esMX', '¿Me trajiste los componentes que necesito, $n?', 0),
(8712, 'esMX', '¿Me trajiste los componentes que necesito, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8705, 8706, 8707, 8708, 8709, 8710, 8711, 8712) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8705, 'esES', 'Lo has hecho bien, $n. Esta empuñadura es una obra maestra... el equilibrio es perfecto.$B$BToma tu arma, $n. ¡Esgrímela con confianza y vence a nuestros enemigos!', 0),
(8706, 'esES', 'Lo has hecho bien, $n. Esta empuñadura es una obra maestra... el equilibrio es perfecto.$B$BToma tu arma, $n. ¡Esgrímela con confianza y vence a nuestros enemigos!', 0),
(8707, 'esES', 'Lo has hecho bien, $n. Esta empuñadura es una obra maestra... el equilibrio es perfecto.$B$BToma tu arma, $n. ¡Esgrímela con confianza y vence a nuestros enemigos!', 0),
(8708, 'esES', 'Lo has hecho bien, $n. Esta empuñadura es una obra maestra... el equilibrio es perfecto.$B$BToma tu arma, $n. ¡Esgrímela con confianza y vence a nuestros enemigos!', 0),
(8709, 'esES', 'Lo has hecho bien, $n. Esta empuñadura es una obra maestra... el equilibrio es perfecto.$B$BToma tu arma, $n. ¡Esgrímela con confianza y vence a nuestros enemigos!', 0),
(8710, 'esES', 'Lo has hecho bien, $n. Esta empuñadura es una obra maestra... el equilibrio es perfecto.$B$BToma tu arma, $n. ¡Esgrímela con confianza y vence a nuestros enemigos!', 0),
(8711, 'esES', 'Lo has hecho bien, $n. Esta empuñadura es una obra maestra... el equilibrio es perfecto.$B$BToma tu arma, $n. ¡Esgrímela con confianza y vence a nuestros enemigos!', 0),
(8712, 'esES', 'Lo has hecho bien, $n. Esta empuñadura es una obra maestra... el equilibrio es perfecto.$B$BToma tu arma, $n. ¡Esgrímela con confianza y vence a nuestros enemigos!', 0),
(8705, 'esMX', 'Lo has hecho bien, $n. Esta empuñadura es una obra maestra... el equilibrio es perfecto.$B$BToma tu arma, $n. ¡Esgrímela con confianza y vence a nuestros enemigos!', 0),
(8706, 'esMX', 'Lo has hecho bien, $n. Esta empuñadura es una obra maestra... el equilibrio es perfecto.$B$BToma tu arma, $n. ¡Esgrímela con confianza y vence a nuestros enemigos!', 0),
(8707, 'esMX', 'Lo has hecho bien, $n. Esta empuñadura es una obra maestra... el equilibrio es perfecto.$B$BToma tu arma, $n. ¡Esgrímela con confianza y vence a nuestros enemigos!', 0),
(8708, 'esMX', 'Lo has hecho bien, $n. Esta empuñadura es una obra maestra... el equilibrio es perfecto.$B$BToma tu arma, $n. ¡Esgrímela con confianza y vence a nuestros enemigos!', 0),
(8709, 'esMX', 'Lo has hecho bien, $n. Esta empuñadura es una obra maestra... el equilibrio es perfecto.$B$BToma tu arma, $n. ¡Esgrímela con confianza y vence a nuestros enemigos!', 0),
(8710, 'esMX', 'Lo has hecho bien, $n. Esta empuñadura es una obra maestra... el equilibrio es perfecto.$B$BToma tu arma, $n. ¡Esgrímela con confianza y vence a nuestros enemigos!', 0),
(8711, 'esMX', 'Lo has hecho bien, $n. Esta empuñadura es una obra maestra... el equilibrio es perfecto.$B$BToma tu arma, $n. ¡Esgrímela con confianza y vence a nuestros enemigos!', 0),
(8712, 'esMX', 'Lo has hecho bien, $n. Esta empuñadura es una obra maestra... el equilibrio es perfecto.$B$BToma tu arma, $n. ¡Esgrímela con confianza y vence a nuestros enemigos!', 0);
-- Cantoestelar el Ancestro
-- 8713, 8714, 8715, 8716, 8717, 8718, 8719, 8720, 8721, 8722, 8723, 8724, 8725, 8726, 8727
-- https://es.classic.wowhead.com/quest=8713
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8713, 8714, 8715, 8716, 8717, 8718, 8719, 8720, 8721, 8722, 8723, 8724, 8725, 8726, 8727) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8713, 'esES', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8714, 'esES', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8715, 'esES', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8716, 'esES', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8717, 'esES', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8718, 'esES', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8719, 'esES', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8720, 'esES', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8721, 'esES', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8722, 'esES', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8723, 'esES', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8724, 'esES', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8725, 'esES', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8726, 'esES', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8727, 'esES', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8713, 'esMX', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8714, 'esMX', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8715, 'esMX', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8716, 'esMX', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8717, 'esMX', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8718, 'esMX', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8719, 'esMX', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8720, 'esMX', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8721, 'esMX', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8722, 'esMX', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8723, 'esMX', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8724, 'esMX', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8725, 'esMX', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8726, 'esMX', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0),
(8727, 'esMX', 'Los cielos, con sus incontables estrellas, guardan las respuestas a los misterios terrenales, $n. ¿Pueden entonces el sabio o el afortunado, mirar hacia arriba y descubrir la verdad?', 0);
-- 8728 Buenas y malas noticias
-- https://es.classic.wowhead.com/quest=8728
SET @ID := 8728;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las boyas de arcanita no se hacen solas, $n. Y NO, no puedes pedir dinero prestado.', 0),
(@ID, 'esMX', 'Las boyas de arcanita no se hacen solas, $n. Y NO, no puedes pedir dinero prestado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trato es un trato. Espero que sepas en lo que te estás metiendo, $n. Esto es un gran problema de pesca.', 0),
(@ID, 'esMX', 'Un trato es un trato. Espero que sepas en lo que te estás metiendo, $n. Esto es un gran problema de pesca.', 0);
-- 8729 La cólera de Neptulon
-- https://es.classic.wowhead.com/quest=8729
SET @ID := 8729;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El tiempo se acaba, $gcampeón:campeona;.', 0),
(@ID, 'esMX', 'El tiempo se acaba, $gcampeón:campeona;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Pronto podré reformar el cetro de las arenas movedizas.', 0),
(@ID, 'esMX', 'Bien hecho, $n. Pronto podré reformar el cetro de las arenas movedizas.', 0);
-- 8730 La corrupción de Nefarius
-- https://es.classic.wowhead.com/quest=8730
SET @ID := 8730;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Otro de nuestros héroes perdió ante el engendro de Alamuerte. Seremos maldecidos con este sufrimiento para siempre...', 0),
(@ID, 'esMX', 'Otro de nuestros héroes perdió ante el engendro de Alamuerte. Seremos maldecidos con este sufrimiento para siempre...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El alma de Vaelastrasz está en paz, $gcampeón:campeona;. Todos los Aspectos observan tu progreso con gran interés. Debes saber que tiene aliados poderosos.$B$BSe me ordenó que te conceda algo que te ayude en esta lucha. Úsalo bien...', 0),
(@ID, 'esMX', 'El alma de Vaelastrasz está en paz, $gcampeón:campeona;. Todos los Aspectos observan tu progreso con gran interés. Debes saber que tiene aliados poderosos.$B$BSe me ordenó que te conceda algo que te ayude en esta lucha. Úsalo bien...', 0);
