-- 13 Nivel 80
-- https://wotlkdb.com/?achievement=13
SET @ID := 13;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','Nivel 80', 'Felicitaciones por tu convicción de llegar a la temporada 80 de aventuras. Sin duda, estás dedicado a la causa de librar a Azeroth de los males que nos han asolado.$B$BY aunque el viaje hasta ahora no ha sido una hazaña menor, la verdadera batalla está por llegar.$B$B¡Sigue luchando!$B$BRhonin'),
(@ID, 'esMX','Nivel 80', 'Felicitaciones por tu convicción de llegar a la temporada 80 de aventuras. Sin duda, estás dedicado a la causa de librar a Azeroth de los males que nos han asolado.$B$BY aunque el viaje hasta ahora no ha sido una hazaña menor, la verdadera batalla está por llegar.$B$B¡Sigue luchando!$B$BRhonin');
-- 45 ¡Has estado por aquí!
-- https://wotlkdb.com/?achievement=45
SET @ID := 45;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','¡Has estado por aquí!', 'Bueno, ¡mírate!$B$B¡Y pensé que había visto algunas cosas en este lugar helado! A este enano le parece obvio que tienes el fuego del explorador ardiendo en tus ojos.$B$BLleva este tabardo con orgullo. De esa manera, tus amigos sabrán a quién pedir direcciones cuando llegue el momento.$B$B¡Sigue en movimiento!$B$BBrann Barbabronce'),
(@ID, 'esMX','¡Has estado por aquí!', 'Bueno, ¡mírate!$B$B¡Y pensé que había visto algunas cosas en este lugar helado! A este enano le parece obvio que tienes el fuego del explorador ardiendo en tus ojos.$B$BLleva este tabardo con orgullo. De esa manera, tus amigos sabrán a quién pedir direcciones cuando llegue el momento.$B$B¡Sigue en movimiento!$B$BBrann Barbabronce');
-- 614 ¡Por la Alianza!
-- https://wotlkdb.com/?achievement=614
SET @ID := 614;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','¡Por la Alianza!', 'La guerra hace estragos en nuestras tierras. Solo los héroes más valientes se atreven a desafiar a la Horda donde más les duele. Estás entre esos héroes.$B$BLos golpes que le has dado a los líderes de la Horda abrirán la puerta a nuestro asalto final. La Horda se inclinará ante el poder de la Alianza.$B$BTus acciones no quedarán sin recompensa. ¡Sigue adelante con orgullo!$B$B--Tu rey'),
(@ID, 'esMX','¡Por la Alianza!', 'La guerra hace estragos en nuestras tierras. Solo los héroes más valientes se atreven a desafiar a la Horda donde más les duele. Estás entre esos héroes.$B$BLos golpes que le has dado a los líderes de la Horda abrirán la puerta a nuestro asalto final. La Horda se inclinará ante el poder de la Alianza.$B$BTus acciones no quedarán sin recompensa. ¡Sigue adelante con orgullo!$B$B--Tu rey');
-- 619 ¡Por la Horda!
-- https://wotlkdb.com/?achievement=619
SET @ID := 619;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','¡Por la Horda!', 'En esta época de gran agitación, los verdaderos héroes surgen de la miseria. Eres uno de esos grandes héroes.$B$BLa guerra está sobre nosotros. Tus esfuerzos promoverán nuestra causa en Azeroth. Tus grandes hazañas serán recompensadas. Toma este premio de Orgrimmar y cabalga hacia la gloria.$B$B¡Por la Horda!$B$BJefe de Guerra Thrall'),
(@ID, 'esMX','¡Por la Horda!', 'En esta época de gran agitación, los verdaderos héroes surgen de la miseria. Eres uno de esos grandes héroes.$B$BLa guerra está sobre nosotros. Tus esfuerzos promoverán nuestra causa en Azeroth. Tus grandes hazañas serán recompensadas. Toma este premio de Orgrimmar y cabalga hacia la gloria.$B$B¡Por la Horda!$B$BJefe de Guerra Thrall');
-- 876 Te he estado mirando <niño/niña>
-- https://wotlkdb.com/?achievement=876
SET @ID := 876;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','Te he estado mirando $gniño:niña;', 'Tienes una gran habilidad para vencer en esa arena. Guarda esto. Úsalo con orgullo. ¡Ahora vuelve y enséñales cómo se hace!$B$BTío sal'),
(@ID, 'esMX','Te he estado mirando $gniño:niña;', 'Tienes una gran habilidad para vencer en esa arena. Guarda esto. Úsalo con orgullo. ¡Ahora vuelve y enséñales cómo se hace!$B$BTío sal');
-- 1021 <Completo/Completa> <Triunfador/Triunfadora>
-- https://wotlkdb.com/?achievement=1021
SET @ID := 1021;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','$gCompleto:Completa; $gTriunfador:Triunfadora;', 'No pude evitar darme cuenta de la excelente colección de tabardos que has conseguido reunir a lo largo de las temporadas. También podrías agregar este a tu colección. Simplemente ha estado acumulando polvo en mi armario.'),
(@ID, 'esMX','$gCompleto:Completa; $gTriunfador:Triunfadora;', 'No pude evitar darme cuenta de la excelente colección de tabardos que has conseguido reunir a lo largo de las temporadas. También podrías agregar este a tu colección. Simplemente ha estado acumulando polvo en mi armario.');
-- 1250 El nuevo hogar de Stinker
-- https://wotlkdb.com/?achievement=1250
SET @ID := 1250;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','El nuevo hogar de Stinker', 'Escuché lo bien que cuidas a nuestros amigos peludos. Espero que no te importe, pero debo conseguirle a Stinker un nuevo hogar. Simplemente se niega a jugar bien con los demás.$B$BAsegúrate de alimentarlo dos veces al día. Y umm... tiene algo con los gatos negros.$B$B--Breanni'),
(@ID, 'esMX','El nuevo hogar de Stinker', 'Escuché lo bien que cuidas a nuestros amigos peludos. Espero que no te importe, pero debo conseguirle a Stinker un nuevo hogar. Simplemente se niega a jugar bien con los demás.$B$BAsegúrate de alimentarlo dos veces al día. Y umm... tiene algo con los gatos negros.$B$B--Breanni');
-- 1681 Saludos de Darnassus
-- https://wotlkdb.com/?achievement=1681
SET @ID := 1681;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','Saludos de Darnassus', 'Tus logros han sido profundos y de gran alcance. Azeroth, con toda la agitación reciente, se beneficia enormemente de aquellos que buscan librar a la tierra del mal.$B$BSolo aquellos que se toman el tiempo de conocer nuestras tierras comprenden los sacrificios de los caídos y el valor de $gnuestros:nuestras; $ghéroes:heroinas;. Eres $guno:una; de esos $ghéroes:heroínas;. Con suerte, se recordarán los relatos de sus aventuras durante los próximos años.$B$BEn nombre de la Alianza, te doy las gracias, Maestro Cultural.'),
(@ID, 'esMX','Saludos de Darnassus', 'Tus logros han sido profundos y de gran alcance. Azeroth, con toda la agitación reciente, se beneficia enormemente de aquellos que buscan librar a la tierra del mal.$B$BSolo aquellos que se toman el tiempo de conocer nuestras tierras comprenden los sacrificios de los caídos y el valor de $gnuestros:nuestras; $ghéroes:heroinas;. Eres $guno:una; de esos $ghéroes:heroínas;. Con suerte, se recordarán los relatos de sus aventuras durante los próximos años.$B$BEn nombre de la Alianza, te doy las gracias, Maestro Cultural.');
-- 1682 Saludos desde Cima del Trueno
-- https://wotlkdb.com/?achievement=1682
SET @ID := 1682;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','Saludos desde Cima del Trueno', 'Las noticias de sus logros han viajado lejos. Los vientos de la agitación aúllan a través de nuestras tierras. Aquellos que desafían el mal son nuestra única esperanza.$B$BSolo aquellos que escuchan los vientos comprenden las deudas que nuestros héroes caídos han pagado para proteger a nuestra gente. Que $gun:una; $ghéroe:heroína; como tú viva mucho para contar las historias de tus aventuras. Porque solo entonces recordaremos cuánto tenemos que estar agradecidos.$B$BNuestro agradecimiento es profundo, $gMaestro:Maestra; Cultural.$B$B¡Por la Horda!$B$B--Cairne Pezuña de Sangre'),
(@ID, 'esMX','Saludos desde Cima del Trueno', 'Las noticias de sus logros han viajado lejos. Los vientos de la agitación aúllan a través de nuestras tierras. Aquellos que desafían el mal son nuestra única esperanza.$B$BSolo aquellos que escuchan los vientos comprenden las deudas que nuestros héroes caídos han pagado para proteger a nuestra gente. Que $gun:una; $ghéroe:heroína; como tú viva mucho para contar las historias de tus aventuras. Porque solo entonces recordaremos cuánto tenemos que estar agradecidos.$B$BNuestro agradecimiento es profundo, $gMaestro:Maestra; Cultural.$B$B¡Por la Horda!$B$B--Cairne Pezuña de Sangre');
-- 2136 La gloria $gdel:de la; $ghéroe:heroína;
-- https://wotlkdb.com/?achievement=2136
SET @ID := 2136;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','La gloria $gdel:de la; $ghéroe:heroína;', '$gCampeón:Campeona;,$B$BHa llegado al Templo del Reposo del Dragón las grandes hazañas heroicas que has realizado desde que llegaste a Rasganorte.$B$BTu valentía no debe pasar desapercibida. Acepta este regalo en nombre de los Aspectos. Juntos libraremos a Azeroth del mal, de una vez y para siempre.$B$BAlexstrasza la Protectora'),
(@ID, 'esMX','La gloria $gdel:de la; $ghéroe:heroína;', '$gCampeón:Campeona;,$B$BHa llegado al Templo del Reposo del Dragón las grandes hazañas heroicas que has realizado desde que llegaste a Rasganorte.$B$BTu valentía no debe pasar desapercibida. Acepta este regalo en nombre de los Aspectos. Juntos libraremos a Azeroth del mal, de una vez y para siempre.$B$BAlexstrasza la Protectora');
-- 2143 Liderar la caballería
-- https://wotlkdb.com/?achievement=2143
SET @ID := 2143;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','Liderar la caballería', 'No pude evitar notar lo $gbueno:buena; que eres con el ganado. Con toda la actividad por aquí, el negocio ha ido mejor que nunca para mí. Supongo que no te importaría cuidar de este Draco Albino por mí. Simplemente no tengo suficientes minutos libres en el día para cuidar a todos estos animales.$B$BTuya, Mei'),
(@ID, 'esMX','Liderar la caballería', 'No pude evitar notar lo $gbueno:buena; que eres con el ganado. Con toda la actividad por aquí, el negocio ha ido mejor que nunca para mí. Supongo que no te importaría cuidar de este Draco Albino por mí. Simplemente no tengo suficientes minutos libres en el día para cuidar a todos estos animales.$B$BTuya, Mei');
-- 2144 Una y otra vez
-- https://wotlkdb.com/?achievement=2144
SET @ID := 2144;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','Una y otra vez', 'Con los tambores de guerra retumbando a lo lejos, es fácil para los habitantes de Azeroth olvidar todo lo que la vida tiene para ofrecer.$B$BTú, por otro lado, has mantenido la dignidad de las buenas razas de Azeroth con tu habilidad para recordar por qué luchamos. No celebrar nuestras victorias es otra forma de derrota. Recuérdalo bien, Juerguista.$B$BQue otros se inspiren en tus ganas de vivir.$B$BAlexstrasza la Protectora'),
(@ID, 'esMX','Una y otra vez', 'Con los tambores de guerra retumbando a lo lejos, es fácil para los habitantes de Azeroth olvidar todo lo que la vida tiene para ofrecer.$B$BTú, por otro lado, has mantenido la dignidad de las buenas razas de Azeroth con tu habilidad para recordar por qué luchamos. No celebrar nuestras victorias es otra forma de derrota. Recuérdalo bien, Juerguista.$B$BQue otros se inspiren en tus ganas de vivir.$B$BAlexstrasza la Protectora');
-- 2145 Una y otra vez
-- https://wotlkdb.com/?achievement=2145
SET @ID := 2145;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','Una y otra vez', 'Con los tambores de guerra retumbando a lo lejos, es fácil para los habitantes de Azeroth olvidar todo lo que la vida tiene para ofrecer.$B$BTú, por otro lado, has mantenido la dignidad de las buenas razas de Azeroth con tu habilidad para recordar por qué luchamos. No celebrar nuestras victorias es otra forma de derrota. Recuérdalo bien, Juerguista.$B$BQue otros se inspiren en tus ganas de vivir.$B$BAlexstrasza la Protectora'),
(@ID, 'esMX','Una y otra vez', 'Con los tambores de guerra retumbando a lo lejos, es fácil para los habitantes de Azeroth olvidar todo lo que la vida tiene para ofrecer.$B$BTú, por otro lado, has mantenido la dignidad de las buenas razas de Azeroth con tu habilidad para recordar por qué luchamos. No celebrar nuestras victorias es otra forma de derrota. Recuérdalo bien, Juerguista.$B$BQue otros se inspiren en tus ganas de vivir.$B$BAlexstrasza la Protectora');
-- 2516 Un amigo para adular
-- https://wotlkdb.com/?achievement=2516
SET @ID := 2516;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','Un amigo para adular', '¡Hola!$B$BTengo entendido que te las has arreglado para darle incluso a ese travieso Stinker un hogar cálido y amoroso ... ¿Esperaba que pudieras considerar la posibilidad de acoger a otro huérfano rebelde?$B$BEste pequeño cervatillo es tímido, pero no tendrás problemas para ganar su amistad con lo que adjunto: ¡su piedra de sal para lamer favorita!$B$B--Breanni'),
(@ID, 'esMX','Un amigo para adular', '¡Hola!$B$BTengo entendido que te las has arreglado para darle incluso a ese travieso Stinker un hogar cálido y amoroso ... ¿Esperaba que pudieras considerar la posibilidad de acoger a otro huérfano rebelde?$B$BEste pequeño cervatillo es tímido, pero no tendrás problemas para ganar su amistad con lo que adjunto: ¡su piedra de sal para lamer favorita!$B$B--Breanni');
-- 2536 Un montón de monturas
-- https://wotlkdb.com/?achievement=2536
SET @ID := 2536;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','Un montón de monturas', 'Escuché que tus establos son casi tan extensos como los míos ahora. ¡Impresionante! Quizás podamos ayudarnos tu y yo... Tengo demasiados dracohalcones y esperaba que pudieras darle un hogar a este. Naturalmente, ha sido entrenado como montura y no como mascota de caza, y lo encontrarás tan leal e incansable como cualquier otro corcel que críe.$B$BTuya de nuevo, Mei'),
(@ID, 'esMX','Un montón de monturas', 'Escuché que tus establos son casi tan extensos como los míos ahora. ¡Impresionante! Quizás podamos ayudarnos tu y yo... Tengo demasiados dracohalcones y esperaba que pudieras darle un hogar a este. Naturalmente, ha sido entrenado como montura y no como mascota de caza, y lo encontrarás tan leal e incansable como cualquier otro corcel que críe.$B$BTuya de nuevo, Mei');
-- 2537 Un montón de monturas
-- https://wotlkdb.com/?achievement=2537
SET @ID := 2537;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','Un montón de monturas', 'Escuché que tus establos son casi tan extensos como los míos ahora. ¡Impresionante! Quizás podamos ayudarnos tu y yo... Tengo demasiados dracohalcones y esperaba que pudieras darle un hogar a este. Naturalmente, ha sido entrenado como montura y no como mascota de caza, y lo encontrarás tan leal e incansable como cualquier otro corcel que críe.$B$BTuya de nuevo, Mei'),
(@ID, 'esMX','Un montón de monturas', 'Escuché que tus establos son casi tan extensos como los míos ahora. ¡Impresionante! Quizás podamos ayudarnos tu y yo... Tengo demasiados dracohalcones y esperaba que pudieras darle un hogar a este. Naturalmente, ha sido entrenado como montura y no como mascota de caza, y lo encontrarás tan leal e incansable como cualquier otro corcel que críe.$B$BTuya de nuevo, Mei');
-- 2957 La gloria del asaltante de Ulduar
-- https://wotlkdb.com/?achievement=2957
SET @ID := 2957;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','La gloria del asaltante de Ulduar', '$gEstimado:Estimada; $n,$B$BEspero que estés bien y que hayas tenido tiempo de recuperarte de nuestras travesuras en Ulduar.$B$BMis muchachos del equipo de prospección se toparon con esta pobre cría de dragón de montar medio muerta. Debe haber sido un experimento de Enano de Hierro de algún tipo.$B$B¡Lo hemos cuidado para que recupere la salud y descubrirás que ya no es tan pequeño! Ninguno de nosotros sabe mucho acerca de montar otra cosa que no sean carneros y mulas de carga, y como te debíamos uno por lo que hiciste allí... Pensamos que quizás lo aceptarías como un regalo.$B$BTuyo,$BBrann Barbabronce'),
(@ID, 'esMX','La gloria del asaltante de Ulduar', '$gEstimado:Estimada; $n,$B$BEspero que estés bien y que hayas tenido tiempo de recuperarte de nuestras travesuras en Ulduar.$B$BMis muchachos del equipo de prospección se toparon con esta pobre cría de dragón de montar medio muerta. Debe haber sido un experimento de Enano de Hierro de algún tipo.$B$B¡Lo hemos cuidado para que recupere la salud y descubrirás que ya no es tan pequeño! Ninguno de nosotros sabe mucho acerca de montar otra cosa que no sean carneros y mulas de carga, y como te debíamos uno por lo que hiciste allí... Pensamos que quizás lo aceptarías como un regalo.$B$BTuyo,$BBrann Barbabronce');
-- 2958 La gloria del asaltante de Ulduar
-- https://wotlkdb.com/?achievement=2958
SET @ID := 2958;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','La gloria del asaltante de Ulduar', '$gEstimado:Estimada; $n,$B$BEspero que estés bien y que hayas tenido tiempo de recuperarte de nuestras travesuras en Ulduar.$B$BMis muchachos del equipo de prospección se toparon con esta pobre cría de dragón de montar medio muerta. Debe haber sido un experimento de Enano de Hierro de algún tipo.$B$B¡Lo hemos cuidado para que recupere la salud y descubrirás que ya no es tan pequeño! Ninguno de nosotros sabe mucho acerca de montar otra cosa que no sean carneros y mulas de carga, y como te debíamos uno por lo que hiciste allí... Pensamos que quizás lo aceptarías como un regalo.$B$BTuyo,$BBrann Barbabronce'),
(@ID, 'esMX','La gloria del asaltante de Ulduar', '$gEstimado:Estimada; $n,$B$BEspero que estés bien y que hayas tenido tiempo de recuperarte de nuestras travesuras en Ulduar.$B$BMis muchachos del equipo de prospección se toparon con esta pobre cría de dragón de montar medio muerta. Debe haber sido un experimento de Enano de Hierro de algún tipo.$B$B¡Lo hemos cuidado para que recupere la salud y descubrirás que ya no es tan pequeño! Ninguno de nosotros sabe mucho acerca de montar otra cosa que no sean carneros y mulas de carga, y como te debíamos uno por lo que hiciste allí... Pensamos que quizás lo aceptarías como un regalo.$B$BTuyo,$BBrann Barbabronce');
-- 3478 Un pavo aún no engullido
-- https://wotlkdb.com/?achievement=3478
SET @ID := 3478;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','Un pavo aún no engullido', '¿Puedes creer que este pavo regordete sobrevivió a noviembre?$B$BDado que todos sus amigos se han servido en abundantes mesas con salsa de arándanos y rellenos de pan con especias y... ooo... tengo hambre. ¡Pero de todos modos! Ahora está solo, así que esperaba que estuvieras dispuesto a cuidar de él. ¡Simplemente no queda suficiente espacio en mi tienda!$B$BMantenlo alejado de los fogones de cocina, por favor. Tiene esta extraña mirada en sus ojos alrededor de los fogones...'),
(@ID, 'esMX','Un pavo aún no engullido', '¿Puedes creer que este pavo regordete sobrevivió a noviembre?$B$BDado que todos sus amigos se han servido en abundantes mesas con salsa de arándanos y rellenos de pan con especias y... ooo... tengo hambre. ¡Pero de todos modos! Ahora está solo, así que esperaba que estuvieras dispuesto a cuidar de él. ¡Simplemente no queda suficiente espacio en mi tienda!$B$BMantenlo alejado de los fogones de cocina, por favor. Tiene esta extraña mirada en sus ojos alrededor de los fogones...');
-- 3656 Un pavo aún no engullido
-- https://wotlkdb.com/?achievement=3656
SET @ID := 3656;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','Un pavo aún no engullido', '¿Puedes creer que este pavo regordete sobrevivió a noviembre?$B$BDado que todos sus amigos se han servido en abundantes mesas con salsa de arándanos y rellenos de pan con especias y... ooo... tengo hambre. ¡Pero de todos modos! Ahora está solo, así que esperaba que estuvieras dispuesto a cuidar de él. ¡Simplemente no queda suficiente espacio en mi tienda!$B$BMantenlo alejado de los fogones de cocina, por favor. Tiene esta extraña mirada en sus ojos alrededor de los fogones...'),
(@ID, 'esMX','Un pavo aún no engullido', '¿Puedes creer que este pavo regordete sobrevivió a noviembre?$B$BDado que todos sus amigos se han servido en abundantes mesas con salsa de arándanos y rellenos de pan con especias y... ooo... tengo hambre. ¡Pero de todos modos! Ahora está solo, así que esperaba que estuvieras dispuesto a cuidar de él. ¡Simplemente no queda suficiente espacio en mi tienda!$B$BMantenlo alejado de los fogones de cocina, por favor. Tiene esta extraña mirada en sus ojos alrededor de los fogones...');
-- 3857 $gMaestro:Maestra; de la Isla de la Conquista
-- https://wotlkdb.com/?achievement=3857
SET @ID := 3857;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','$gMaestro:Maestra; de la Isla de la Conquista', 'Honorable $N,$B$BPor tus hazañas en la Isla de la Conquista, es un honor para mí presentarte este tabardo. Úselo con orgullo.$B$BAlto Comandante, Séptima Legión'),
(@ID, 'esMX','$gMaestro:Maestra; de la Isla de la Conquista', 'Honorable $N,$B$BPor tus hazañas en la Isla de la Conquista, es un honor para mí presentarte este tabardo. Úselo con orgullo.$B$BAlto Comandante, Séptima Legión');
-- 3957 $gMaestro:Maestra; de la Isla de la Conquista
-- https://wotlkdb.com/?achievement=3957
SET @ID := 3957;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','$gMaestro:Maestra; de la Isla de la Conquista', 'Honorable $N,$B$BPor tus hazañas en la Isla de la Conquista, es un honor para mí presentarte este tabardo. Úselo con orgullo.$B$BAlto Comandante, Séptima Legión'),
(@ID, 'esMX','$gMaestro:Maestra; de la Isla de la Conquista', 'Honorable $N,$B$BPor tus hazañas en la Isla de la Conquista, es un honor para mí presentarte este tabardo. Úselo con orgullo.$B$BAlto Comandante, Séptima Legión');
-- 4079 Un tributo a la inmortalidad
-- https://wotlkdb.com/?achievement=4079
SET @ID := 4079;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','Un tributo a la inmortalidad', 'Estimado $n,$B$BLos relatos de su actuación reciente en la Prueba del Gran Cruzado se contarán y volverán a contar durante siglos. Mientras la Cruzada Argenta hizo un llamado a los más grandes campeones de Azeroth para que pusieran a prueba su temple en el crisol del Coliseo, esperaba contra toda esperanza que los faros de luz como tú y tus compañeros pudieran emerger de la refriega.$B$BTe necesitaremos desesperadamente en la próxima batalla contra el Rey Exánime. Pero en este día, regocíjate y celebra tu glorioso logro y acepta este regalo; uno de nuestros mejores caballos de guerra. ¡Cuando la Plaga vea su estandarte asomándose en el horizonte, $ghéroe:heroína;, su fin estará cerca!$B$BTuyo con honor,$BTirion Vadin'),
(@ID, 'esMX','Un tributo a la inmortalidad', 'Estimado $n,$B$BLos relatos de su actuación reciente en la Prueba del Gran Cruzado se contarán y volverán a contar durante siglos. Mientras la Cruzada Argenta hizo un llamado a los más grandes campeones de Azeroth para que pusieran a prueba su temple en el crisol del Coliseo, esperaba contra toda esperanza que los faros de luz como tú y tus compañeros pudieran emerger de la refriega.$B$BTe necesitaremos desesperadamente en la próxima batalla contra el Rey Exánime. Pero en este día, regocíjate y celebra tu glorioso logro y acepta este regalo; uno de nuestros mejores caballos de guerra. ¡Cuando la Plaga vea su estandarte asomándose en el horizonte, $ghéroe:heroína;, su fin estará cerca!$B$BTuyo con honor,$BTirion Vadin');
-- 4156 Un tributo a la inmortalidad
-- https://wotlkdb.com/?achievement=4156
SET @ID := 4156;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','Un tributo a la inmortalidad', 'Estimado $n,$B$BLos relatos de su actuación reciente en la Prueba del Gran Cruzado se contarán y volverán a contar durante siglos. Mientras la Cruzada Argenta hizo un llamado a los más grandes campeones de Azeroth para que pusieran a prueba su temple en el crisol del Coliseo, esperaba contra toda esperanza que los faros de luz como tú y tus compañeros pudieran emerger de la refriega.$B$BTe necesitaremos desesperadamente en la próxima batalla contra el Rey Exánime. Pero en este día, regocíjate y celebra tu glorioso logro y acepta este regalo; uno de nuestros mejores caballos de guerra. ¡Cuando la Plaga vea su estandarte asomándose en el horizonte, $ghéroe:heroína;, su fin estará cerca!$B$BTuyo con honor,$BTirion Vadin'),
(@ID, 'esMX','Un tributo a la inmortalidad', 'Estimado $n,$B$BLos relatos de su actuación reciente en la Prueba del Gran Cruzado se contarán y volverán a contar durante siglos. Mientras la Cruzada Argenta hizo un llamado a los más grandes campeones de Azeroth para que pusieran a prueba su temple en el crisol del Coliseo, esperaba contra toda esperanza que los faros de luz como tú y tus compañeros pudieran emerger de la refriega.$B$BTe necesitaremos desesperadamente en la próxima batalla contra el Rey Exánime. Pero en este día, regocíjate y celebra tu glorioso logro y acepta este regalo; uno de nuestros mejores caballos de guerra. ¡Cuando la Plaga vea su estandarte asomándose en el horizonte, $ghéroe:heroína;, su fin estará cerca!$B$BTuyo con honor,$BTirion Vadin');
-- 4478 P.U.G.
-- https://wotlkdb.com/?achievement=4478
SET @ID := 4478;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','P.U.G.', 'Estimado individuo muy paciente,$B$BNos gustaría reconocer su tenacidad en la gestión de mazmorras con personas que probablemente no haya conocido antes. Con suerte, incluso les enseñaste a algunos novatos las cuerdas en tus grupos de recogida.$B$BEn resumen, escuchamos que te gustan los pugs. Así que aquí tienes un pug para tu pug, para que puedas pug mientras pug. O algo.$B$BAbrazos,$B$BTus amigos del equipo de desarrollo de WoW.'),
(@ID, 'esMX','P.U.G.', 'Estimado individuo muy paciente,$B$BNos gustaría reconocer su tenacidad en la gestión de mazmorras con personas que probablemente no haya conocido antes. Con suerte, incluso les enseñaste a algunos novatos las cuerdas en tus grupos de recogida.$B$BEn resumen, escuchamos que te gustan los pugs. Así que aquí tienes un pug para tu pug, para que puedas pug mientras pug. O algo.$B$BAbrazos,$B$BTus amigos del equipo de desarrollo de WoW.');
-- 4602 La gloria del asaltante de Corona de Hielo
-- https://wotlkdb.com/?achievement=4602
SET @ID := 4602;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','La gloria del asaltante de Corona de Hielo', '$n,$B$BA medida que la influencia del Rey Exánime se desvanece, algunos de sus secuaces más poderosos se han liberado de sus manos.$B$BEste dragón vermis de hielo que mis hombres capturaron es un excelente ejemplo. Ella tiene voluntad propia y algo más.$B$BUno de mis hombres perdió un brazo al domarla, pero ahora se adapta bastante bien a los jinetes, siempre que ellos mismos sean hábiles y de voluntad fuerte.$B$BAcepta esta magnífica bestia como regalo de los Caballeros de la Espada de Ébano. Fue un honor luchar a tu lado en esta gran batalla.$B$BCon honor,$BDarion Mograine.'),
(@ID, 'esMX','La gloria del asaltante de Corona de Hielo', '$n,$B$BA medida que la influencia del Rey Exánime se desvanece, algunos de sus secuaces más poderosos se han liberado de sus manos.$B$BEste dragón vermis de hielo que mis hombres capturaron es un excelente ejemplo. Ella tiene voluntad propia y algo más.$B$BUno de mis hombres perdió un brazo al domarla, pero ahora se adapta bastante bien a los jinetes, siempre que ellos mismos sean hábiles y de voluntad fuerte.$B$BAcepta esta magnífica bestia como regalo de los Caballeros de la Espada de Ébano. Fue un honor luchar a tu lado en esta gran batalla.$B$BCon honor,$BDarion Mograine.');
-- 4603 La gloria del asaltante de Corona de Hielo
-- https://wotlkdb.com/?achievement=4603
SET @ID := 4603;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','La gloria del asaltante de Corona de Hielo', '$n,$B$BA medida que la influencia del Rey Exánime se desvanece, algunos de sus secuaces más poderosos se han liberado de sus manos.$B$BEste dragón vermis de hielo que mis hombres capturaron es un excelente ejemplo. Ella tiene voluntad propia y algo más.$B$BUno de mis hombres perdió un brazo al domarla, pero ahora se adapta bastante bien a los jinetes, siempre que ellos mismos sean hábiles y de voluntad fuerte.$B$BAcepta esta magnífica bestia como regalo de los Caballeros de la Espada de Ébano. Fue un honor luchar a tu lado en esta gran batalla.$B$BCon honor,$BDarion Mograine.'),
(@ID, 'esMX','La gloria del asaltante de Corona de Hielo', '$n,$B$BA medida que la influencia del Rey Exánime se desvanece, algunos de sus secuaces más poderosos se han liberado de sus manos.$B$BEste dragón vermis de hielo que mis hombres capturaron es un excelente ejemplo. Ella tiene voluntad propia y algo más.$B$BUno de mis hombres perdió un brazo al domarla, pero ahora se adapta bastante bien a los jinetes, siempre que ellos mismos sean hábiles y de voluntad fuerte.$B$BAcepta esta magnífica bestia como regalo de los Caballeros de la Espada de Ébano. Fue un honor luchar a tu lado en esta gran batalla.$B$BCon honor,$BDarion Mograine.');
-- 4784 Intendente de emblemas en el Enclave de Plata de Dalaran
-- https://wotlkdb.com/?achievement=4784
SET @ID := 4784;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','Intendente de emblemas en el Enclave de Plata de Dalaran', 'Tus logros en Rasganorte no han pasado desapercibidos, amigo.$B$BLos emblemas que hayas ganado se pueden usar para comprar equipo de los distintos Intendente de emblemas en Dalaran.$B$BPuede encontrarnos en el Enclave de Plata, donde cada variedad de emblema tiene su propio intendente.$B$B¡Esperamos tu llegada!'),
(@ID, 'esMX','Intendente de emblemas en el Enclave de Plata de Dalaran', 'Tus logros en Rasganorte no han pasado desapercibidos, amigo.$B$BLos emblemas que hayas ganado se pueden usar para comprar equipo de los distintos Intendente de emblemas en Dalaran.$B$BPuede encontrarnos en el Enclave de Plata, donde cada variedad de emblema tiene su propio intendente.$B$B¡Esperamos tu llegada!');
-- 4785 Intendente de emblemas en el Santuario Atracasol de Dalaran
-- https://wotlkdb.com/?achievement=4785
SET @ID := 4785;
DELETE FROM `achievement_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`) VALUES
(@ID, 'esES','Intendente de emblemas en el Santuario Atracasol de Dalaran', 'Tus logros en Rasganorte no han pasado desapercibidos, amigo.$B$BLos emblemas que hayas ganado se pueden usar para comprar equipo de los distintos Intendente de emblemas en Dalaran.$B$BPuede encontrarnos en el Santuario Atracasol, donde cada variedad de emblema tiene su propio intendente.$B$B¡Esperamos tu llegada!'),
(@ID, 'esMX','Intendente de emblemas en el Santuario Atracasol de Dalaran', 'Tus logros en Rasganorte no han pasado desapercibidos, amigo.$B$BLos emblemas que hayas ganado se pueden usar para comprar equipo de los distintos Intendente de emblemas en Dalaran.$B$BPuede encontrarnos en el Santuario Atracasol, donde cada variedad de emblema tiene su propio intendente.$B$B¡Esperamos tu llegada!');
