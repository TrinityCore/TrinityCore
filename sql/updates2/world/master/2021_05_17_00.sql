
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=20468 AND `AreaTriggerId`=24363); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0

DELETE FROM `conversation_line_template` WHERE `Id` IN (4866, 7600, 6533, 7599, 7598, 8163, 8314, 8312, 8310, 20225, 20224, 20222, 20220, 7596, 4869, 7595, 7594, 7593, 37742, 18025, 18024, 18023, 7592, 4872, 7591, 7590, 7589, 7588, 4875, 7587, 7586, 8309, 8307, 9243, 8305, 7583, 4881, 7582, 7581, 9256, 4895, 7578, 7577, 7576, 2910, 7706);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(4866, 19884, 0, 2, 1, 38134),
(7600, 17659, 0, 0, 1, 38134),
(6533, 17659, 0, 2, 1, 38134),
(7599, 11482, 0, 0, 0, 38134),
(7598, 5636, 0, 0, 0, 38134),
(8163, 0, 0, 0, 0, 38134),
(8314, 9774, 0, 0, 0, 38134),
(8312, 3681, 0, 0, 0, 38134),
(8310, 0, 0, 0, 0, 38134),
(20225, 11749, 0, 0, 0, 38134),
(20224, 11749, 0, 3, 1, 38134),
(20222, 9399, 0, 2, 1, 38134),
(20220, 0, 0, 0, 0, 38134),
(7596, 14841, 0, 0, 0, 38134),
(4869, 14841, 0, 2, 1, 38134),
(7595, 11933, 0, 0, 0, 38134),
(7594, 1957, 0, 0, 0, 38134),
(7593, 0, 0, 0, 0, 38134),
(37742, 0, 0, 0, 0, 38134),
(18025, 15111, 0, 0, 0, 38134),
(18024, 7639, 0, 0, 0, 38134),
(18023, 0, 0, 0, 0, 38134),
(7592, 15209, 0, 0, 0, 38134),
(4872, 15209, 0, 2, 1, 38134),
(7591, 9077, 0, 0, 0, 38134),
(7590, 1924, 0, 0, 0, 38134),
(7589, 0, 0, 0, 0, 38134),
(7588, 15951, 0, 0, 0, 38134),
(4875, 15951, 0, 2, 1, 38134),
(7587, 7189, 0, 0, 0, 38134),
(7586, 0, 0, 0, 0, 38134),
(8309, 10047, 0, 2, 1, 38134),
(8307, 7077, 0, 0, 0, 38134),
(9243, 1805, 0, 0, 0, 38134),
(8305, 0, 0, 0, 0, 38134),
(7583, 14801, 0, 0, 0, 38134),
(4881, 14801, 0, 2, 1, 38134),
(7582, 7522, 0, 0, 0, 38134),
(7581, 2595, 0, 0, 0, 38134),
(9256, 0, 0, 0, 0, 38134),
(4895, 14796, 0, 2, 1, 38134),
(7578, 11324, 0, 0, 0, 38134),
(7577, 2255, 0, 0, 0, 38134),
(7576, 0, 0, 0, 0, 38134),
(2910, 4848, 0, 2, 1, 38134),
(7706, 0, 0, 0, 0, 38134);

