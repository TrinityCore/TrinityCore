-- 372 En guerra con la Cruzada Escarlata
-- https://es.classic.wowhead.com/quest=372
SET @ID := 372;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aún no has cumplido con tu deber, $c. No podemos esperar llevar a cabo el plan de La Dama Oscura con la Cruzada Escarlata molestando a nuestros soldados. ¡Haz que mueran y cumple tu deber con Sylvanas!', 0),
(@ID, 'esMX', 'Aún no has cumplido con tu deber, $c. No podemos esperar llevar a cabo el plan de La Dama Oscura con la Cruzada Escarlata molestando a nuestros soldados. ¡Haz que mueran y cumple tu deber con Sylvanas!', 0);
-- 498 El rescate
-- https://es.classic.wowhead.com/quest=498
SET @ID := 498;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Rescata a Drull', `ObjectiveText2` = 'Rescata a Tog\'thar', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes darte prisa, $c. Me estremezco al pensar en lo que los humanos podrían estar haciendo con Drull y Tog\'thar.', 0),
(@ID, 'esMX', 'Debes darte prisa, $c. Me estremezco al pensar en lo que los humanos podrían estar haciendo con Drull y Tog\'thar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que los humanos querían esclavizarnos, ¿eh? ¡Eso ya lo veremos!$B$BParece que han trasladado a Gol\'dir; debemos encontrarlo y rescatarlo.$B$BTe avisaré cuando tengamos alguna pista de su paradero.', 0),
(@ID, 'esMX', 'Así que los humanos querían esclavizarnos, ¿eh? ¡Eso ya lo veremos!$B$BParece que han trasladado a Gol\'dir; debemos encontrarlo y rescatarlo.$B$BTe avisaré cuando tengamos alguna pista de su paradero.', 0);
-- 499 Elixir de sufrimiento
-- https://es.classic.wowhead.com/quest=499
SET @ID := 499;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Croac!', 0),
(@ID, 'esMX', '¡Croac!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Croac!', 0),
(@ID, 'esMX', '¡Croac!', 0);
-- 501 Elixir de dolor
-- https://es.classic.wowhead.com/quest=501
SET @ID := 501;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí, $n; ibas a ayudarme con mi elixir. Necesito la sangre para extender el dolor y la muerte en Trabalomas.', 0),
(@ID, 'esMX', 'Ah, sí, $n; ibas a ayudarme con mi elixir. Necesito la sangre para extender el dolor y la muerte en Trabalomas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n.', 0),
(@ID, 'esMX', 'Excelente trabajo, $n.', 0);
-- 502 Elixir de dolor
-- https://es.classic.wowhead.com/quest=502
SET @ID := 502;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Guau.', 0),
(@ID, 'esMX', 'Guau.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te pones un poco de elixir en el hueco de la mano y se lo das a Stanley.', 0),
(@ID, 'esMX', 'Te pones un poco de elixir en el hueco de la mano y se lo das a Stanley.', 0);
-- 503 Gol'dir
-- https://es.classic.wowhead.com/quest=503
SET @ID := 503;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dame la llave, $c, ya me ocupo yo.', 0),
(@ID, 'esMX', 'Dame la llave, $c, ya me ocupo yo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Yo dirigía la expedición desde Durotar bajo las órdenes del Jefe de Guerra, pero como ves las cosas no han salido como esperábamos. Me han tenido cautivo en su ciudad realizando trabajos forzados.$B$BPero mi sufrimiento no es importante; tengo información que debes llevar de inmediato a quien sea que nos lidera ahora.', 0),
(@ID, 'esMX', 'Gracias, $n. Yo dirigía la expedición desde Durotar bajo las órdenes del Jefe de Guerra, pero como ves las cosas no han salido como esperábamos. Me han tenido cautivo en su ciudad realizando trabajos forzados.$B$BPero mi sufrimiento no es importante; tengo información que debes llevar de inmediato a quien sea que nos lidera ahora.', 0);
-- 506 El legado de Lodonegro
-- https://es.classic.wowhead.com/quest=506
SET @ID := 506;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Pero cómo se atreven esos humanos!$B$BAhora, además de recoger el abalorio para el Jefe de Guerra, nos ocuparemos de demostrarles que no nos someteremos nunca.', 0),
(@ID, 'esMX', '¡Pero cómo se atreven esos humanos!$B$BAhora, además de recoger el abalorio para el Jefe de Guerra, nos ocuparemos de demostrarles que no nos someteremos nunca.', 0);
-- 507 Lord Aliden Perenolde
-- https://es.classic.wowhead.com/quest=507
SET @ID := 507;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Q-que quieres?', 0),
(@ID, 'esMX', '¿Q-que quieres?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No me hagas daño! ¡Yo no he hecho nada, me tenía retenida! ¡Piedad, te lo ruego!', 0),
(@ID, 'esMX', '¡No me hagas daño! ¡Yo no he hecho nada, me tenía retenida! ¡Piedad, te lo ruego!', 0);
-- 508 Un regalo de Taretha
-- https://es.classic.wowhead.com/quest=508
SET @ID := 508;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto, $n. ¿Algún éxito que comunicar?', 0),
(@ID, 'esMX', 'Has vuelto, $n. ¿Algún éxito que comunicar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es extraño que el Jefe de Guerra se gaste tanto en una cosa tan pequeña. No puedo decir que lo entienda pero acataré sus órdenes, sean las que sean. Lo has hecho muy bien, $n, seguro que el Jefe de Guerra se alegrará de conocer tu éxito.', 0),
(@ID, 'esMX', 'Es extraño que el Jefe de Guerra se gaste tanto en una cosa tan pequeña. No puedo decir que lo entienda pero acataré sus órdenes, sean las que sean. Lo has hecho muy bien, $n, seguro que el Jefe de Guerra se alegrará de conocer tu éxito.', 0);
-- 509 Elixir de agonía
-- https://es.classic.wowhead.com/quest=509
SET @ID := 509;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tal en Granja Nethander?', 0),
(@ID, 'esMX', '¿Qué tal en Granja Nethander?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Detesto la peste de las flores de morrobarro. Al menos esos asquerosos gnolls sirven para algo.', 0),
(@ID, 'esMX', 'Detesto la peste de las flores de morrobarro. Al menos esos asquerosos gnolls sirven para algo.', 0);
-- 513 Elixir de agonía
-- https://es.classic.wowhead.com/quest=513
SET @ID := 513;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No ves que estoy ocupado, $c? La Dama Oscura quiere que prepare una nueva plaga antes de que la Plaga nos invada desde Rasganorte. Los humanos amenazan desde el sur y a mí me falta el tiempo. ¡Espero que esto sea importante!', 0),
(@ID, 'esMX', '¿No ves que estoy ocupado, $c? La Dama Oscura quiere que prepare una nueva plaga antes de que la Plaga nos invada desde Rasganorte. Los humanos amenazan desde el sur y a mí me falta el tiempo. ¡Espero que esto sea importante!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que te envía el boticario Lydon? ¡Haberlo dicho!$B$BPese a su pesimismo innato, es uno de los mejores.$B$B¡Y me envía compuesto de Morrobarro! Me gusta su línea de pensamiento. La Dama Oscura estará muy complacida con los avances en la nueva peste.', 0),
(@ID, 'esMX', '¿Que te envía el boticario Lydon? ¡Haberlo dicho!$B$BPese a su pesimismo innato, es uno de los mejores.$B$B¡Y me envía compuesto de Morrobarro! Me gusta su línea de pensamiento. La Dama Oscura estará muy complacida con los avances en la nueva peste.', 0);
-- 515 Elixir de agonía
-- https://es.classic.wowhead.com/quest=515
SET @ID := 515;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de verte, $n. Me estaba aburriendo mortalmente, sin nada que hacer salvo envenenar y reanimar a Umpi una y otra vez.$B$B¿Qué tal en Entrañas? ¿Pudiste eliminar a muchos humanos?', 0),
(@ID, 'esMX', 'Me alegro de verte, $n. Me estaba aburriendo mortalmente, sin nada que hacer salvo envenenar y reanimar a Umpi una y otra vez.$B$B¿Qué tal en Entrañas? ¿Pudiste eliminar a muchos humanos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por fin, algo con lo que entretenerme! Gracias por tu ayuda, $n. ¡Vamos a extender la muerte y la enfermedad por el lugar!', 0),
(@ID, 'esMX', '¡Por fin, algo con lo que entretenerme! Gracias por tu ayuda, $n. ¡Vamos a extender la muerte y la enfermedad por el lugar!', 0);
 -- 516 El Desafío de Beren
