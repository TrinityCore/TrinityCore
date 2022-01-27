-- 65 La hermandad de los Defias
-- https://es.classic.wowhead.com/quest=65
SET @ID := 65;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Así que vienes de parte de Mantorrecio? Bien, estoy en deuda con él.', 0);

-- 14 La Milicia Popular
-- https://es.classic.wowhead.com/quest=14
SET @ID := 14;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '$n, ahora no hay tiempo para charlas. Si aún deseas demostrar tu valía ante la Milicia Popular, debes matar a los Defias que te indiqué anteriormente. Vuelve a mí cuando hayas completado tu deber.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Cuando dejé las tierras malditas de Lordaeron, regresé para encontrar mi patria sumida en una situación desalentadora. Pero aún hay esperanza para los Páramos de Poniente. Has demostrado tu valor en la batalla, y es evidente que sirves con honor a nuestra causa. Me es por ello un gran honor ordenarte como miembro de Las Milicias del Pueblo. Que la Luz guíe siempre tu camino.', 0);

-- 1780 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1780
SET @ID := 1780;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Qué pronto has vuelto, $n. ¿Y qué has conseguido en este tiempo que no has estado en la Catedral?$B$B¿Has conseguido ayudar en alguna noble causa? Quizás hayas aprendido el valor de la caridad o algo más sobre tus obligaciones para con los habitantes de Azeroth. Dime a quién has ayudado y cómo... Vaya, estoy impresionado, $n, las tuyas son sin duda acciones de alguien que sigue el camino de la Luz y antepone el bien de los demás al propio.$B$BTu sacrificio se verá recompensado con el tiempo.', 0);

-- 1781 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1781
SET @ID := 1781;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '*tose*$B$BEs un placer conocerte, $r. No prestes atención a mis heridas. Este buen sacerdote se ocupará del viejo Gazin. No necesitaré el poder de ese Símbolo de la Vida que has traído... al menos, no todavía.$B$BAsí que te envía Duthorian, ¿eh? Muy bien. Te diré exactamente lo que nos ocurrió a mí y a mi amigo Henze. Y, con un poco de suerte y algo de habilidad por tu parte, quizás puedas ayudarnos a todos.', 0);

-- 1786 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1786
SET @ID := 1786;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias, $ghermano:hermana;.$B$BVeo que portas el Símbolo de la Vida, ¿puedo deducir de eso que te envían Duthorian o Gazin?$B$BCaí ante los hechizos de los Defias cuando Gazin y yo intentábamos hacernos con sus planes. Conseguí aguantar el tiempo suficiente para que Gazin escapara, pero al final, su magia me superó.$B$BY entonces llegaste tú y me trajiste de nuevo a la vida. La habilidad de utilizar el Símbolo no la tiene cualquiera, $n. Debes apreciar lo que significa que pudieras utilizarlo con ayuda de tu fe.', 0);

-- 1787 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1787
SET @ID := 1787;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Henze está a salvo, $n? ¿Tuviste éxito?$B$BEntre tu habilidad con las armas y el poder de la Luz, creo que la Vigilia de los Héroes estará a salvo de cualquier amenaza de los Defias, pero eso deben decirlo el Rey y sus consejeros.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Estupendo! Lo has conseguido, has salvado a Henze. ¡Es evidente que la Luz está en ti, $n!', 0);

-- 1788 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1788
SET @ID := 1788;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Has actuado bien, $n. Deberías enorgullecerte de lo que has conseguido.$B$BDeberías estar $gorgulloso:orgullosa; de tus habilidades. No todo el mundo puede utilizar el poder del Símbolo de la Vida. Si puedes invocar a la Luz para devolver a los muertos a la vida, es que estás $gpreparado:preparada; para uno de los mayores honores de los paladines: el poder de resucitar.$B$BPodrás devolver a la vida a compañeros caídos, tal y como hiciste con Henze.$B$BCuídate, $n. La Luz te ilumina. Recíbela en ti.', 0);