DELETE FROM `creature_template_locale` WHERE (`locale`='esMX' AND `entry` IN (166605,175366,166119,168014,166606,165992,166963,165860,168012,165974,169076,169072,170760,169109,169098,169073,169071,170763,169101,169100,169095,169093,169075,170762,170761,170759,170758,168670,169070,175138,165505,173706,176554,176203,176192,176220,173219,171789,173220,169177,165918,170484,170487));
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `NameAlt`, `Title`, `TitleAlt`, `VerifiedBuild`) VALUES
(166605, 'esMX', 'Caballero de la Espada de ébano', 'Caballero de la Espada de Ébano', NULL, NULL, 38134),
(175366, 'esMX', 'Guardia jurafauces', NULL, NULL, NULL, 38134),
(166119, 'esMX', 'Alma condenada', 'Alma condenada', NULL, NULL, 38134),
(168014, 'esMX', 'Desgarrador de almas jurafauces', NULL, NULL, NULL, 38134),
(166606, 'esMX', 'Caballero de la Espada de ébano', 'Caballero de la Espada de ébano', NULL, NULL, 38134),
(165992, 'esMX', 'Desgarrador de almas jurafauces', NULL, NULL, NULL, 38134),
(166963, 'esMX', 'Caballero de la Espada de ébano', 'Caballero de la Espada de Ébano', NULL, NULL, 38134),
(165860, 'esMX', 'Guardia jurafauces', NULL, NULL, NULL, 38134),
(168012, 'esMX', 'Guardia jurafauces', NULL, NULL, NULL, 38134),
(165974, 'esMX', 'Buscador del Crisol', NULL, NULL, NULL, 38134),
(169076, 'esMX', 'Alto señor Bolvar Fordragón', NULL, 'Caballeros de la Espada de Ébano', NULL, 38134),
(169072, 'esMX', 'Tyrande Susurravientos', NULL, 'La guerrera nocturna', NULL, 38134),
(170760, 'esMX', 'Príncipe mercante Gazlowe', NULL, NULL, NULL, 38134),
(169109, 'esMX', 'Fragmento de dominación', NULL, NULL, NULL, 38134),
(169098, 'esMX', 'Fragmento de dominación', NULL, NULL, NULL, 38134),
(169073, 'esMX', 'Lor\'themar Theron', NULL, 'Señor regente de Quel\'Thalas', NULL, 38134),
(169071, 'esMX', 'Genn Cringris', NULL, 'Rey de Gilneas', NULL, 38134),
(170763, 'esMX', 'Muradin Barbabronce', NULL, 'Gran señor feudal', NULL, 38134),
(169101, 'esMX', 'Fragmento de dominación', NULL, NULL, NULL, 38134),
(169100, 'esMX', 'Fragmento de dominación', NULL, NULL, NULL, 38134),
(169095, 'esMX', 'Fragmento de dominación', NULL, NULL, NULL, 38134),
(169093, 'esMX', 'Ritualista de la Espada de Ébano', 'Ritualista de la Espada de Ébano', NULL, NULL, 38134),
(169075, 'esMX', 'Calia Menethil', NULL, NULL, NULL, 38134),
(170762, 'esMX', 'Alleria Brisaveloz', NULL, NULL, NULL, 38134),
(170761, 'esMX', 'Gelbin Mekkatorque', NULL, 'Manitas Mayor, rey de los gnomos', NULL, 38134),
(170759, 'esMX', 'Primera Arcanista Thalyssra', NULL, NULL, NULL, 38134),
(170758, 'esMX', 'Rokhan', NULL, 'Jefe Lanza Negra', NULL, 38134),
(168670, 'esMX', 'Controlador de reinicio', NULL, NULL, NULL, 38134),
(169070, 'esMX', 'Alto señor Darion Mograine', NULL, 'Jinete de la Espada de Ébano', NULL, 38134),
(175138, 'esMX', 'Alleria Brisaveloz', NULL, NULL, NULL, 38134),
(165505, 'esMX', 'Loretta Banks', NULL, 'Especialista de vuelo', NULL, 38134),
(173706, 'esMX', 'Mummiaabu', NULL, NULL, NULL, 38134),
(176554, 'esMX', 'Alto señor Darion Mograine', NULL, 'Jinete de la Espada de Ébano', NULL, 38134),
(176203, 'esMX', 'Tanaya Perch', NULL, NULL, NULL, 38134),
(176192, 'esMX', 'Xavier Carpintero', NULL, NULL, NULL, 38134),
(176220, 'esMX', 'Antoinette Jardenne', NULL, NULL, NULL, 38134),
(173219, 'esMX', 'Espectador preocupado', 'Espectadora preocupada', NULL, NULL, 38134),
(171789, 'esMX', 'Alta inquisidora Melenablanca', NULL, 'Jinete de la Espada de Ébano', NULL, 38134),
(173220, 'esMX', 'Guardia de Ventormenta', 'Guardia de Ventormenta', NULL, NULL, 38134),
(169177, 'esMX', 'Caballero de la Espada de Ébano', 'Caballero de la Espada de Ébano', NULL, NULL, 38134),
(165918, 'esMX', 'Alto señor Darion Mograine', NULL, 'Jinete de la Espada de Ébano', NULL, 38134),
(170484, 'esMX', 'Roedor de huesos helados', NULL, NULL, NULL, 38134),
(170487, 'esMX', 'Vigía guardapiedra', NULL, NULL, NULL, 38134);