-- https://es.classic.wowhead.com/quest=516
SET @ID := 516;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has localizado su base, $n? ¡El tiempo es esencial!', 0),
(@ID, 'esMX', '¿Ya has localizado su base, $n? ¡El tiempo es esencial!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si nuestros exploradores y agentes continúan proporcionándonos información valiosa como esta, tendremos a la Plaga del rey Exánime fuera de nuestras tierras en un abrir y cerrar de ojos.', 0),
(@ID, 'esMX', 'Si nuestros exploradores y agentes continúan proporcionándonos información valiosa como esta, tendremos a la Plaga del rey Exánime fuera de nuestras tierras en un abrir y cerrar de ojos.', 0);
-- 517 Elixir de agonía
-- https://es.classic.wowhead.com/quest=517
SET @ID := 517;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A veces me aburro tanto aquí en Molino Tarren que me da por probar cócteles de químicos. Pero Umpi se pone nerviosa.$B$BBueno, ¿traes el barril? Si no enveneno pronto a alguien con mi elixir mortal me va a dar un ataque.', 0),
(@ID, 'esMX', 'A veces me aburro tanto aquí en Molino Tarren que me da por probar cócteles de químicos. Pero Umpi se pone nerviosa.$B$BBueno, ¿traes el barril? Si no enveneno pronto a alguien con mi elixir mortal me va a dar un ataque.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por fin podemos pasar a la acción!', 0),
(@ID, 'esMX', '¡Por fin podemos pasar a la acción!', 0);
 -- 518 Corona de Voluntad