-- 399 Principios humildes
-- https://es.classic.wowhead.com/quest=399
SET @ID := 399;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡$n! ¿Has tenido suerte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Oh, muchas gracias, $n! No me sirve de nada, pero el valor sentimental... No hace falta que te dé las gracias por traerme esto... y veo que has tenido que sufrir algún que otro percance para conseguirlo, sin mencionar el tiempo que has perdido yendo a Páramos de Poniente. Tienes mi gratitud. Acepta esto como muestra de ello.', 0);

-- 353 Una entrega a Pico Tormenta
-- https://es.wowhead.com/quest=353
-- https://wow-es.gamepedia.com/Misión:Una entrega a Pico Tormenta
SET @ID := 353;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has venido hasta aquí desde Ventormenta? He oído que las cosas se están poniendo feas en las tierras humanas, con forajidos y orcos campando a sus anchas. ¡Un lugar perfecto para que un $c demuestre su valía!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Ajá! ¿Así que Grimand ha terminado mi hacha por fin? ¡Me muero por probarla con algunos troggs y kóbolds!$B$BMuchas gracias, $n. Has hecho un largo viaje para entregármela. Acepta unas monedas por tu trabajo.', 0);

-- 6661 A por las ratas del tranvía subterráneo
-- https://es.wowhead.com/quest=6661
SET @ID := 6661;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Eeeh... pillastre, ¿por qué tardas tanto tiempo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Esto va bien, $gamigo:amiga;. Mi hermano las necesita vivitas y coleando, de lo contrario se ponen amargas ... No querrás probar ninguna brocheta de rata agria.', 0);

-- 6662 Mi hermano Niblis
-- https://es.wowhead.com/quest=6662
-- https://wow-es.gamepedia.com/Misión:Mi hermano Niblis
SET @ID := 6662;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '<Nipsy pone su dedo índice a través de uno de los agujeros de aire en el cartón.>$B$BVivo y coleando... ¡y justo a tiempo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Pobre Monty. Desde el incidente de Gnomeregan, no ha sido el mismo. Ese niño nunca ha visto un océano en su vida, y mucho menos ser una especie de pirata.$B$B<Nipsy suspira.>$B$BAl menos mantiene el flujo de las criaturas retorciéndose.', 0);

-- 117 Cerveza Cebatruenos
-- https://es.classic.wowhead.com/quest=117
SET @ID := 117;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Rápido, $gamigo:amiga; y date prisa$BNuestra cerveza está de risa$BMás cerveza y menos comida,$BDadnos lúpulo para hacer birra.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Lúpulo y cebada, malta y levadura$BNi te imaginas cómo se disfruta,$B$BDeja de pedir, deja de gemir$B¡La cerveza Cebatruenos ya viene en su barril!', 0);

-- 103 Guardián de la Llama
-- https://es.classic.wowhead.com/quest=103
SET @ID := 103;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'La llama no arderá mucho tiempo sin aceite, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Loado seas, valiente $c. Las rocas de la Costa de los Páramos de Poniente estarán iluminadas gracias a ti. Mientras la antorcha esté iluminada se salvarán muchas vidas.', 0);

-- 104 La amenaza costera
-- https://es.classic.wowhead.com/quest=104
SET @ID := 104;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Aún no has conseguido aniquilar a la amenaza conocida como Viejo Ojosombrío? Ha sido visto recorriendo la costa de los Páramos de Poniente.$B$BVuelve a verme cuando esa bestia esté muerta.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Así que el infecto pagano Ojosombrío está muerto. Bien hecho, $n. Tus manos han dado fin a una vida, pero han podido salvar muchas otras. El Mare Magnum, aun tan lleno de peligros como está, será algo más seguro esta noche gracias a tus hazañas.', 0);

-- 152 Hay moros en la costa
-- https://es.classic.wowhead.com/quest=152
SET @ID := 152;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Mata 7 cazamareas, 7 guerreros, 7 oráculos y 7 correcostas y procuraré que seas $grecompensado:recompensada;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Bien hecho, $n. Tienes talento para el combate. Gracias a ti, la Costa de los Páramos de Poniente es un lugar más seguro.', 0);