UPDATE `creature_template_locale` SET `Name`='World Trigger', `VerifiedBuild`=38134 WHERE (`entry`=126605 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=116633 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=115634 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=1752 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=150119 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=61840 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=61839 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=6090 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=1478 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=51348 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140407 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=58167 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=1327 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140403 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=42339 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `Title`='Directora de talento y liderazgo', `VerifiedBuild`=38134 WHERE (`entry`=155011 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=1756 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=340 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=1328 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=68 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=44237 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=38821 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140253 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=6089 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=3629 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=61841 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=42421 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=1477 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=49540 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=88316 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=107104 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=108983 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=108988 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=107541 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=107540 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=109010 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=108982 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=108981 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=107542 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=107543 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=110747 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=107953 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=107539 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=105628 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=103205 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=102592 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=101929 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=95093 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=79414 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=100448 AND `locale`='esMX');


DELETE FROM `quest_template_locale` WHERE (`locale`='esMX' AND `ID` IN (59907,59752,61874,59751,56775,60129,60545));
INSERT INTO `quest_template_locale` (`ID`, `locale`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `QuestCompletionLog`, `VerifiedBuild`) VALUES
(59907, 'esMX', 'Amenaza de jurafauces', 'Derrota a $1oa enemigos jurafauces en el Crisol de los Malditos.', 'Nuestros caballeros son fuertes, pero no tienen oportunidad contra este oponente si están dispersos.\n\nDebemos reducir las filas de nuestro enemigo. La Espada de Ébano no nos será muy útil si acaban con ellos.', '', '', '', '', '', '', 38134),
(59752, 'esMX', 'Una hoja rota', 'Reúne a $1oa caballeros de la Espada de Ébano en el Crisol de los Malditos.', 'Las energías caóticas de este lugar han dispersado a la Espada de Ébano.\n\nNo creo que las bendiciones de Azeroth te acompañen en este lugar, $c. Necesitaremos aliados para sobrevivir aquí.\n\nTenemos que encontrarlos rápido, antes de que no puedan resistir más.', '', '', '', '', '', '', 38134),
(61874, 'esMX', 'Shadowlands: un llamado escalofriante', 'Reúnete con Darion Mograine fuera del Fuerte Grommash en Orgrimmar.', 'Ha llegado la hora, $c.\n\nEl alto señor Bolvar Fordragón solicita tu presencia en la cima de la Ciudadela de la Corona de Hielo. Ven a verme en Orgrimmar y te llevaré hasta él.\n\nNo quiero hacerlo esperar.', '', '', '', '', '', 'Preséntate ante Bolvar Fordragón en el Trono Helado.', 38134),
(59751, 'esMX', 'A través del cielo destrozado', 'Completa el ritual en el Trono Helado para abrir una falla a las Fauces.', 'Cuando Sylvanas destruyó el Yelmo de dominación, ese mismo poder quedó impregnado en ella.\n\nSiento los ecos de ese poder, y sé a dónde fue.\n\nSi quieres rescatar a tus líderes, el yelmo destruido puede abrir un camino. Pero no puede traerte de regreso. Eso deberás hacerlo por tu cuenta.\n\nEl riesgo es grande, $n, pero no hay otra forma. Comenzaremos el ritual de inmediato.', '', '', '', '', '', 'Habla con Lord Darion Mograine en el Crisol de los Malditos.', 38134),
(56775, 'esMX', 'Entrada en calor', 'Entrena con un muñeco de combate para entrar en calor.', 'Prepárate, $n. Estamos cerca de la isla donde se perdió la última expedición.\n\nEntra en calor con estos muñecos de combate. Necesitamos que todos estén listos para enfrentarse a lo que sea que nos espere en esa isla.', '', '', '', '', '', '', 38134),
(60129, 'esMX', 'Un extraño en tierras aún más extrañas', 'Busca la forma de entrar a Oribos y averigua lo que está pasando.', '<Llegas $gsolo:sola; al precipicio de una ciudad extraña y sabes que los líderes de Azeroth siguen atrapados en las Fauces.\n\nDonde sea que estés, claramente este lugar está muy, muy lejos de casa.\n\nParece que han notado tu llegada.>', '', '', '', '', '', '', 38134),
(60545, 'esMX', 'Shadowlands: un llamado escalofriante', 'Reúnete con Darion Mograine fuera del Castillo de Ventormenta.', 'Ha llegado la hora, $c.\n\nEl alto señor Bolvar Fordragón solicita tu presencia en la cima de la Ciudadela de la Corona de Hielo. Ven a verme en Ventormenta y te llevaré hasta él.\n\nNo quiero hacerlo esperar.', '', '', '', '', '', 'Preséntate ante Bolvar Fordragón en el Trono Helado.', 38134);

UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=50046 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=28238 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=14482 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=27210 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=26209 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=46268 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=48506 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=42978 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `LogTitle`='Mareas de Guerra', `VerifiedBuild`=38134 WHERE (`ID`=46727 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=13036 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=12818 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=12522 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=48642 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=48641 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=42234 AND `locale`='esMX');


DELETE FROM `quest_objectives_locale` WHERE (`locale`='esMX' AND `ID` IN (397209,397055,406785,406784,406783,398944,398943,398942,398941,398940,398939,391353,397741,397736,397669,405017,406745,406744));
INSERT INTO `quest_objectives_locale` (`ID`, `locale`, `QuestId`, `StorageIndex`, `Description`, `VerifiedBuild`) VALUES
(397209, 'esMX', 59907, 0, 'Fuerzas jurafauces asesinadas', 38134),
(397055, 'esMX', 59752, 0, 'Caballero de la muerte convocado', 38134),
(406785, 'esMX', 61874, 0, 'Usa el teletransportador para ir al Trono Helado', 38134),
(406784, 'esMX', 61874, 2, 'Atraviesa el Portón de la muerte a Acherus.', 38134),
(406783, 'esMX', 61874, 1, 'Aprende sobre el destino de tus líderes', 38134),
(398944, 'esMX', 59751, 5, 'Ritual finalizado', 38134),
(398943, 'esMX', 59751, 4, 'Cuarto fragmento colocado', 38134),
(398942, 'esMX', 59751, 3, 'Tercer fragmento colocado', 38134),
(398941, 'esMX', 59751, 2, 'Segundo fragmento colocado', 38134),
(398940, 'esMX', 59751, 1, 'Primer fragmento colocado', 38134),
(398939, 'esMX', 59751, 0, 'Escucha las instrucciones de Bolvar', 38134),
(391353, 'esMX', 56775, 0, 'Entrena con un muñeco de práctica de combate', 38134),
(397741, 'esMX', 60129, 2, 'Habla con Kah-Delen', 38134),
(397736, 'esMX', 60129, 1, 'Sigue a los guardias hasta Oribos', 38134),
(397669, 'esMX', 60129, 0, 'Intenta comunicarte', 38134),
(405017, 'esMX', 60545, 0, 'Usa el teletransportador para ir al Trono Helado', 38134),
(406745, 'esMX', 60545, 2, 'Atraviesa el Portón de la muerte a Acherus.', 38134),
(406744, 'esMX', 60545, 1, 'Aprende sobre el destino de tus líderes', 38134);

UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=296295 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=266167 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=265836 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=265757 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=265756 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=265755 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=265754 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=292355 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=292354 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=337818 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `Description`='Ve al Consejo de guerra en el Castillo de Ventormenta', `VerifiedBuild`=38134 WHERE (`ID`=337817 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=292699 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=292697 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=283946 AND `locale`='esMX');



DELETE FROM `quest_greeting_locale` WHERE (`ID`=165918 AND `Type`=0 AND `locale`='esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(165918, 0, 'esMX', 'La Espada de Ébano prevalecerá.', 38134);


DELETE FROM `quest_poi` WHERE (`QuestID`=48641 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(48641, 0, 0, -1, 0, 0, 1220, 646, 0, 0, 0, 0, 0, 1289000, 0, 38134); -- -Unknown-

UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48642 AND `BlobIndex`=2 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48642 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48642 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=42234 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
DELETE FROM `quest_poi_points` WHERE (`QuestID`=48641 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(48641, 0, 0, -1625, 3202, 129, 38134); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48642 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48642 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48642 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=42234 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-

DELETE FROM `spell_target_position` WHERE (`ID`=341618 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(341618, 0, 0, -8548.7001953125, 468.141998291015625, 104.5780029296875, 38134); -- Spell: 341618 (Boost Experience - BfA / Shadowlands - Gryphon Teleport) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=329463 AND `EffectIndex`=1);
UPDATE `spell_target_position` SET `MapID`=0, `PositionX`=0, `PositionY`=0, `PositionZ`=0, `VerifiedBuild`=38134 WHERE (`ID`=348402 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=328796 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=333607 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (88316 /*88316 (Muñeco de entrenamiento) - Training Dummy Marker, Passive Uber DoT*/, 170484 /*170484 (Roedor de huesos helados)*/, 170487 /*170487 (Vigía guardapiedra)*/, 107104 /*107104 (Muñeco objetivo) - Boost 2.0 - Unkillable Target Dummy*/, 108983 /*108983 (Navegante Lane)*/, 107541 /*107541 (Teniente Warren)*/, 108988 /*108988 (Teniente Murray)*/, 107540 /*107540 (Recluta de la Alianza)*/, 108982 /*108982 (Navegante Gibson)*/, 109010 /*109010 (Infantería de la Alianza)*/, 107542 /*107542 (Oteador de la Alianza)*/, 108981 /*108981 (Marinero de cubierta)*/, 105628 /*105628 (Mago Filinthus)*/, 103205 /*103205 (Barco)*/, 95093 /*95093 (Almirante Walsh)*/, 107543 /*107543 (Grifo nevado acorazado)*/, 101929 /*101929 (Mejora 2.0: conejito invisible) - Boost 2.0 - Wait For Player - Cover*/, 110747 /*110747 (Infantería de la Alianza)*/, 102592 /*102592 (Infantería de la Alianza) - Change Faction*/, 107539 /*107539 (Recluta de la Alianza)*/, 79414 /*79414 (Muñeco de entrenamiento) - Training Dummy Marker*/, 107953 /*107953 (Anacoreta Taliah)*/, 100448 /*100448 (General Bret Hughes)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(88316, 0, 0, 0, 1, 0, 0, 0, 0, '98892 167347'), -- 88316 (Muñeco de entrenamiento) - Training Dummy Marker, Passive Uber DoT
(170484, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 170484 (Roedor de huesos helados)
(170487, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 170487 (Vigía guardapiedra)
(107104, 0, 0, 0, 1, 0, 0, 0, 0, '212543'), -- 107104 (Muñeco objetivo) - Boost 2.0 - Unkillable Target Dummy
(108983, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 108983 (Navegante Lane)
(107541, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 107541 (Teniente Warren)
(108988, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 108988 (Teniente Murray)
(107540, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 107540 (Recluta de la Alianza)
(108982, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 108982 (Navegante Gibson)
(109010, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 109010 (Infantería de la Alianza)
(107542, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 107542 (Oteador de la Alianza)
(108981, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 108981 (Marinero de cubierta)
(105628, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 105628 (Mago Filinthus)
(103205, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103205 (Barco)
(95093, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 95093 (Almirante Walsh)
(107543, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 107543 (Grifo nevado acorazado)
(101929, 0, 0, 0, 1, 0, 0, 0, 0, '206454'), -- 101929 (Mejora 2.0: conejito invisible) - Boost 2.0 - Wait For Player - Cover
(110747, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110747 (Infantería de la Alianza)
(102592, 0, 0, 0, 1, 0, 0, 0, 0, '224443'), -- 102592 (Infantería de la Alianza) - Change Faction
(107539, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 107539 (Recluta de la Alianza)
(79414, 0, 0, 0, 1, 0, 0, 0, 0, '98892'), -- 79414 (Muñeco de entrenamiento) - Training Dummy Marker
(107953, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 107953 (Anacoreta Taliah)
(100448, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 100448 (General Bret Hughes)

UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=166605; -- 166605 (Caballero de la Espada de ébano)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=166119; -- 166119 (Doomed Soul)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=169071; -- 169071 (Genn Greymane)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=116633; -- 116633 (Efecto)
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=176220; -- 176220 (Antoinette Jardenne)

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=1 AND `Entry` IN (176220,340,61841,155011,1328,121541,58167,111190,44237,173706,176203,3629,1756,32520,171789,721,42421,1327,6090,6089,42339,176554,38821,176192,49540,51348,68,173219,1478,1477,169177,173220,88316,170484,170487,107104,108983,107541,108988,107540,108982,109010,107542,108981,105628,103205,95093,107543,101929,110747,102592,107539,79414,107953,100448));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(176220, 1, 45, 60, 0, 0, 1355, 38134),
(340, 1, 1, 60, 0, 0, 864, 38134),
(61841, 1, 1, 60, 0, 0, 864, 38134),
(155011, 1, 1, 60, 0, 0, 181, 38134),
(1328, 1, 1, 60, 0, 0, 378, 38134),
(121541, 1, 45, 45, 0, 0, 336, 38134),
(58167, 1, 1, 60, 0, 0, 864, 38134),
(111190, 1, 10, 45, 0, 0, 773, 38134),
(44237, 1, 1, 60, 0, 0, 864, 38134),
(173706, 1, 1, 60, 0, 0, 864, 38134),
(176203, 1, 45, 60, 0, 0, 1355, 38134),
(3629, 1, 1, 60, 0, 0, 864, 38134),
(1756, 1, 60, 60, 0, 0, 883, 38134),
(32520, 1, 1, 60, 0, 0, 181, 38134),
(171789, 1, 50, 50, 0, 0, 1400, 38134),
(721, 1, 1, 1, 0, 0, 81, 38134),
(42421, 1, 1, 60, 0, 0, 864, 38134),
(1327, 1, 1, 60, 0, 0, 864, 38134),
(6090, 1, 1, 60, 0, 0, 864, 38134),
(6089, 1, 1, 60, 0, 0, 378, 38134),
(42339, 1, 1, 60, 0, 0, 864, 38134),
(176554, 1, 50, 50, 0, 0, 1400, 38134),
(38821, 1, 1, 60, 0, 0, 181, 38134),
(176192, 1, 45, 60, 0, 0, 1355, 38134),
(49540, 1, 1, 1, 0, 0, 81, 38134),
(51348, 1, 60, 60, 0, 0, 883, 38134),
(68, 1, 60, 60, 0, 0, 883, 38134),
(173219, 1, 50, 50, 0, 0, 1400, 38134),
(1478, 1, 1, 60, 0, 0, 864, 38134),
(1477, 1, 1, 60, 0, 0, 864, 38134),
(169177, 1, 50, 50, 0, 0, 1400, 38134),
(173220, 1, 50, 60, 0, 0, 1401, 38134),
(88316, 1, 10, 40, 0, 0, 302, 38134),
(170484, 1, 1, 60, 0, 0, 774, 38134),
(170487, 1, 1, 60, 0, 0, 774, 38134),
(107104, 1, 1, 60, 0, 0, 774, 38134),
(108983, 1, 1, 60, 0, 0, 774, 38134),
(107541, 1, 1, 60, 0, 0, 774, 38134),
(108988, 1, 1, 60, 0, 0, 774, 38134),
(107540, 1, 1, 60, 0, 0, 774, 38134),
(108982, 1, 1, 60, 0, 0, 774, 38134),
(109010, 1, 1, 60, 0, 0, 774, 38134),
(107542, 1, 1, 60, 0, 0, 774, 38134),
(108981, 1, 1, 60, 0, 0, 774, 38134),
(105628, 1, 1, 60, 0, 0, 774, 38134),
(103205, 1, 1, 60, 0, 0, 774, 38134),
(95093, 1, 10, 40, 0, 0, 302, 38134),
(107543, 1, 1, 60, 0, 0, 774, 38134),
(101929, 1, 1, 60, 0, 0, 774, 38134),
(110747, 1, 1, 60, 0, 0, 774, 38134),
(102592, 1, 1, 60, 0, 0, 774, 38134),
(107539, 1, 1, 60, 0, 0, 774, 38134),
(79414, 1, 1, 60, 0, 0, 328, 38134),
(107953, 1, 1, 60, 0, 0, 774, 38134),
(100448, 1, 1, 60, 0, 0, 774, 38134);

UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=467, `VerifiedBuild`=38134 WHERE (`Entry`=140407 AND `DifficultyID`=1);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=288, `VerifiedBuild`=38134 WHERE (`Entry`=140403 AND `DifficultyID`=1);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=288, `VerifiedBuild`=38134 WHERE (`Entry`=140253 AND `DifficultyID`=1);


UPDATE `creature_model_info` SET `BoundingRadius`=0.983263254165649414, `CombatReach`=1.45000004768371582 WHERE `DisplayID`=92410;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=2256;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=32776;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=60853;
UPDATE `creature_model_info` SET `BoundingRadius`=0.875436902046203613, `VerifiedBuild`=38134 WHERE `DisplayID`=24993;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=26800;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=70152;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=27001;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=71914;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=70148;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=70149;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=70145;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=70146;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=70153;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=27000;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=70151;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=70150;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=71913;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72642;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86819;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=23489;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=67693;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=70144;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=16074;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=70354;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=67690;

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (107541,108988,107540,108982,109010,108981,105628,95093,110747,102592,107539,107953,100448));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(107541, 1, 109637, 0, 0, 0, 0, 0, 0, 0, 0), -- Teniente Warren
(108988, 1, 109637, 0, 0, 0, 0, 0, 0, 0, 0), -- Teniente Murray
(107540, 1, 109637, 0, 0, 119202, 0, 0, 0, 0, 0), -- Recluta de la Alianza
(108982, 1, 1493, 0, 0, 0, 0, 0, 0, 0, 0), -- Navegante Gibson
(109010, 1, 109638, 0, 0, 0, 0, 0, 0, 0, 0), -- Infantería de la Alianza
(108981, 1, 1903, 0, 0, 0, 0, 0, 0, 0, 0), -- Marinero de cubierta
(105628, 1, 116470, 0, 0, 0, 0, 0, 0, 0, 0), -- Mago Filinthus
(95093, 1, 155799, 0, 0, 0, 0, 0, 155816, 0, 0), -- Almirante Walsh
(110747, 1, 109637, 0, 0, 0, 0, 0, 0, 0, 0), -- Infantería de la Alianza
(102592, 1, 109637, 0, 0, 0, 0, 0, 0, 0, 0), -- Infantería de la Alianza
(107539, 1, 109637, 0, 0, 119202, 0, 0, 0, 0, 0), -- Recluta de la Alianza
(107953, 1, 119174, 0, 0, 0, 0, 0, 0, 0, 0), -- Anacoreta Taliah
(100448, 1, 923, 0, 0, 0, 0, 0, 0, 0, 0); -- General Bret Hughes

UPDATE `creature_equip_template` SET `ItemID1`=117049 WHERE (`CreatureID`=166606 AND `ID`=5); -- Knight of the Ebon Blade
UPDATE `creature_equip_template` SET `ItemID1`=174488 WHERE (`CreatureID`=166605 AND `ID`=2); -- Caballero de la Espada de ébano
UPDATE `creature_equip_template` SET `ItemID1`=174488 WHERE (`CreatureID`=166606 AND `ID`=4); -- Knight of the Ebon Blade
UPDATE `creature_equip_template` SET `ItemID1`=164980 WHERE (`CreatureID`=166606 AND `ID`=3); -- Knight of the Ebon Blade
UPDATE `creature_equip_template` SET `ItemID1`=75223 WHERE (`CreatureID`=166605 AND `ID`=1); -- Caballero de la Espada de ébano
UPDATE `creature_equip_template` SET `ItemID1`=164981 WHERE (`CreatureID`=166606 AND `ID`=2); -- Knight of the Ebon Blade
UPDATE `creature_equip_template` SET `ItemID1`=163542 WHERE (`CreatureID`=166606 AND `ID`=1); -- Knight of the Ebon Blade
UPDATE `creature_equip_template` SET `ItemID1`=164980 WHERE (`CreatureID`=169177 AND `ID`=6); -- Caballero de la Espada de Ébano
UPDATE `creature_equip_template` SET `ItemID1`=174488 WHERE (`CreatureID`=169177 AND `ID`=4); -- Caballero de la Espada de Ébano
UPDATE `creature_equip_template` SET `ItemID1`=164981 WHERE (`CreatureID`=169177 AND `ID`=3); -- Caballero de la Espada de Ébano
UPDATE `creature_equip_template` SET `ItemID1`=1905 WHERE (`CreatureID`=176192 AND `ID`=1); -- Xavier Carpintero
UPDATE `creature_equip_template` SET `ItemID1`=75223 WHERE (`CreatureID`=169177 AND `ID`=2); -- Caballero de la Espada de Ébano
UPDATE `creature_equip_template` SET `ItemID1`=117049 WHERE (`CreatureID`=169177 AND `ID`=1); -- Caballero de la Espada de Ébano

DELETE FROM `gossip_menu` WHERE (`MenuId`=24065 AND `TextId`=35374);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(24065, 35374, 38134); -- 100448 (General Bret Hughes)

UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=20085 AND `TextId`=29837); -- 0
DELETE FROM `gossip_menu_option` WHERE (`OptionIndex`=0 AND `MenuId` IN (20085,24065));
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(20085, 0, 0, '<Recibe tu citación y vete de la nave.>', 0, 38134),
(24065, 0, 0, 'Estoy listo para comenzar.', 0, 38134);





UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=165918; -- Highlord Darion Mograine
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=166605; -- Caballero de la Espada de ébano
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=165974; -- Buscador del Crisol
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=166119; -- Doomed Soul
UPDATE `creature_template` SET `dynamicflags`=128 WHERE `entry`=166963; -- Caballero de la Espada de ébano
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=44237; -- Maegan Tillman
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=68; -- Guardia de la ciudad de Ventormenta
UPDATE `creature_template` SET `speed_run`=1, `RangeAttackTime`=0, `unit_flags`=131072, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=88316; -- Muñeco de entrenamiento
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=2780, `BaseAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=170484; -- Roedor de huesos helados
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=2780, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=170487; -- Vigía guardapiedra
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=7, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=107104; -- Muñeco objetivo
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=1802, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=108983; -- Navegante Lane
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=1819, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=107541; -- Teniente Warren
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=1819, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=108988; -- Teniente Murray
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=2261, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=107540; -- Recluta de la Alianza
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=2774, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=108982; -- Navegante Gibson
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=1802, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=109010; -- Infantería de la Alianza
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=2774, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=107542; -- Oteador de la Alianza
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=2774, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=108981; -- Marinero de cubierta
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=84, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=105628; -- Mago Filinthus
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=7, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=103205; -- Barco
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=84, `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=95093; -- Almirante Walsh
UPDATE `creature_template` SET `gossip_menu_id`=20085, `minlevel`=60, `maxlevel`=60, `npcflag`=1, `BaseAttackTime`=1500, `unit_flags`=33280, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=4933 WHERE `entry`=107543; -- Grifo nevado acorazado
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=7, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=101929; -- Mejora 2.0: conejito invisible
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=84, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=110747; -- Infantería de la Alianza
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=534, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=102592; -- Infantería de la Alianza
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=2261, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=107539; -- Recluta de la Alianza
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=7, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=131072, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=79414; -- Muñeco de entrenamiento
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=84, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=107953; -- Anacoreta Taliah
UPDATE `creature_template` SET `gossip_menu_id`=24065, `minlevel`=100, `maxlevel`=110, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=100448; -- General Bret Hughes



UPDATE `quest_template` SET `FlagsEx`=2105412, `VerifiedBuild`=38134 WHERE `ID`=59907; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105412, `VerifiedBuild`=38134 WHERE `ID`=59752; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=69206080, `VerifiedBuild`=38134 WHERE `ID`=61874; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=6291520, `VerifiedBuild`=38134 WHERE `ID`=59751; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=60 WHERE `ID`=56775; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=50046; -- -Unknown-
UPDATE `quest_template` SET `Flags`=4194312, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=28238; -- -Unknown-
UPDATE `quest_template` SET `Flags`=3145792, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=14482; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=27210; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=26209; -- -Unknown-
UPDATE `quest_template` SET `RewardSpell`=239804, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=46268; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=48506; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=35660096, `VerifiedBuild`=38134 WHERE `ID`=42978; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=117000, `RewardBonusMoney`=2900, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=60129; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=69206080, `VerifiedBuild`=38134 WHERE `ID`=60545; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=22130, `RewardBonusMoney`=70, `FlagsEx`=2105410, `AllowableRaces`=6130900294268439629, `VerifiedBuild`=38134 WHERE `ID`=46727; -- -Unknown-
UPDATE `quest_template` SET `Flags`=8, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=13036; -- -Unknown-
UPDATE `quest_template` SET `Flags`=8, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=12818; -- -Unknown-
UPDATE `quest_template` SET `Flags`=8, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=12522; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=69206080, `VerifiedBuild`=38134 WHERE `ID`=48642; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=69206080, `VerifiedBuild`=38134 WHERE `ID`=42234; -- -Unknown-


UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=397209; -- 397209
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=397739; -- 397739
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=397738; -- 397738
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=397737; -- 397737
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=397055; -- 397055
UPDATE `quest_objectives` SET `ObjectID`=173229, `Flags`=2, `VerifiedBuild`=38134 WHERE `ID`=406784; -- 406784
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398944; -- 398944
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398943; -- 398943
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398942; -- 398942
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398941; -- 398941
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398940; -- 398940
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398939; -- 398939
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=391353; -- 391353
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=296295; -- 296295
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=266167; -- 266167
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=265836; -- 265836
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=265757; -- 265757
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=265756; -- 265756
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=265755; -- 265755
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=265754; -- 265754
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=289293; -- 289293
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292356; -- 292356
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292355; -- 292355
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292354; -- 292354
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=397741; -- 397741
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=397736; -- 397736
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=397669; -- 397669
UPDATE `quest_objectives` SET `ObjectID`=173229, `Flags`=2, `VerifiedBuild`=38134 WHERE `ID`=406745; -- 406745
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=337818; -- 337818
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=337817; -- 337817
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=264468; -- 264468
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=263436; -- 263436
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292699; -- 292699
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=283946; -- 283946


UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292355 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292354 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292354 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=337818 AND `Index`=0);



UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=352595; -- Colocar fragmento
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=352594; -- Colocar fragmento
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=352593; -- Colocar fragmento
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=352592; -- Colocar fragmento
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353979; -- Teletransportador
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=352591; -- Fragmento de hielo
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=243788; -- Yunque
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=243780; -- Forja de runa
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=202244; -- Transportador de la Plaga
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201857; -- Entrada de Lord Tuétano
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201825; -- Puerta de Colmillosauro
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=202245; -- Transportador de la Plaga
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=243789; -- Yunque
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=243785; -- Yunque
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=245433; -- Forja de alma
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201910; -- Doodad_IceCrown_Icewall02
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=243790; -- Forja
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=243786; -- Yunque
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201911; -- Muro helado
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201563; -- Oratory of the Damned Entrance
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=315955; -- Transportador de la Plaga
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=243791; -- Laboratorio de alquimia
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=243787; -- Forja
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=243779; -- Forja de runa
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=202243; -- Transportador de la Plaga
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=202220; -- Ascensor de Lady Susurramuerte
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201674; -- Banco de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=355461; -- Portón de la muerte a Acherus
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=210181; -- Trofeo de Alamuerte (0,7)
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201531; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201529; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201490; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=209692; -- Placas de Potts
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201422; -- Distrito de los Enanos
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201534; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201538; -- Silla de madera
UPDATE `gameobject_template` SET `ContentTuningId`=337, `VerifiedBuild`=38134 WHERE `entry`=269834; -- Nave de la Alianza
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201526; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201542; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=206110; -- Portal a Claro de la Luna
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=281118; -- Percha de grifo
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201495; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=203762; -- Manzana jugosa
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=207416; -- Aguas de Clarividencia
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201491; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201496; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201527; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201511; -- Casco Antiguo
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201535; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201539; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201492; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201488; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201540; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=190536; -- Barco, rompehielos (Orgullo de Ventormenta)
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201504; -- El Cerdo Borracho
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=293696; -- Barco darnassiano
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201532; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201528; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201536; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201524; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201512; -- Casco Antiguo
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=209039; -- La Dama Misteriosa
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201493; -- Silla de madera
UPDATE `gameobject_template` SET `IconName`='', `Data1`=0, `Data30`=29958, `ContentTuningId`=864, `VerifiedBuild`=38134 WHERE `entry`=203800; -- Barril de pez de canal
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201489; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201537; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201525; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201541; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201521; -- Buzón
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201533; -- Silla de madera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=259008; -- 7.0 Stormwind - Lion's Rest - Phased WMO
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=179965; -- Darkmoon Faire Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=201494; -- Silla de madera
UPDATE `gameobject_template` SET `Data12`=1, `VerifiedBuild`=38134 WHERE `entry`=290743; -- Espada del Alba

DELETE FROM `npc_text` WHERE `ID`=41731;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(41731, 1, 0, 0, 0, 0, 0, 0, 0, 204438, 0, 0, 0, 0, 0, 0, 0, 38134); -- 41731

UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=29837; -- 29837
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=35374; -- 35374


UPDATE `conversation_template` SET `FirstLineID`=36104, `LastLineEndTime`=2121 WHERE `Id`=14424;
UPDATE `conversation_template` SET `FirstLineID`=36102, `LastLineEndTime`=3313 WHERE `Id`=14423;
UPDATE `conversation_template` SET `FirstLineID`=36096, `LastLineEndTime`=6700 WHERE `Id`=12798;
UPDATE `conversation_template` SET `FirstLineID`=36093, `LastLineEndTime`=4461 WHERE `Id`=12818;
UPDATE `conversation_template` SET `FirstLineID`=35650, `LastLineEndTime`=3411 WHERE `Id`=10768;

DELETE FROM `creature_template_locale` WHERE (`entry`=167343 AND `locale`='esMX');
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `NameAlt`, `Title`, `TitleAlt`, `VerifiedBuild`) VALUES
(167343, 'esMX', 'Dracohalcón', NULL, NULL, NULL, 38134);


UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=325131 AND `EffectIndex`=3);

DELETE FROM `creature_template_addon` WHERE `entry`=167343;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(167343, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 167343 (Dracohalcón)



UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=482, `VerifiedBuild`=38134 WHERE (`Entry`=167343 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=10, `ContentTuningID`=741 WHERE (`Entry`=160737 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=23515;


UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=167343; -- Dracohalcón
UPDATE `creature_template` SET `unit_flags`=33554688, `unit_flags2`=67110912, `unit_flags3`=16 WHERE `entry`=160737; -- Muñeco de combate


UPDATE `conversation_template` SET `FirstLineID`=36104, `LastLineEndTime`=2121 WHERE `Id`=14424;
UPDATE `conversation_template` SET `FirstLineID`=36102, `LastLineEndTime`=3313 WHERE `Id`=14423;
UPDATE `conversation_template` SET `FirstLineID`=36096, `LastLineEndTime`=6700 WHERE `Id`=12798;
UPDATE `conversation_template` SET `FirstLineID`=36093, `LastLineEndTime`=4461 WHERE `Id`=12818;
UPDATE `conversation_template` SET `FirstLineID`=35650, `LastLineEndTime`=3411 WHERE `Id`=10768;

DELETE FROM `quest_request_items_locale` WHERE (`ID`=59926 AND `locale`='esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(59926, 'esMX', '¡No me molestes! Ve a atacar a esos muñecos de combate. Muéstrame tu poder.', 38134);


DELETE FROM `quest_request_items` WHERE `ID`=59926;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(59926, 0, 0, 0, 0, '¡No me molestes! Ve a atacar a esos muñecos de combate. Muéstrame tu poder.', 38134); -- -Unknown-


UPDATE `gameobject_template` SET `type`=15, `VerifiedBuild`=38134 WHERE `entry`=349879; -- Transporte de la Horda

UPDATE creature_template SET `scriptname` = 'npc_captain_garrick_156651' WHERE entry= 156651;
UPDATE creature_template SET `scriptname` = 'npc_captain_garrick_156280' WHERE entry= 156280;
UPDATE creature_template SET `scriptname` = 'npc_captain_garrick_161350' WHERE entry= 161350;
UPDATE `creature_template` SET `ScriptName`='npc_riathia_silverstar' WHERE  `entry`=152238;
UPDATE `creature_template` SET `ScriptName`='npc_where_the_road_leads' WHERE  `entry`=500518;
UPDATE `creature_template` SET `ScriptName`='npc_valkyr_battle_maiden_allied' WHERE  `entry`=228534;
UPDATE `creature_template` SET `ScriptName`= 'boss_garothi_worldbreaker' WHERE `entry`= 122450;
UPDATE `creature_template` SET `ScriptName`='npc_danica_the_reclaimer' WHERE `entry`=93823; -- Danica the Reclaimer
UPDATE `creature_template` SET `ScriptName`='npc_odyn' WHERE `entry`=96469; -- Odyn
UPDATE creature_template SET ScriptName="npc_kayn_sunfury_welcome" WHERE entry=93011;
UPDATE creature_template SET scriptname = "npc_mardum_allari" WHERE entry = 94410;
UPDATE `creature_template` SET `ScriptName`='npc_inquisitor_baleful' WHERE  `entry`=93105;
UPDATE `creature_template` SET `ScriptName`='npc_mardum_ashtongue_mystic' WHERE  `entry`=99914;
UPDATE `creature_template` SET `ScriptName`='npc_doom_commander_beliash' WHERE  `entry`=93221;
UPDATE creature_template SET scriptname = "npc_mardum_sevis_brightflame_shivarra" WHERE entry = 99915;
UPDATE creature_template SET scriptname = "npc_mardum_captain" WHERE entry IN (90247, 93693, 94435);
UPDATE creature_template SET scriptname = "npc_mardum_jace_darkweaver" WHERE entry = 96436;
UPDATE `creature_template` SET `ScriptName`='npc_fel_lord_caza' WHERE  `entry`=96441;
UPDATE creature_template SET scriptname = "npc_mardum_izal_whitemoon" WHERE entry = 96653;
UPDATE `creature_template` SET `ScriptName`='npc_kayn_tyranna_fight' WHERE  `entry`=97244;
UPDATE `creature_template` SET `ScriptName`='npc_allari_tyranna_fight' WHERE  `entry`=97962;
UPDATE `creature_template` SET `ScriptName`='npc_jace_tyranna_fight' WHERE  `entry`=97959;
UPDATE `creature_template` SET `ScriptName`='npc_brood_queen_tyranna' WHERE  `entry`=93802;
UPDATE `creature_template` SET `ScriptName`='npc_korvas_tyranna_fight' WHERE  `entry`=98712;
UPDATE creature_template SET scriptname = "npc_mardum_kayn_sunfury_end" WHERE entry = 97303;
UPDATE `creature_template` SET `ScriptName`='npc_kayn_sunfury' WHERE  `entry`=93127;
UPDATE `creature_template` SET `ScriptName`='npc_allari' WHERE  `entry`=96655;
UPDATE `creature_template` SET `ScriptName`='npc_cyana' WHERE  `entry`=96420;
UPDATE `creature_template` SET `ScriptName`='npc_korvas' WHERE  `entry`=99045;
UPDATE `creature_template` SET `ScriptName`='npc_mannethrel' WHERE  `entry`=96652;
UPDATE creature_template SET ScriptName="npc_q38689" WHERE entry=92782;
UPDATE creature_template SET ScriptName="npc_q38689" WHERE entry=92776;
UPDATE creature_template SET ScriptName="npc_q38723" WHERE entry=92990;
UPDATE creature_template SET ScriptName="npc_q38723" WHERE entry=97632;
UPDATE creature_template SET ScriptName="npc_99443" WHERE entry=99443;
UPDATE creature_template SET ScriptName="npc_q39685" WHERE entry=99709;
UPDATE creature_template SET ScriptName="npc_q39685" WHERE entry=99731;
UPDATE creature_template SET ScriptName="npc_q39685" WHERE entry=99732;
UPDATE creature_template SET ScriptName="npc_96675" WHERE entry=96675;
UPDATE creature_template SET ScriptName="npc_97644" WHERE entry=97644;
UPDATE creature_template SET ScriptName="npc_92718" WHERE entry=92718;
UPDATE creature_template SET ScriptName="npc_q38672" WHERE entry=103658;
UPDATE creature_template SET ScriptName="npc_q38672" WHERE entry=103655;
UPDATE creature_template SET ScriptName="npc_97978" WHERE entry=97978;
UPDATE creature_template SET ScriptName="npc_96682" WHERE entry=96682;
UPDATE creature_template SET ScriptName="npc_96783" WHERE entry=96783;
