-- https://es.classic.wowhead.com/quest=518
SET @ID := 518;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Observo que tu tarea está inconclusa, $n. ¿Debo informar a Sharlindra de tu ineptitud?', 0),
(@ID, 'esMX', 'Observo que tu tarea está inconclusa, $n. ¿Debo informar a Sharlindra de tu ineptitud?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La nieve está roja con la sangre de los ogros, pero no debemos cejar hasta que los Aplastacresta muerdan el polvo y sean aniquilados por completo.', 0),
(@ID, 'esMX', 'La nieve está roja con la sangre de los ogros, pero no debemos cejar hasta que los Aplastacresta muerdan el polvo y sean aniquilados por completo.', 0);
-- 519 Corona de Voluntad
-- https://es.classic.wowhead.com/quest=519
SET @ID := 519;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, quiero cabezas, no excusas.', 0),
(@ID, 'esMX', '$n, quiero cabezas, no excusas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Y yo que creía que lo peor de los ogros era el olor.$B$BCuando me traigas la cabeza de Jarra\'thol, clavaré las 4 cabezas en picas; será un aviso para los que contrarían a la Dama Oscura.', 0),
(@ID, 'esMX', 'Y yo que creía que lo peor de los ogros era el olor.$B$BCuando me traigas la cabeza de Jarra\'thol, clavaré las 4 cabezas en picas; será un aviso para los que contrarían a la Dama Oscura.', 0);
-- 520 Corona de Voluntad
-- https://es.classic.wowhead.com/quest=520
SET @ID := 520;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo 3 cabezas, me falta una. Si no es la de Jarra\'thol, será la tuya, $n; tenlo por seguro.', 0),
(@ID, 'esMX', 'Tengo 3 cabezas, me falta una. Si no es la de Jarra\'thol, será la tuya, $n; tenlo por seguro.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. La cabeza de Jarra\'thol adornará la cumbre más alta de las Ruinas de Alterac y la Guardia de la Muerte acabará de exterminar a los Aplastacresta.', 0),
(@ID, 'esMX', 'Bien hecho, $n. La cabeza de Jarra\'thol adornará la cumbre más alta de las Ruinas de Alterac y la Guardia de la Muerte acabará de exterminar a los Aplastacresta.', 0);
-- 521 Corona de Voluntad
-- https://es.classic.wowhead.com/quest=521
SET @ID := 521;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? ¿Tienes alguna noticia?', 0),
(@ID, 'esMX', '¿Sí? ¿Tienes alguna noticia?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que esto es lo que usó el ogro para enfrentarse a la Dama Oscura.$B$BCuesta creer que algo tan sencillo tenga tanto poder. Buen trabajo, $n. Entregaré la corona a Lady Sylvanas y le hablaré de tu proeza.', 0),
(@ID, 'esMX', 'Así que esto es lo que usó el ogro para enfrentarse a la Dama Oscura.$B$BCuesta creer que algo tan sencillo tenga tanto poder. Buen trabajo, $n. Entregaré la corona a Lady Sylvanas y le hablaré de tu proeza.', 0);
-- 524 Elixir de agonía
-- https://es.classic.wowhead.com/quest=524
SET @ID := 524;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La alfombra huele a moho.', 0),
(@ID, 'esMX', 'La alfombra huele a moho.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dejas el barril contaminado en la alfombra polvorienta.', 0),
(@ID, 'esMX', 'Dejas el barril contaminado en la alfombra polvorienta.', 0);
-- 526 Lingotes Forjaluz
-- https://es.classic.wowhead.com/quest=526
SET @ID := 526;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste el hierro Forjaluz que necesitas?', 0),
(@ID, 'esMX', '¿Encontraste el hierro Forjaluz que necesitas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, los encontraste! Ahora hagamos que este hierro Forjaluz se convierta en algo útil, ¿eh?', 0),
(@ID, 'esMX', '¡Ah, los encontraste! Ahora hagamos que este hierro Forjaluz se convierta en algo útil, ¿eh?', 0);
-- 527 La batalla de Trabalomas
-- https://es.classic.wowhead.com/quest=527
SET @ID := 527;
UPDATE `quest_template_locale` SET `Details` = 'Ponte firme cuando te dirijas a mí, $c.$B$BEstoy a las órdenes directas de Varimathras. Debemos sofocar la infestación humana hasta que nuestros boticarios desarrollen la nueva plaga.$B$BNuestros datos indican que Trabalomas es vulnerable. Tu primera misión es interrumpir el abastecimiento de alimentos y su infraestructura.$B$BVe hacia el oeste. Ataca las granjas más septentrionales de Campos de Trabalomas. Asegúrate de que los propietarios, el granjero Ray y el granjero Getz, son ejecutados.', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Como Alto Ejecutor de Molino Tarren, bajo el mando directo de Varimathras y la Dama Oscura, estás sujeto a seguir mis órdenes.$B$B¿Quizás te tomas a la ligera esta guerra con la Alianza? Si ese es el caso, debería decapitarte aquí y ahora. De lo contrario, viaja hacia el oeste hasta la ciudad de Trabalomas y libra una batalla contra los humanos, como te lo ordenaron.$B$BLárgate.', 0),
(@ID, 'esMX', 'Como Alto Ejecutor de Molino Tarren, bajo el mando directo de Varimathras y la Dama Oscura, estás sujeto a seguir mis órdenes.$B$B¿Quizás te tomas a la ligera esta guerra con la Alianza? Si ese es el caso, debería decapitarte aquí y ahora. De lo contrario, viaja hacia el oeste hasta la ciudad de Trabalomas y libra una batalla contra los humanos, como te lo ordenaron.$B$BLárgate.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Descansa, $c. Mis fuentes me indican que luchaste bien en el frente de Trabalomas.', 0),
(@ID, 'esMX', 'Descansa, $c. Mis fuentes me indican que luchaste bien en el frente de Trabalomas.', 0);
