-- 1785 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1785
SET @ID := 1785;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hoy has hecho un gran favor a todo Forjaz, $n. Me enorgullece contarte entre los nuestros y, si te sientes $gpreparado:preparada;, quisiera bendecirte con este pergamino. El Símbolo de la Vida solo habría funcionado en manos de $gun:una; $c que estuviera $glisto:lista; para una de las mayores bendiciones de la Luz: el poder de devolver la vida a los muertos.$B$BTe enseñaré cómo resucitar a tus compañeros. Utiliza ese don con sabiduría, $n. Te doy las gracias, también de parte de mi marido y de Forjaz.', 0),
(@ID, 'esMX', 'Hoy has hecho un gran favor a todo Forjaz, $n. Me enorgullece contarte entre los nuestros y, si te sientes $gpreparado:preparada;, quisiera bendecirte con este pergamino. El Símbolo de la Vida solo habría funcionado en manos de $gun:una; $c que estuviera $glisto:lista; para una de las mayores bendiciones de la Luz: el poder de devolver la vida a los muertos.$B$BTe enseñaré cómo resucitar a tus compañeros. Utiliza ese don con sabiduría, $n. Te doy las gracias, también de parte de mi marido y de Forjaz.', 0);
-- 1789 El Símbolo de la Vida
-- https://es.classic.wowhead.com/quest=1789
SET @ID := 1789;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Date prisa, $n, más de una vida está en juego si fallas.$B$BSi por alguna razón no ayudas a Muiredon y Narm, vuelve a verme y te daré otro Símbolo de Vida para tus viajes.$B$BNo confundas mi ayuda con una simple caridad, debes demostrar que eres digno como cualquier otro $c y el fracaso continuo puede reflejarse en ti más adelante.', 0),
(@ID, 'esMX', 'Date prisa, $n, más de una vida está en juego si fallas.$B$BSi por alguna razón no ayudas a Muiredon y Narm, vuelve a verme y te daré otro Símbolo de Vida para tus viajes.$B$BNo confundas mi ayuda con una simple caridad, debes demostrar que eres digno como cualquier otro $c y el fracaso continuo puede reflejarse en ti más adelante.', 0);
-- 1791 El Vigía del viento
-- https://es.classic.wowhead.com/quest=1791
SET @ID := 1791;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho un largo viaje, joven $c. Veo fuego en tu mirada. Buscas un arma de gran poder, ¿verdad?$B$BPuedo ayudarte en tu búsqueda. Y tú puedes ayudarme en la mía.', 0),
(@ID, 'esMX', 'Has hecho un largo viaje, joven $c. Veo fuego en tu mirada. Buscas un arma de gran poder, ¿verdad?$B$BPuedo ayudarte en tu búsqueda. Y tú puedes ayudarme en la mía.', 0);
-- 1792 Arma torbellino
-- https://es.classic.wowhead.com/quest=1792
SET @ID := 1792;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo el corazón de torbellino y ya puedo colocarlo en el recipiente que elijas.$B$BElige tu arma, $n, y no olvides que su poder será el poder del Ciclonio.', 0),
(@ID, 'esMX', 'Tengo el corazón de torbellino y ya puedo colocarlo en el recipiente que elijas.$B$BElige tu arma, $n, y no olvides que su poder será el poder del Ciclonio.', 0);
-- 1795 El vínculo
-- https://es.classic.wowhead.com/quest=1795
SET @ID := 1795;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todo $c tiene un manáfago bajo su mando. Aunque cuesta mucho amaestrarlo, el poder que le otorga a su amo compensa en mucho el esfuerzo.', 0),
(@ID, 'esMX', 'Todo $c tiene un manáfago bajo su mando. Aunque cuesta mucho amaestrarlo, el poder que le otorga a su amo compensa en mucho el esfuerzo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debo decir que estoy impresionado, $n. Cuando me enfrenté a mi primer manáfago, salí con vida de milagro. Presiento que tienes el potencial para convertirte en $guno de los más poderosos brujos:una de las más poderosas brujas; de esta era.', 0),
(@ID, 'esMX', 'Debo decir que estoy impresionado, $n. Cuando me enfrenté a mi primer manáfago, salí con vida de milagro. Presiento que tienes el potencial para convertirte en $guno de los más poderosos brujos:una de las más poderosas brujas; de esta era.', 0);
-- 1796 Los componentes para la toga de sangre dorada encantada
-- https://es.classic.wowhead.com/quest=1796
SET @ID := 1796;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va tu búsqueda de las túnicas, $n? ¿Las has hecho tú mismo? Encuentro que tales toques personales les confieren una magia aún más dulce. Te da un sentido de logro aún mayor. Pero entiendo que si has elegido la vía más rápida y has pedido que te las confeccionen, se puede decir algo de semejante... ambición.', 0),
(@ID, 'esMX', '¿Cómo va tu búsqueda de las túnicas, $n? ¿Las has hecho tú mismo? Encuentro que tales toques personales les confieren una magia aún más dulce. Te da un sentido de logro aún mayor. Pero entiendo que si has elegido la vía más rápida y has pedido que te las confeccionen, se puede decir algo de semejante... ambición.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto me servirá, $n.$B$BTodos los objetos mágicos deben empezar con un objeto de gran calidad. Cuanto más esfuerzo y habilidad se ponga en confeccionarlo, mayor será la magia que pueda contener. Los componentes raros y caros mantienen mejor la magia. No te arrepentirás de que tus togas se conviertan en las que te haremos más tarde.', 0),
(@ID, 'esMX', 'Esto me servirá, $n.$B$BTodos los objetos mágicos deben empezar con un objeto de gran calidad. Cuanto más esfuerzo y habilidad se ponga en confeccionarlo, mayor será la magia que pueda contener. Los componentes raros y caros mantienen mejor la magia. No te arrepentirás de que tus togas se conviertan en las que te haremos más tarde.', 0);
-- 1798 Buscando a Strahad
-- https://es.classic.wowhead.com/quest=1798
SET @ID := 1798;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿$n? Ah sí, por supuesto. Nuestro último prodigio. Me temo que la realidad no está a la altura de la leyenda.$B$BNo importa, has venido a aprender, no a escuchar mis chistes malos.', 0),
(@ID, 'esMX', '¿$n? Ah sí, por supuesto. Nuestro último prodigio. Me temo que la realidad no está a la altura de la leyenda.$B$BNo importa, has venido a aprender, no a escuchar mis chistes malos.', 0);
-- 1799 Los trozos del orbe de Orahil
-- https://es.classic.wowhead.com/quest=1799
SET @ID := 1799;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Y claro, si no eres un mago, me pregunto si puedo fiarme de ti. Puedo oler el poder arcano en ti pero pareces haber eludido el hedor de la corrupción que con tanta facilidad alcanza a los de tu clase.$B$BSí, tú, $c... $gun:una; $c ha venido a pedirme ayuda.$B$BBien, ¿qué puedo hacer por ti, $n?', 0),
(@ID, 'esMX', 'Y claro, si no eres un mago, me pregunto si puedo fiarme de ti. Puedo oler el poder arcano en ti pero pareces haber eludido el hedor de la corrupción que con tanta facilidad alcanza a los de tu clase.$B$BSí, tú, $c... $gun:una; $c ha venido a pedirme ayuda.$B$BBien, ¿qué puedo hacer por ti, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, así que te envía Menara. Vale... Supongo que puedes quedarte como $ginvitado:invitada; por ahora. Pero debes estar detrás de algún asunto urgente, ¿en busca de poder perdido quizás? A lo mejor me equivoco. A lo mejor la corrupción ni se te ha acercado después de todo.', 0),
(@ID, 'esMX', 'Oh, así que te envía Menara. Vale... Supongo que puedes quedarte como $ginvitado:invitada; por ahora. Pero debes estar detrás de algún asunto urgente, ¿en busca de poder perdido quizás? A lo mejor me equivoco. A lo mejor la corrupción ni se te ha acercado después de todo.', 0);
-- 1800 Sala del Trono de Lordaeron
-- https://es.classic.wowhead.com/quest=1800
SET @ID := 1800;
UPDATE `quest_template_locale` SET `Objectives` = 'Lleva a tu pupilo a la antigua Sala del Trono de Lordaeron. La encontrarás justo antes de llegar al acceso a Entrañas.', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya llegamos?', 0),
(@ID, 'esMX', '¿Ya llegamos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esa sala del trono daba mucho miedo, $n! Aunque estaba vacía pude sentir que allí había ocurrido algo muy malo. Me sentí mal... y triste. Ya entiendo porqué las supervisoras nos cuentan esas historias, ¡yo nunca traicionaré así a mi pueblo!$B$BGracias por traerme a la sala del trono, $n. He aprendido mucho.', 0),
(@ID, 'esMX', '¡Esa sala del trono daba mucho miedo, $n! Aunque estaba vacía pude sentir que allí había ocurrido algo muy malo. Me sentí mal... y triste. Ya entiendo porqué las supervisoras nos cuentan esas historias, ¡yo nunca traicionaré así a mi pueblo!$B$BGracias por traerme a la sala del trono, $n. He aprendido mucho.', 0);
-- 1801 Libro del conciliábulo
-- https://es.classic.wowhead.com/quest=1801
SET @ID := 1801;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Elaboración de mapas! Imágenes, estimaciones de la realidad. No tengo ningún uso para esas cosas.$B$B¡En libros, narrativa, descripción! Ahí es donde está la verdad. Cambiaría todos los mapas de esta tienda por un libro sobre el auge de la nigromancia o una historia del triunfo de la Dama Oscura.', 0),
(@ID, 'esMX', '¡Elaboración de mapas! Imágenes, estimaciones de la realidad. No tengo ningún uso para esas cosas.$B$B¡En libros, narrativa, descripción! Ahí es donde está la verdad. Cambiaría todos los mapas de esta tienda por un libro sobre el auge de la nigromancia o una historia del triunfo de la Dama Oscura.', 0);
-- 1802 Libro del conciliábulo
-- https://es.classic.wowhead.com/quest=1802
SET @ID := 1802;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Los rumores resultaron ciertos, $n?', 0),
(@ID, 'esMX', '¿Los rumores resultaron ciertos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico! Ahora puedo unirme a las filas de los pocos que han espiado su contenido.$B$BNo puedo esperar para leer más detenidamente este texto. ¡Este es un gran día, $n! Si me permites echarle un vistazo antes de irte. Estoy seguro de que Strahad estará dispuesto a enviarme una copia.', 0),
(@ID, 'esMX', '¡Fantástico! Ahora puedo unirme a las filas de los pocos que han espiado su contenido.$B$BNo puedo esperar para leer más detenidamente este texto. ¡Este es un gran día, $n! Si me permites echarle un vistazo antes de irte. Estoy seguro de que Strahad estará dispuesto a enviarme una copia.', 0);
-- 1803 Libro del conciliábulo
-- https://es.classic.wowhead.com/quest=1803
SET @ID := 1803;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Puede ser que estés persiguiendo cuentos de hadas, $n, pero la verdad se puede encontrar en el centro de incluso los rumores más descabellados.', 0),
(@ID, 'esMX', 'Puede ser que estés persiguiendo cuentos de hadas, $n, pero la verdad se puede encontrar en el centro de incluso los rumores más descabellados.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien bien bien! ¿Qué tenemos aquí?$B$BEsto es impresionante, $n. No lo hubiera creído posible, pero aquí está en mis manos, el Tomo completo de la Cábala.$B$BPermíteme hojear sus páginas un momento antes de que te vayas de nuevo.', 0),
(@ID, 'esMX', '¡Bien bien bien! ¿Qué tenemos aquí?$B$BEsto es impresionante, $n. No lo hubiera creído posible, pero aquí está en mis manos, el Tomo completo de la Cábala.$B$BPermíteme hojear sus páginas un momento antes de que te vayas de nuevo.', 0);
-- 1804 Libro del conciliábulo
-- https://es.classic.wowhead.com/quest=1804
SET @ID := 1804;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hacía mucho que no te veía. ¿Encontraste el tomo y las varas?', 0),
(@ID, 'esMX', 'Hacía mucho que no te veía. ¿Encontraste el tomo y las varas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Magnífico, aquí están: el Libro del Conciliábulo y las varas.$B$BEsto va a ser interesante: hace tiempo que ningún joven $c se enfrenta a un manáfago.', 0),
(@ID, 'esMX', 'Magnífico, aquí están: el Libro del Conciliábulo y las varas.$B$BEsto va a ser interesante: hace tiempo que ningún joven $c se enfrenta a un manáfago.', 0);
-- 1805 Libro del conciliábulo
-- https://es.classic.wowhead.com/quest=1805
SET @ID := 1805;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $n? ¿En qué puedo ayudarte?', 0),
(@ID, 'esMX', '¿Sí, $n? ¿En qué puedo ayudarte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien hecho! El Tomo de la Cábala y tres prístinas --supongo que ligeramente rayados-- varas de mediación.$B$BEsto será interesante. Ha pasado algún tiempo desde que $gun:una; joven $c tomó un cazador vil para hacerlo suyo.', 0),
(@ID, 'esMX', '¡Bien hecho! El Tomo de la Cábala y tres prístinas --supongo que ligeramente rayados-- varas de mediación.$B$BEsto será interesante. Ha pasado algún tiempo desde que $gun:una; joven $c tomó un cazador vil para hacerlo suyo.', 0);
-- 1818 Habla con Dillinger
-- https://es.classic.wowhead.com/quest=1818
SET @ID := 1818;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has venido por una misión? Bien. Tengo una importante y que pondrá a prueba tu destreza en combate... y tu firmeza en la defensa de los Renegados.', 0),
(@ID, 'esMX', '¿Has venido por una misión? Bien. Tengo una importante y que pondrá a prueba tu destreza en combate... y tu firmeza en la defensa de los Renegados.', 0);
-- 1819 Ulag el Cuchilla
-- https://es.classic.wowhead.com/quest=1819
SET @ID := 1819;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu tarea aún está por hacer, $n. No es prudente que $gun:una; $c muestre miedo...', 0),
(@ID, 'esMX', 'Tu tarea aún está por hacer, $n. No es prudente que $gun:una; $c muestre miedo...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Ulag no era un agente menor de la Plaga. Has mostrado a los guardias de la muerte y, por tanto, a la Dama Oscura, que eres $gun:una; $c firme y que mereces seguir avanzando en tu instrucción.', 0),
(@ID, 'esMX', 'Bien hecho, $n. Ulag no era un agente menor de la Plaga. Has mostrado a los guardias de la muerte y, por tanto, a la Dama Oscura, que eres $gun:una; $c firme y que mereces seguir avanzando en tu instrucción.', 0);
-- 1820 Habla con Coleman
-- https://es.classic.wowhead.com/quest=1820
SET @ID := 1820;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, es cierto, necesito de tu pericia en combate. Mis medios son escasos, pero mi tarea sirve también a la causa de los Renegados. Hazlo y tu recompensa será doble.', 0),
(@ID, 'esMX', 'Sí, es cierto, necesito de tu pericia en combate. Mis medios son escasos, pero mi tarea sirve también a la causa de los Renegados. Hazlo y tu recompensa será doble.', 0);
-- 1821 Reliquias Agamand
-- Notice: English text: change 'Sictor' to '$n'
-- https://es.classic.wowhead.com/quest=1821
SET @ID := 1821;
UPDATE `quest_request_items` SET `CompletionText` = 'Do you have the heirlooms, $n?', `VerifiedBuild` = 0 WHERE `id` = @ID ;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las reliquias, $n?', 0),
(@ID, 'esMX', '¿Tienes las reliquias, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah! ¡Los has recuperado! El último vestigio de honor y de recuerdo ya ha sido arrancado de las tierras malditas de Agamand. ¡La familia ha desaparecido por completo!', 0),
(@ID, 'esMX', '¡Ah! ¡Los has recuperado! El último vestigio de honor y de recuerdo ya ha sido arrancado de las tierras malditas de Agamand. ¡La familia ha desaparecido por completo!', 0);
-- 1822 Arma reliquia
-- https://es.classic.wowhead.com/quest=1822
SET @ID := 1822;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Conservaré tres de las armas que me has devuelto, como recuerdos de mi sufrimiento y de mi pérdida. Pero por favor, $n, elige tu favorita entre las reliquias y quédatela.$B$BQue te sea de más ayuda que a sus antiguos y malditos propietarios.', 0),
(@ID, 'esMX', 'Conservaré tres de las armas que me has devuelto, como recuerdos de mi sufrimiento y de mi pérdida. Pero por favor, $n, elige tu favorita entre las reliquias y quédatela.$B$BQue te sea de más ayuda que a sus antiguos y malditos propietarios.', 0);
-- 1823 Habla con Ruga
-- https://es.classic.wowhead.com/quest=1823
SET @ID := 1823;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has venido por mi prueba, $n?', 0),
(@ID, 'esMX', '¿Has venido por mi prueba, $n?', 0);
-- 1824 Prueba en Tierra de Gigantes
-- https://es.classic.wowhead.com/quest=1824
SET @ID := 1824;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las antenas? Si las tienes dámelas enseguida, las antenas agitadas no siguen agitándose mucho tiempo...', 0),
(@ID, 'esMX', '¿Tienes las antenas? Si las tienes dámelas enseguida, las antenas agitadas no siguen agitándose mucho tiempo...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien hecho, $n! Al superar la prueba en Tierra de Gigantes has dado un gran paso adelante en la senda $gdel:de la; $c.', 0),
(@ID, 'esMX', '¡Muy bien hecho, $n! Al superar la prueba en Tierra de Gigantes has dado un gran paso adelante en la senda $gdel:de la; $c.', 0);
-- 1825 Habla con Thun'grim
-- https://es.classic.wowhead.com/quest=1825
SET @ID := 1825;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, has venido. Es estupendo, tenemos mucho de qué hablar tú y yo.', 0),
(@ID, 'esMX', 'Sí, has venido. Es estupendo, tenemos mucho de qué hablar tú y yo.', 0);
-- 1838 Armadura brutal
-- https://es.classic.wowhead.com/quest=1838
SET @ID := 1838;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los objetos que indicaba mi pergamino, $n?', 0),
(@ID, 'esMX', '¿Tienes los objetos que indicaba mi pergamino, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Trajiste todo lo que te pedí. Ahora, haré mi parte...', 0),
(@ID, 'esMX', 'Trajiste todo lo que te pedí. Ahora, haré mi parte...', 0);
-- 1839 Ula'elek y los guanteletes brutales
-- https://es.classic.wowhead.com/quest=1839
SET @ID := 1839;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $n. El viejo Thun\'grim me envió un mensaje de tu llegada, pero si hubiera guardado silencio, tu presencia aquí no me habría sorprendido.$B$BLos espíritus siguen tu progreso, joven $c, y me dicen que muchos enemigos han caído ante ti.', 0),
(@ID, 'esMX', 'Saludos, $n. El viejo Thun\'grim me envió un mensaje de tu llegada, pero si hubiera guardado silencio, tu presencia aquí no me habría sorprendido.$B$BLos espíritus siguen tu progreso, joven $c, y me dicen que muchos enemigos han caído ante ti.', 0);
-- 1840 Orm Pezuña Pétrea y el yelmo brutal
-- https://es.classic.wowhead.com/quest=1840
SET @ID := 1840;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c. Soy Orm, Thun\'grim me dijo que querías que te hiciera un yelmo, ¿cierto?', 0),
(@ID, 'esMX', 'Saludos, $c. Soy Orm, Thun\'grim me dijo que querías que te hiciera un yelmo, ¿cierto?', 0);
-- 1841 Velora Noctis y las musleras brutal
-- https://es.classic.wowhead.com/quest=1841
SET @ID := 1841;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estás aquí por una armadura para las piernas? ¡Excelente!$B$BUmm... ¿estoy haciendo la armadura para ti o tú la estás haciendo para mí?$B$BEso fue una broma. ¿Fué divertido? No puedo decir... Perdí mi sentido del humor al mismo tiempo que perdí mi sentido del olfato. Que fue casi al mismo tiempo que dejé de respirar.', 0),
(@ID, 'esMX', '¿Estás aquí por una armadura para las piernas? ¡Excelente!$B$BUmm... ¿estoy haciendo la armadura para ti o tú la estás haciendo para mí?$B$BEso fue una broma. ¿Fué divertido? No puedo decir... Perdí mi sentido del humor al mismo tiempo que perdí mi sentido del olfato. Que fue casi al mismo tiempo que dejé de respirar.', 0);
-- 1842 Pezuñas de sátiro
-- https://es.classic.wowhead.com/quest=1842
SET @ID := 1842;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las pezuñas, $n? La magia en ellas es fuerte.', 0),
(@ID, 'esMX', '¿Tienes las pezuñas, $n? La magia en ellas es fuerte.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, las tienes! Ahora, justo cuando los sátiros absorbieron la fuerza de Vallefresno, absorberé el poder que tienen estas pezuñas y lo aprovecharé en mi artesanía...', 0),
(@ID, 'esMX', '¡Ah, las tienes! Ahora, justo cuando los sátiros absorbieron la fuerza de Vallefresno, absorberé el poder que tienen estas pezuñas y lo aprovecharé en mi artesanía...', 0);
-- 1843 Guanteletes brutales
-- https://es.classic.wowhead.com/quest=1843
SET @ID := 1843;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Estos guanteletes son mi mejor trabajo. Tómalos. Al usarlos, me honras a mí y a mis antepasados.', 0),
(@ID, 'esMX', 'Gracias, $n. Estos guanteletes son mi mejor trabajo. Tómalos. Al usarlos, me honras a mí y a mis antepasados.', 0);
-- 1844 Cuerno de quimera
-- https://es.classic.wowhead.com/quest=1844
SET @ID := 1844;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes el cuerno? ¿Has librado a la matriarca de su sufrimiento?', 0),
(@ID, 'esMX', '¿Tienes el cuerno? ¿Has librado a la matriarca de su sufrimiento?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has terminado tu tarea, $n, y me has demostrado tu valía y resolución. El yelmo será tuyo...', 0),
(@ID, 'esMX', 'Has terminado tu tarea, $n, y me has demostrado tu valía y resolución. El yelmo será tuyo...', 0);
-- 1845 Yelmo brutal
-- https://es.classic.wowhead.com/quest=1845
SET @ID := 1845;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te concedo este yelmo.$B$BMe diste grandes gestas, $n, y si la Madre Tierra quiere... aún te esperan gestas mayores.', 0),
(@ID, 'esMX', 'Te concedo este yelmo.$B$BMe diste grandes gestas, $n, y si la Madre Tierra quiere... aún te esperan gestas mayores.', 0);
-- 1846 Tibias de Faucedraco
-- https://es.classic.wowhead.com/quest=1846
SET @ID := 1846;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy esperando esas tibias, $n. Serán un buen marco para tus protectores de piernas.', 0),
(@ID, 'esMX', 'Estoy esperando esas tibias, $n. Serán un buen marco para tus protectores de piernas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien hecho! Todas parecen resistentes. Creo que irá bastante bien. ¿Cómo les sentó a esos orcos que les quitaras las tibias, $n? ¿Se quejaron mucho?$B$BEsa fue otra broma. No te estás riendo.$B$BNo soy muy gracioso estos días, ¿verdad?', 0),
(@ID, 'esMX', '¡Bien hecho! Todas parecen resistentes. Creo que irá bastante bien. ¿Cómo les sentó a esos orcos que les quitaras las tibias, $n? ¿Se quejaron mucho?$B$BEsa fue otra broma. No te estás riendo.$B$BNo soy muy gracioso estos días, ¿verdad?', 0);
-- 1847 Musleras brutales
-- https://es.classic.wowhead.com/quest=1847
SET @ID := 1847;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí tienes tus musleras, $n. Déjame ver cómo encajan o si necesitas modificaciones. ¡Mi objetivo es agradar! Al menos solía hacerlo.$B$BEn estos días no me preocupo mucho por mi oficio. ¡Pero es mejor que ser un esbirro insensato de la Plaga!$B$BSupongo.', 0),
(@ID, 'esMX', 'Aquí tienes tus musleras, $n. Déjame ver cómo encajan o si necesitas modificaciones. ¡Mi objetivo es agradar! Al menos solía hacerlo.$B$BEn estos días no me preocupo mucho por mi oficio. ¡Pero es mejor que ser un esbirro insensato de la Plaga!$B$BSupongo.', 0);
-- 1848 Camisote brutal
-- https://es.classic.wowhead.com/quest=1848
SET @ID := 1848;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Habrás tenido que soportar duras privaciones y habrás derramado mucha sangre cumpliendo mi tarea, $n. Este es el producto de todo tu esfuerzo.$B$BUtilízalo bien y quizás un día vuelvas a contarme cuántas veces te ha sido de ayuda.', 0),
(@ID, 'esMX', 'Habrás tenido que soportar duras privaciones y habrás derramado mucha sangre cumpliendo mi tarea, $n. Este es el producto de todo tu esfuerzo.$B$BUtilízalo bien y quizás un día vuelvas a contarme cuántas veces te ha sido de ayuda.', 0);
-- 1858 Mano Destrozada
-- https://es.classic.wowhead.com/quest=1858
SET @ID := 1858;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es humillante tener el objeto que deseas a tu alcance y no ser capaz de tomarlo.', 0),
(@ID, 'esMX', 'Es humillante tener el objeto que deseas a tu alcance y no ser capaz de tomarlo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm, interesante. Has probado sobradamente tu valía, $n. Considérate $gel:la; miembro más reciente de Mano Destrozada. Y toma esto; te ayudará mucho en el futuro.', 0),
(@ID, 'esMX', 'Mmm, interesante. Has probado sobradamente tu valía, $n. Considérate $gel:la; miembro más reciente de Mano Destrozada. Y toma esto; te ayudará mucho en el futuro.', 0);
-- 1859 Therzok
-- https://es.classic.wowhead.com/quest=1859
SET @ID := 1859;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, me alegro de que Kaplak consiguiera encontrarte.$B$BTenemos que hablar de varias cosas y la más importante es tu futuro en la Mano.', 0),
(@ID, 'esMX', 'Muy bien, me alegro de que Kaplak consiguiera encontrarte.$B$BTenemos que hablar de varias cosas y la más importante es tu futuro en la Mano.', 0);
