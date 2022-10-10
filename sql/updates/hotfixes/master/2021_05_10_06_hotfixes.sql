DELETE FROM `broadcast_text_locale` WHERE `locale` = 'itIT' AND `ID` IN (209968, 208581);
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(209968, 'itIT', '', 'Ti do il benvenuto. Ti interessano delle Chiavi del Potere?', 38134),
(208581, 'itIT', 'Salve, NOMEUTENTE. Spero che tu stia trascorrendo una GENERA AGGETTIVO POSITIVO CASUALE giornata.', '', 38134);

DELETE FROM `item_search_name_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(52489, 'itIT', 'Occhiali da Sole con Strass', 38134);

DELETE FROM `currency_types_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `currency_types_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1191, 'itIT', 'Punti Valore', 'Una valuta utilizzata per aumentare il potere degli oggetti depredati nelle spedizioni Mitiche.', 38134),
(1602, 'itIT', 'Punti Conquista', 'Ottenuto dalle attività di PvP Classificato. Usalo per acquistare equipaggiamento a Oribos.', 38134),
(1828, 'itIT', 'Cenere d\'Anima', 'Una fonte grezza di potere trovata a Torgast. Usata per alimentare la Stanza dell\'Incisore di Rune.', 38134);

DELETE FROM `spell_name_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(328547, 'itIT', 'Aculeo Osseo Seghettato', 38134),
(335718, 'itIT', 'Rappresaglia', 38134),
(340882, 'itIT', 'Richiamo di Gassino', 38134),
(351967, 'itIT', 'Richiamo di Bollirose', 38134),
(320914, 'itIT', 'Clessidra del Cronomante', 38134),
(350249, 'itIT', 'Distorsione Temporale', 38134),
(320740, 'itIT', 'Ossessione', 38134),
(335161, 'itIT', 'Esaurimento d\'Animum', 38134),
(340433, 'itIT', 'Dono di Oblio del Peccato', 38134),
(220358, 'itIT', 'Assalti Ciclonici', 38134),
(352329, 'itIT', '[DNT] Learn Bananas', 38134),
(163708, 'itIT', 'Falò Vincolamagie', 38134),
(34477, 'itIT', 'Depistaggio', 38134),
(202335, 'itIT', 'Doppio Barile', 38134),
(209584, 'itIT', 'Tè della Concentrazione Zen', 38134),
(235219, 'itIT', 'Prontezza Gelida', 38134),
(243435, 'itIT', 'Birra Fortificante', 38134),
(248518, 'itIT', 'Intrusione', 38134),
(321995, 'itIT', 'Presenza Ipotermica', 38134),
(327193, 'itIT', 'Momento di Gloria', 38134),
(352497, 'itIT', '[DNT] Teleport', 38134),
(294587, 'itIT', 'Aculei di Obleron x2', 38134),
(294588, 'itIT', 'Aculei di Obleron x3', 38134),
(322841, 'itIT', 'Alafuriosa', 38134),
(324919, 'itIT', 'Alafuriosa', 38134),
(352816, 'itIT', '[DNT] Grant Keystone', 38134),
(341220, 'itIT', 'Balestra dei Giurafauce', 38134),
(321136, 'itIT', 'Luce Brillante', 38134),
(255260, 'itIT', 'Marchio del Caos', 38134),
(281242, 'itIT', 'Marchio del Caos', 38134),
(337541, 'itIT', 'Spirito delle Fiamme Oscure', 38134),
(71, 'itIT', 'Avanguardia', 38134),
(48263, 'itIT', 'Veterano della Terza Guerra', 38134),
(245013, 'itIT', 'Equilibrio del Mastro Birraio', 38134),
(300346, 'itIT', 'Adepto dell\'Orso', 38134),
(316714, 'itIT', 'Veterano della Terza Guerra', 38134),
(319278, 'itIT', 'Veterano della Quarta Guerra', 38134),
(353367, 'itIT', 'Egida della Luce', 38134),
(337334, 'itIT', 'Altocielo di Keefer', 38134),
(336061, 'itIT', 'Carica di Poltiglia', 38134),
(340271, 'itIT', 'Contagio Coagulato', 38134),
(327332, 'itIT', 'Infusione Arma', 38134),
(45525, 'itIT', 'Intelletto Arcano', 38134),
(354135, 'itIT', 'Bottom Barrier Visual', 38134),
(321828, 'itIT', 'Tortina da Tè', 38134),
(321832, 'itIT', 'Palla Prigioniera', 38134),
(326180, 'itIT', 'Marchiatura Gelida', 38134),
(322416, 'itIT', 'Frattura Rocciosa', 38134);

DELETE FROM `criteria_tree_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(91079, 'itIT', 'Login with Bananas license (Charity Pet 2021)', 38134),
(91080, 'itIT', '', 38134),
(91081, 'itIT', 'Earn character-level Bananas achievement', 38134),
(91082, 'itIT', '', 38134),
(91386, 'itIT', 'Ve\'nari reputation is Apprehensive', 38134),
(91388, 'itIT', 'Ve\'nari reputation is Tentative', 38134),
(91390, 'itIT', 'Ve\'nari reputation is Ambivalent', 38134),
(91392, 'itIT', 'Ve\'nari reputation is Cordial', 38134),
(91393, 'itIT', '', 38134),
(91503, 'itIT', 'Do You Have All Rank 1s in a Covenant Sanctum?', 38134),
(91504, 'itIT', 'Login test for backporting of \"do you have all level 1 buildings\"', 38134),
(91505, 'itIT', '', 38134),
(91506, 'itIT', 'Do You Have All Rank 2s in a Covenant Sanctum?', 38134),
(91507, 'itIT', 'Login test for backporting of \"do you have all level 2 buildings\"', 38134),
(91508, 'itIT', '', 38134),
(91509, 'itIT', 'Do You Have All Rank 3s in a Covenant Sanctum?', 38134),
(91510, 'itIT', 'Login test for backporting of \"do you have all level 3 buildings\"', 38134),
(91511, 'itIT', '', 38134),
(91387, 'itIT', 'Ottieni la reputazione Ansiosa con Ve\'nari.', 38134),
(91389, 'itIT', 'Ottieni la reputazione Incerta con Ve\'nari.', 38134),
(91391, 'itIT', 'Ottieni la reputazione Esitante con Ve\'nari.', 38134),
(87404, 'itIT', 'Vinci scontri PvP classificati durante la Stagione 1 di Shadowlands a un indice PvP di 1.000 o superiore', 38134),
(87408, 'itIT', 'Vinci scontri PvP classificati durante la Stagione 1 di Shadowlands a un indice PvP di 1.000 o superiore', 38134);

DELETE FROM `specialization_spells_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `specialization_spells_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(5164, 'itIT', '', 38134),
(5369, 'itIT', '', 38134),
(5480, 'itIT', '', 38134),
(6271, 'itIT', '', 38134),
(6285, 'itIT', '', 38134),
(6286, 'itIT', '', 38134),
(6287, 'itIT', '', 38134),
(6288, 'itIT', '', 38134),
(6289, 'itIT', '', 38134),
(6292, 'itIT', '', 38134),
(6293, 'itIT', '', 38134),
(6294, 'itIT', '', 38134),
(6295, 'itIT', '', 38134),
(6298, 'itIT', '', 38134),
(6299, 'itIT', '', 38134),
(6306, 'itIT', '', 38134),
(6377, 'itIT', '', 38134),
(6455, 'itIT', '', 38134),
(6457, 'itIT', '', 38134),
(6463, 'itIT', '', 38134),
(6478, 'itIT', '', 38134),
(6531, 'itIT', '', 38134),
(6532, 'itIT', '', 38134),
(6533, 'itIT', '', 38134),
(6534, 'itIT', '', 38134),
(6535, 'itIT', '', 38134),
(6608, 'itIT', '', 38134),
(5262, 'itIT', '', 38134),
(6609, 'itIT', '', 38134),
(5320, 'itIT', '', 38134),
(5521, 'itIT', '', 38134),
(5580, 'itIT', '', 38134),
(5938, 'itIT', '', 38134),
(6113, 'itIT', '', 38134),
(6114, 'itIT', '', 38134),
(6193, 'itIT', '', 38134),
(6195, 'itIT', '', 38134),
(6324, 'itIT', '', 38134),
(6400, 'itIT', '', 38134),
(6434, 'itIT', '', 38134),
(6447, 'itIT', '', 38134),
(6515, 'itIT', '', 38134),
(6516, 'itIT', '', 38134),
(6610, 'itIT', '', 38134);

DELETE FROM `battlemaster_list_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `battlemaster_list_locale` (`ID`, `locale`, `Name_lang`, `GameType_lang`, `ShortDescription_lang`, `LongDescription_lang`, `VerifiedBuild`) VALUES
(100, 'itIT', 'CdB classificato', '', '', '', 38134),
(866, 'itIT', 'Tutte le Arene', 'Rissa', '', '', 38134),
(1047, 'itIT', 'Mugambala', '', '', '', 38134),
(1048, 'itIT', 'Robodromo', '', '', '', 38134),
(1049, 'itIT', 'Presidio della Pesca', '', '', '', 38134),
(1050, 'itIT', 'Dominio Empireo', '', '', '', 38134);

DELETE FROM `area_table_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(12876, 'itIT', 'Seggio del Primus', 38134),
(12917, 'itIT', 'Oblio del Peccato', 38134),
(12924, 'itIT', 'Selvarden', 38134),
(13387, 'itIT', 'Selvarden', 38134),
(6852, 'itIT', 'Arena d\'Addestramento', 38134);

DELETE FROM `char_titles_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `char_titles_locale` (`ID`, `locale`, `Name_lang`, `Name1_lang`, `VerifiedBuild`) VALUES
(679, 'itIT', 'Barone %s', 'Barone %s', 38134),
(680, 'itIT', 'Baronessa %s', 'Baronessa %s', 38134),
(682, 'itIT', 'Conte %s', 'Conte %s', 38134),
(683, 'itIT', 'Contessa %s', 'Contessa %s', 38134);

DELETE FROM `item_sparse_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(52489, 'itIT', '', '', '', '', 'Occhiali da Sole con Strass', 38134),
(180317, 'itIT', '', '', '', '', 'Pozione di Cura dell\'Anima', 38134),
(180318, 'itIT', '', '', '', '', 'Pozione di Mana dell\'Anima', 38134),
(155622, 'itIT', '', '', '', '', 'Trofeo del Condottiero', 38134),
(159570, 'itIT', '', '', '', '', 'Sigillo di Battaglia', 38134),
(164580, 'itIT', '', '', '', '', 'Sigillo di Battaglia', 38134),
(164581, 'itIT', '', '', '', '', 'Sigillo di Battaglia', 38134),
(164582, 'itIT', '', '', '', '', 'Sigillo di Battaglia', 38134),
(164583, 'itIT', '', '', '', '', 'Sigillo di Battaglia', 38134),
(164584, 'itIT', '', '', '', '', 'Trofeo del Condottiero', 38134),
(164585, 'itIT', '', '', '', '', 'Trofeo del Condottiero', 38134),
(164586, 'itIT', '', '', '', '', 'Trofeo del Condottiero', 38134),
(164587, 'itIT', '', '', '', '', 'Trofeo del Condottiero', 38134),
(164950, 'itIT', '', '', '', '', 'Trofeo del Condottiero', 38134),
(164951, 'itIT', '', '', '', '', 'Sigillo di Battaglia', 38134),
(164952, 'itIT', '', '', '', '', 'Sigillo di Battaglia', 38134),
(164953, 'itIT', '', '', '', '', 'Sigillo di Battaglia', 38134),
(164954, 'itIT', '', '', '', '', 'Sigillo di Battaglia', 38134),
(164955, 'itIT', '', '', '', '', 'Sigillo di Battaglia', 38134),
(164956, 'itIT', '', '', '', '', 'Trofeo del Condottiero', 38134),
(164957, 'itIT', '', '', '', '', 'Trofeo del Condottiero', 38134),
(164958, 'itIT', '', '', '', '', 'Trofeo del Condottiero', 38134),
(164959, 'itIT', '', '', '', '', 'Trofeo del Condottiero', 38134),
(168316, 'itIT', '', '', '', '', 'Sigillo di Battaglia', 38134),
(171090, 'itIT', '', '', '', '', 'Sigillo di Battaglia', 38134),
(171091, 'itIT', '', '', '', '', 'Sigillo di Battaglia', 38134),
(171092, 'itIT', '', '', '', '', 'Sigillo di Battaglia', 38134),
(171093, 'itIT', '', '', '', '', 'Sigillo di Battaglia', 38134),
(171095, 'itIT', '', '', '', '', 'Trofeo del Condottiero', 38134),
(171096, 'itIT', '', '', '', '', 'Trofeo del Condottiero', 38134),
(171097, 'itIT', '', '', '', '', 'Trofeo del Condottiero', 38134),
(171098, 'itIT', '', '', '', '', 'Trofeo del Condottiero', 38134),
(171099, 'itIT', '', '', '', '', 'Trofeo del Condottiero', 38134),
(172890, 'itIT', '', '', '', '', 'Sigillo di Battaglia', 38134),
(172891, 'itIT', '', '', '', '', 'Sigillo di Battaglia', 38134),
(172892, 'itIT', '', '', '', '', 'Sigillo di Battaglia', 38134),
(172893, 'itIT', '', '', '', '', 'Sigillo di Battaglia', 38134),
(172894, 'itIT', '', '', '', '', 'Sigillo di Battaglia', 38134),
(172895, 'itIT', '', '', '', '', 'Trofeo del Condottiero', 38134),
(172896, 'itIT', '', '', '', '', 'Trofeo del Condottiero', 38134),
(172897, 'itIT', '', '', '', '', 'Trofeo del Condottiero', 38134),
(172898, 'itIT', '', '', '', '', 'Trofeo del Condottiero', 38134),
(172899, 'itIT', '', '', '', '', 'Trofeo del Condottiero', 38134),
(186099, 'itIT', 'Questo dispositivo fa apparire nei tuoi pezzi d\'equipaggiamento una fenditura in miniatura, della forma perfetta per ospitare una gemma.', '', '', '', 'Apparato di Riallineamento Spaziale', 38134),
(183122, 'itIT', '', '', '', '', 'Mantello della Morte', 38134),
(183131, 'itIT', '', '', '', '', 'Ancora di Stigia', 38134),
(183135, 'itIT', '', '', '', '', 'Evocazione dei Caduti', 38134),
(183136, 'itIT', '', '', '', '', 'Rattofauce Incendiario', 38134),
(183141, 'itIT', '', '', '', '', 'Magma di Stigia', 38134),
(183165, 'itIT', '', '', '', '', 'Balestra dei Giurafauce', 38134),
(183187, 'itIT', '', '', '', '', 'Incanto del Tessiombre', 38134),
(174876, 'itIT', '', '', '', '', 'Occhio Cavato di N\'zoth', 38134),
(187116, 'itIT', '', '', '', '', 'Manichino a Molla', 38134);

DELETE FROM `map_difficulty_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `map_difficulty_locale` (`ID`, `locale`, `Message_lang`, `VerifiedBuild`) VALUES
(4775, 'itIT', '', 38134);

DELETE FROM `mount_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `mount_locale` (`ID`, `locale`, `Name_lang`, `SourceText_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1458, 'itIT', 'Antico Errante', '|cFFFFD200Promozione|r', 'Strenui difensori delle foreste di Azeroth, gli Antichi sono famosi anche per le loro gloriose chiome di foglie, che cambiano colore con le stagioni.', 38134);

DELETE FROM `player_condition_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(90553, 'itIT', '', 38134),
(90651, 'itIT', '', 38134),
(90652, 'itIT', '', 38134),
(78581, 'itIT', '', 38134),
(87399, 'itIT', 'Richiede che Ve\'nari abbia di te un\'opinione Riconoscente o superiore.', 38134);

DELETE FROM `achievement_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(15010, 'itIT', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Apprehensive standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Apprehensive [DNT]', '', 38134),
(15011, 'itIT', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Tentative standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Tentative [DNT]', '', 38134),
(15012, 'itIT', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Ambivalent standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Ambivalent [DNT]', '', 38134),
(15013, 'itIT', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Cordial standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Cordial [DNT]', '', 38134),
(14340, 'itIT', 'Sconfiggi un boss nella Via dell\'Ascensione.', 'La Via Verso l\'Ascensione 1', 'Sblocca altre sfide nella Via dell\'Ascensione.', 38134),
(14342, 'itIT', 'Sconfiggi tre boss nella Via dell\'Ascensione.', 'La Via Verso l\'Ascensione 3', 'Sblocca altre sfide nella Via dell\'Ascensione.', 38134),
(14343, 'itIT', 'Sconfiggi cinque boss nella Via dell\'Ascensione.', 'La Via Verso l\'Ascensione 5', 'Sblocca altre sfide nella Via dell\'Ascensione.', 38134),
(14344, 'itIT', 'Sconfiggi sette boss nella Via dell\'Ascensione.', 'La Via Verso l\'Ascensione 7', 'Sblocca altre sfide nella Via dell\'Ascensione.', 38134),
(14345, 'itIT', 'Sconfiggi 12 boss nella Via dell\'Ascensione.', 'La Via Verso l\'Ascensione 12', 'Sblocca altre sfide nella Via dell\'Ascensione.', 38134),
(14346, 'itIT', 'Sconfiggi 16 boss nella Via dell\'Ascensione.', 'La Via Verso l\'Ascensione 16', 'Sblocca altre sfide nella Via dell\'Ascensione.', 38134),
(14348, 'itIT', 'Sconfiggi 20 boss nella Via dell\'Ascensione.', 'La Via Verso l\'Ascensione 20', 'Sblocca altre sfide nella Via dell\'Ascensione.', 38134),
(14349, 'itIT', 'Sconfiggi 24 boss nella Via dell\'Ascensione.', 'La Via Verso l\'Ascensione 24', 'Sblocca altre sfide nella Via dell\'Ascensione.', 38134),
(14351, 'itIT', 'Sconfiggi 39 boss nella Via dell\'Ascensione.', 'La Via Verso l\'Ascensione 39', 'Sblocca altre sfide nella Via dell\'Ascensione.', 38134),
(14502, 'itIT', 'Supera le prime otto Prove della Lealtà.', 'Leale alla lealtà', '', 38134),
(14633, 'itIT', 'Sblocca il Grado III della rete di collegamento del tuo Santuario.', 'Navigatore esperto', '', 38134),
(14636, 'itIT', 'Sblocca il Grado III del Tavolo del Comando delle Avventure del tuo Santuario.', 'Avventuriero capo', '', 38134),
(14637, 'itIT', 'Sblocca il Grado V della funzione speciale del tuo Santuario.', 'Una Congrega speciale', '', 38134),
(14638, 'itIT', 'Sblocca tutti i luoghi collegati al tuo Conduttore d\'Animum.', 'L\'Animum non può fermarsi', '', 38134),
(14639, 'itIT', 'Usa il tuo Conduttore d\'Animum 50 volte.', 'Dipendenza da Conduttore', '', 38134),
(14670, 'itIT', 'Incuba uno spirito di ogni tipo nel Vivaio della Regina.', 'Questo è lo spirito', '', 38134),
(14675, 'itIT', 'Incuba uno spirito superiore di ogni tipo nel Vivaio della Regina.', 'La superiorità dello spirito', '', 38134),
(14676, 'itIT', 'Incuba uno spirito divino di ogni tipo nel Vivaio della Regina.', 'Uno spirito divino', '', 38134),
(14677, 'itIT', 'Completa ognuna delle missioni d\'osservazione dello spirito di Falir nel Vivaio della Regina.', 'Osservazioni spirituali', '', 38134),
(14678, 'itIT', 'Sblocca i seguenti favori per la tua Corte delle Braci.', 'Favori della Corte', '', 38134),
(14679, 'itIT', 'Sblocca i seguenti potenziamenti per la tua Corte delle Braci.', 'Festa a palazzo', '', 38134),
(14680, 'itIT', 'Sblocca i seguenti servizi per la tua Corte delle Braci.', 'Ce n\'è per tutti', '', 38134),
(14681, 'itIT', 'Addestra i tuoi Dragatori della Corte delle Braci nelle seguenti arti da maggiordomo.', 'Accademia dei Dragatori', '', 38134),
(14682, 'itIT', 'Compi le imprese della Corte delle Braci elencate qui sotto.', 'L\'Alfiere della Festa', 'Ricompensa: titolo \"l\'Alfiere della Festa\"', 38134),
(14683, 'itIT', 'Sblocca le seguenti opzioni cosmetiche per i tuoi Dragatori della Corte delle Braci.', 'Stile da Dragatore', '', 38134),
(14684, 'itIT', 'Completa tutte le missioni delle Cuciture Abominevoli elencate qui sotto.', 'Vite abominevoli', '', 38134),
(14723, 'itIT', 'Ricevi i seguenti ospiti presso la tua Corte delle Braci.', 'Un caldo benvenuto', '', 38134),
(14724, 'itIT', 'Aiuta i seguenti ospiti a raggiungere l\'umore Entusiasta alla tua Corte delle Braci.', 'Piacione', '', 38134),
(14725, 'itIT', 'Tieni una Corte delle Braci con quattro ospiti Entusiasti.', 'Pochi ma buoni', '', 38134),
(14726, 'itIT', 'Tieni delle Corti delle Braci con i seguenti attributi ai massimi livelli.', 'Non ci si annoia mai', '', 38134),
(14727, 'itIT', 'Completa 10 eventi durante una singola Corte delle Braci.', ' Maestro delle cerimonie', '', 38134),
(14748, 'itIT', 'Crea 25 di questi accessori di stile con le Cuciture Abominevoli.', 'Rifare il guardaroba', '', 38134),
(14749, 'itIT', 'Aiuta Squartacus a trovare i seguenti cappelli da indossare alla Corte delle Braci.', 'Il grande giorno di Squartacus', '', 38134),
(14751, 'itIT', 'Costruisci ognuno dei seguenti costrutti con le Cuciture Abominevoli.', 'La banda è di nuovo riunita', 'Ricompensa: cavalcatura \"Tauralus Prescelto\"', 38134),
(14752, 'itIT', 'Compi le imprese delle Cuciture Abominevoli elencate qui sotto.', 'Cose da fare da morti', 'Ricompensa: titolo \" Abominevole\" e Ricompensa: cavalcatura \"Tauralus Prescelto Corazzato\"', 38134),
(14753, 'itIT', 'Contribuisci con 100 Nastri Vincolati dall\'Animum consegnati all\'Evocatore Gerard a evocare Visectus, Spettro della Guerra.', 'Guerre a nastro', '', 38134),
(14764, 'itIT', 'Con l\'aiuto di Accordino, ottieni il Portabene Grandioso.', 'Il Portabene Grandioso', '', 38134),
(14775, 'itIT', 'Diventa Osannato da Marasmio.', 'Che marasma', 'Ricompensa: titolo \"Amiceto / Amiceta\"', 38134),
(14777, 'itIT', 'Potenzia tutte le funzioni del tuo Santuario della Congrega.', 'Esperto di rigenerazione', '', 38134),
(14780, 'itIT', 'Completa tutte le missioni di meditazione di Ohm nel Vivaio della Regina e diventa tutt\'uno con il tuo io interiore.', 'Maestro della meditazione', '', 38134),
(14789, 'itIT', 'Completa la serie di missioni di Lia per riportare tutti gli spiriti animali al Vivaio della Regina.', 'Tutti gli spiriti, grandi e piccoli', '', 38134),
(14833, 'itIT', 'Crea ognuno di questi accessori di stile con le Cuciture Abominevoli.', 'Abomini alla moda', '', 38134),
(14839, 'itIT', 'Fai salire al livello 60 tre Vincoli dell\'Anima nelle Avventure.', 'Vincolati all\'avventura', '', 38134),
(14840, 'itIT', 'Fai salire al livello 20 un Avventuriero.', 'Avventure: imparare le regole', '', 38134),
(14841, 'itIT', 'Fai salire al livello 40 un Avventuriero.', 'Avventure: ora si ragiona', '', 38134),
(14842, 'itIT', 'Fai salire al livello 60 un Avventuriero.', 'Avventure: forza e resilienza', '', 38134),
(14843, 'itIT', 'Ottieni tutti i 12 avventurieri della tua Congrega.', 'Avventure: armonia dello Scopo', '', 38134),
(14844, 'itIT', 'Completa le seguenti avventure della Fauce.', 'Avventure: nella breccia', '', 38134),
(14845, 'itIT', 'Completa un\'avventura.', 'Avventure: un passo nella direzione giusta', '', 38134),
(14846, 'itIT', 'Completa 10 Avventure.', 'Avventure: foglie nella foresta', '', 38134),
(14847, 'itIT', 'Completa 100 Avventure.', 'Avventure: protettori delle Terretetre', '', 38134),
(14851, 'itIT', 'Sconfiggi Kalisthene e Corinth il Codardo mentre utilizzi l\'Egida dello Spirito Forgiato.', 'Bastione della protezione', '', 38134),
(14852, 'itIT', 'Sconfiggi l\'Incubo Spezzacortecce e Alderyn e Myn\'ir nella Prova della Lealtà nei panni di Mikanikos.', 'L\'arte del gufare', '', 38134),
(14853, 'itIT', 'Sconfiggi Mortimer il Folle dopo aver subito gli effetti di Vene Ardenti, Congelato e Vomito Incontrollato.', 'Tutti i colori dello schiaffobaleno', '', 38134),
(14854, 'itIT', 'Supera una Prova della Lealtà usando tutti i pezzi dell\'equipaggiamento del Vincolo dell\'Anima.', 'Non importa cosa indossi', '', 38134),
(14856, 'itIT', 'Supera una Prova della Saggezza con cinque Talismani equipaggiati.', 'Talismani incantevoli', '', 38134),
(14857, 'itIT', 'Sconfiggi Echthra in una Prova della Saggezza dopo aver ucciso 20 ragni.', 'Minuscoli combattenti', '', 38134),
(14858, 'itIT', 'Sconfiggi Corinth il Codardo in una Prova della Saggezza dopo che ha consumato due Globi dell\'Animum.', 'Maledizione della sete', '', 38134),
(14859, 'itIT', 'Sconfiggi Athanos in una Prova della Saggezza sopravvivendo a cinque Sferzate di Potenza.', 'Fuoricampo dentro il campo', '', 38134),
(14860, 'itIT', 'Supera una Prova della Saggezza senza alcun equipaggiamento del Vincolo dell\'Anima.', 'Lo stretto necessario', '', 38134),
(14861, 'itIT', 'Sconfiggi Kalisthene e Athanos nella Prova della Saggezza usando Pelagos, Kleia e Mikanikos.', 'Imparare dai maestri', '', 38134),
(14862, 'itIT', 'Supera una Prova dell\'Umiltà usando ogni equipaggiamento del Vincolo dell\'Anima.', 'Importa come la indossi', '', 38134),
(14863, 'itIT', 'Sconfiggi Thran\'tiok nella Prova della Saggezza senza danneggiarla prima di distruggere tutti i filatteri.', 'Morte indegna', '', 38134),
(14864, 'itIT', 'Sconfiggi Azaruux in una Prova della Saggezza nei panni di Pelagos senza affrontare alcun ricordo.', 'Incubo personale', '', 38134),
(14865, 'itIT', 'Supera dieci Prove dell\'Umiltà con Pelagos, Kleia e Mikanikos.', 'Discepolo dell\'Umiltà', '', 38134),
(14866, 'itIT', 'Supera dieci Prove dell\'Umiltà senza alcun talismano o braciere attivo.', 'Maestro della Via', '', 38134),
(14887, 'itIT', 'Fai ciaociao ad Athanos dopo che lui lo fa a te.', 'Dritto verso la Luna', '', 38134),
(15023, 'itIT', 'Sblocca il Grado 1 di tutti e quattro i potenziamenti di una Congrega.', 'Possiamo ricostruire', 'Sblocca: ricompense in Animum aggiuntive', 38134),
(15024, 'itIT', 'Sblocca il Grado 2 di tutti e quattro i potenziamenti di una Congrega.', 'Non ce n\'è siccità', 'Sblocca: ricompense in Animum aggiuntive', 38134),
(15025, 'itIT', 'Sblocca il Grado 3 di tutti e quattro i potenziamenti di una Congrega.', 'Santuario superiore', 'Sblocca: ricompense in Animum aggiuntive', 38134);


DELETE FROM `hotfix_blob` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(13330255, 89547, 'itIT', 0xFB1E0200ECDA0200, 38134), -- ItemXItemEffect
(3865974254, 187116, 'itIT', 0xECDA020000000000, 38134), -- ModifiedReagentItem
(3205218938, 34395, 'itIT', 0x4C4F47494E5F504152454E54414C434F4E54524F4C004C276163636573736F20612071756573746F206163636F756E7420C3A82061747475616C6D656E7465206C696D697461746F2064616C20636F6E74726F6C6C6F20706172656E74616C652E2050756F692063616D6269617265206C6520696D706F7374617A696F6E692064616C6C612073636865726D6174612064692067657374696F6E65206F6E6C696E652064656C2074756F206163636F756E742E0002, 38134), -- GlobalStrings
(3205218938, 33881, 'itIT', 0x424E45545F4552524F525F3131004C276163636573736F20612071756573746F206163636F756E7420C3A82061747475616C6D656E7465206C696D697461746F2064616C20636F6E74726F6C6C6F20706172656E74616C652E2050756F692063616D6269617265206C6520696D706F7374617A696F6E692064616C6C612073636865726D6174612064692067657374696F6E65206F6E6C696E652064656C2074756F206163636F756E742E0002, 38134), -- GlobalStrings
(3205218938, 33838, 'itIT', 0x415554485F504152454E54414C5F434F4E54524F4C004C276163636573736F20612071756573746F206163636F756E7420C3A82061747475616C6D656E7465206C696D697461746F2064616C20636F6E74726F6C6C6F20706172656E74616C652E2050756F692063616D6269617265206C6520696D706F7374617A696F6E692064616C6C612073636865726D6174612064692067657374696F6E65206F6E6C696E652064656C2074756F206163636F756E742E0002, 38134), -- GlobalStrings
(1754233351, 4164, 'itIT', 0x69ED040011C2B8323FF3665F3F00004843000048430000000000000000000000000000000000000000000000000000803F0000803F0000A040, 38134), -- SpellMissile
(240389885, 5745, 'itIT', 0x005238383800000000020202020000000001000000080000000A0000000C00000000000000000000000000000000000000, 38134), -- UnitCondition
(3776013982, 322416, 'itIT', 0x004C27696E63616E7461746F726520666120656D6572676572652064656C6C65207370616363617475726520646920726F6363696120646120736F74746F2074757474692069206E656D69636920766963696E692C20696E666C696767656E646F202433323234313873312064616E6E6920666973696369206520736361676C69616E646F6C6920696E20617269612E0000, 38134), -- Spell
(3865974254, 174876, 'itIT', 0x1CAB020000000000, 38134), -- ModifiedReagentItem
(3776013982, 326180, 'itIT', 0x0024407370656C6C646573633332313837330D0A0000, 38134), -- Spell
(3776013982, 321832, 'itIT', 0x0024407370656C6C646573633331303430360D0A0000, 38134), -- Spell
(3776013982, 321828, 'itIT', 0x004C2745766F63616E65626269652067696F63612061206C616E6369617265206C612024407370656C6C6E616D6533323138323820636F6E74726F20756E206E656D69636F2C20696E666C696767656E646F202473312064616E6E69206461206E6174757261206520636F6E666F6E64656E646F6C6F207065722024642E204C27696E63616E746573696D6F207075C3B22065737365726520696E746572726F74746F2064616C206265727361676C696F2E2000436F6E6675736F2E00, 38134), -- Spell
(2640972154, 324, 'itIT', 0x4C6120436F7274652064656C6C6520427261636900440100006F00000000000000050000000001000000000000000500000002000000, 38134), -- GarrTalentTree
(2640972154, 321, 'itIT', 0x4661626272696361206465676C692041626F6D696E6900410100006F00000000000000050000000000000000000000000500000004000000, 38134), -- GarrTalentTree
(2640972154, 320, 'itIT', 0x4C61205669612064656C6C27417363656E73696F6E6500400100006F00000000000000050000A31400000000000000000500000001000000, 38134), -- GarrTalentTree
(2640972154, 319, 'itIT', 0x496C2056697661696F2064656C6C6120526567696E61003F0100006F00000000000000050000000000000000000000000500000003000000, 38134), -- GarrTalentTree
(4033975491, 441527, 'itIT', 0x00000000666646C000005040000000000000000000000000B7BC06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000000000000FA390200, 38134), -- SpellVisualKitModelAttach
(4033975491, 441526, 'itIT', 0x000000006666464000005040000000000000000000000000B6BC06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000000000000FA390200, 38134), -- SpellVisualKitModelAttach
(4033975491, 441525, 'itIT', 0x000000000000000000005040000000000000000000000000B5BC06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000000000000FA390200, 38134), -- SpellVisualKitModelAttach
(4033975491, 429002, 'itIT', 0x00000000666646C000003040000000000000000000000000CA8B06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF00000000000000000000000000000009210200, 38134), -- SpellVisualKitModelAttach
(4033975491, 429001, 'itIT', 0x000000006666464000003040000000000000000000000000C98B06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF00000000000000000000000000000009210200, 38134), -- SpellVisualKitModelAttach
(4033975491, 429000, 'itIT', 0x000000000000000000003040000000000000000000000000C88B06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF00000000000000000000000000000009210200, 38134), -- SpellVisualKitModelAttach
(1181150530, 381714, 'itIT', 0x02000000B7BC0600FA390200, 38134), -- SpellVisualKitEffect
(1181150530, 381713, 'itIT', 0x02000000B6BC0600FA390200, 38134), -- SpellVisualKitEffect
(1181150530, 381712, 'itIT', 0x02000000B5BC0600FA390200, 38134), -- SpellVisualKitEffect
(3425193231, 280125, 'itIT', 0x090000000A0000000000000000000000000000000000000003000000FA39020075A60100, 38134), -- SpellVisualEvent
(4146370265, 108149, 'itIT', 0x0000000000000000000000000000000000000000000000000000000000000000FF22000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SpellVisual
(3776013982, 354135, 'itIT', 0x000000, 38134), -- Spell
(2939349194, 723, 'itIT', 0x426F73732065737465726E692028536861646F776C616E64732900426F73732065737465726E6900030000002301000000008C4E0100AE08000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 722, 'itIT', 0x43617374656C6C6F206469204E617468726961202845726F696361290045726F6963610003020B0123000000D7008C4E0100F8080F00001E0000000000, 38134), -- GroupFinderActivity
(2939349194, 721, 'itIT', 0x43617374656C6C6F206469204E61746872696120284D697469636129004D69746963610003030B0123000000E6008C4E0100F808100000140000000000, 38134), -- GroupFinderActivity
(2939349194, 720, 'itIT', 0x43617374656C6C6F206469204E61746872696120284E6F726D616C6529004E6F726D616C650003010B0123000000C8008C4E0100F8080E00001E0000000000, 38134), -- GroupFinderActivity
(2939349194, 719, 'itIT', 0x54656174726F2064656C20446F6C6F7265202845726F696361290045726F6963610002010A016300000073008C4E0100F508020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 718, 'itIT', 0x54656174726F2064656C20446F6C6F726520284D697469636129004D69746963610002010A016300000073008C4E0100F508170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 717, 'itIT', 0x54656174726F2064656C20446F6C6F726520284D69746963612B29004D69746963612B0002010A01C300000073008C4E0100F508080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 716, 'itIT', 0x54656174726F2064656C20446F6C6F726520284E6F726D616C6529004E6F726D616C650002010A016300000000008C4E0100F508010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 715, 'itIT', 0x53636961204E6563726F74696361202845726F696361290045726F69636100020109016300000073008C4E0100EE08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 714, 'itIT', 0x53636961204E6563726F7469636120284D697469636129004D697469636100020109016300000073008C4E0100EE08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 713, 'itIT', 0x53636961204E6563726F7469636120284D69746963612B29004D69746963612B0002010901C300000073008C4E0100EE08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 712, 'itIT', 0x53636961204E6563726F7469636120284E6F726D616C6529004E6F726D616C6500020109016300000000008C4E0100EE08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 711, 'itIT', 0x4775676C69652064656C6C27417363656E73696F6E65202845726F696361290045726F69636100020108016300000073008C4E0100ED08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 710, 'itIT', 0x4775676C69652064656C6C27417363656E73696F6E6520284D697469636129004D697469636100020108016300000073008C4E0100ED08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 709, 'itIT', 0x4775676C69652064656C6C27417363656E73696F6E6520284D69746963612B29004D69746963612B0002010801C300000073008C4E0100ED08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 708, 'itIT', 0x4775676C69652064656C6C27417363656E73696F6E6520284E6F726D616C6529004E6F726D616C6500020108016300000000008C4E0100ED08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 707, 'itIT', 0x50726F666F6E646974C3A02053616E677569676E65202845726F696361290045726F69636100020107016300000073008C4E0100EC08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 706, 'itIT', 0x50726F666F6E646974C3A02053616E677569676E6520284D697469636129004D697469636100020107016300000073008C4E0100EC08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 705, 'itIT', 0x50726F666F6E646974C3A02053616E677569676E6520284D69746963612B29004D69746963612B0002010701C300000073008C4E0100EC08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 704, 'itIT', 0x50726F666F6E646974C3A02053616E677569676E6520284E6F726D616C6529004E6F726D616C6500020107016300000000008C4E0100EC08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 703, 'itIT', 0x4E6562626965206469205469726E612046616C63697320284D69746963612B29004D69746963612B0002010601C300000073008C4E0100F208080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 702, 'itIT', 0x4E6562626965206469205469726E612046616C63697320284D697469636129004D697469636100020106016300000073008C4E0100F208170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 701, 'itIT', 0x4E6562626965206469205469726E612046616C636973202845726F696361290045726F69636100020106016300000073008C4E0100F208020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 700, 'itIT', 0x4E6562626965206469205469726E612046616C63697320284E6F726D616C6529004E6F726D616C6500020106016300000000008C4E0100F208010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 699, 'itIT', 0x53616C652064656C6C6120526564656E7A696F6E6520284D69746963612B29004D69746963612B0002010501C300000073008C4E0100EF08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 698, 'itIT', 0x53616C652064656C6C6120526564656E7A696F6E6520284D697469636129004D697469636100020105016300000073008C4E0100EF08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 697, 'itIT', 0x53616C652064656C6C6120526564656E7A696F6E65202845726F696361290045726F69636100020105016300000073008C4E0100EF08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 696, 'itIT', 0x53616C652064656C6C6120526564656E7A696F6E6520284E6F726D616C6529004E6F726D616C6500020105016300000000008C4E0100EF08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 695, 'itIT', 0x4C27416C64696CC3A020284D69746963612B29004D69746963612B0002010401C300000073008C4E0100F308080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 694, 'itIT', 0x4C27416C64696CC3A020284D697469636129004D697469636100020104016300000073008C4E0100F308170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 693, 'itIT', 0x4C27416C64696CC3A0202845726F696361290045726F69636100020104016300000073008C4E0100F308020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 692, 'itIT', 0x4C27416C64696CC3A020284E6F726D616C6529004E6F726D616C6500020104016300000000008C4E0100F308010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 691, 'itIT', 0x506961676166756E6573746120284D69746963612B29004D69746963612B0002010301C300000073008C4E0100F108080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 690, 'itIT', 0x506961676166756E6573746120284D697469636129004D697469636100020103016300000073008C4E0100F108170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 689, 'itIT', 0x506961676166756E65737461202845726F696361290045726F69636100020103016300000073008C4E0100F108020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 688, 'itIT', 0x506961676166756E6573746120284E6F726D616C6529004E6F726D616C6500020103016300000000008C4E0100F108010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 657, 'itIT', 0x426F73732065737465726E692028426174746C6520666F7220417A65726F74682900426F73732065737465726E690003000000230100000000BF5300000000000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 498, 'itIT', 0x53706564697A696F6E652063617375616C653A20426174746C6520666F7220417A65726F7468202845726F696361290045726F6963610002028800620000003A00BF5300006A06020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 497, 'itIT', 0x53706564697A696F6E652063617375616C653A20426174746C6520666F7220417A65726F746820284E6F726D616C6529004E6F726D616C650002008800620000000000BF5300006A06010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 458, 'itIT', 0x426F73732065737465726E69206469204C6567696F6E00426F73732065737465726E690003000000230100000000BF530000C404000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 418, 'itIT', 0x53706564697A696F6E652063617375616C65206469204C6567696F6E202845726F696361290045726F6963610002026F00620000003200BF530000C404020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 417, 'itIT', 0x53706564697A696F6E652063617375616C65206469204C6567696F6E20284E6F726D616C6529004E6F726D616C650002006F00620000000000BF530000C404010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 398, 'itIT', 0x426F73732065737465726E6920646920447261656E6F7200426F73732065737465726E690003000000230100000000BF5300005C04000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 397, 'itIT', 0x426F73732065737465726E692064692050616E646172696100426F73732065737465726E690003000000230100000000BF5300006603000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 396, 'itIT', 0x53706564697A696F6E652063617375616C6520646920447261656E6F72202845726F696361290045726F6963610002006D00620000000000BF5300005C04020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 395, 'itIT', 0x53706564697A696F6E652063617375616C6520646920447261656E6F7220284E6F726D616C6529004E6F726D616C650002006D00620000000000BF5300005C04010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 364, 'itIT', 0x53706564697A696F6E652063617375616C652064692050616E6461726961202845726F696361290045726F6963610002005400620000000000BF5300006603020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 363, 'itIT', 0x53706564697A696F6E652063617375616C652064692050616E646172696120284E6F726D616C6529004E6F726D616C650002005400620000000000BF5300006603010000050100000000, 38134), -- GroupFinderActivity
(3776013982, 45525, 'itIT', 0x0041756D656E7461206C27496E74656C6C6574746F20646920756E20616C6C6561746F2064692024733125207065722024642E00496E74656C6C6574746F2061756D656E7461746F20646920247331252E00, 38134), -- Spell
(3776013982, 327332, 'itIT', 0x004C27696E63616E7461746F726520696E666F6E6465206C27416E696D756D206E656C6C2761726D612E20492073756363657373697669203520617474616363686920656E74726F20246420696E666C6967676F6E6F2064616E6E6920646120617263616E6F2061676769756E746976692E002433323733333173312064616E6E6920646120617263616E6F2061676769756E7469766920696E666C6974746920636F6E20676C692061747461636368692064656C6C2761726D612E00, 38134), -- Spell
(3776013982, 340271, 'itIT', 0x0052696475636520692064616E6E6920737562697469206461676C6920616C6C6561746920656E74726F203135206D2064656C20243334303237337331252E0044616E6E6920737562697469206461676C6920616C6C6561746920656E74726F203135206D207269646F7474692064656C20243334303237337331252E00, 38134), -- Spell
(3776013982, 336061, 'itIT', 0x000000, 38134), -- Spell
(603412935, 28771, 'itIT', 0xE4B8ADE59BBDE9AB98E5B182E4BABAE4BA8BE58F98E58AA80004, 38134), -- ChatProfanity
(603412935, 28770, 'itIT', 0xE4B8ADE59BBDE9AB98E5B182E69D83E58A9BE69697E4BA890004, 38134), -- ChatProfanity
(603412935, 28769, 'itIT', 0xE4B8ADE59BBDE5AE98E59CBAE68385E69D80E6A1880004, 38134), -- ChatProfanity
(603412935, 28768, 'itIT', 0xE69CB1E6BAB6E59FBA0004, 38134), -- ChatProfanity
(603412935, 28767, 'itIT', 0xE69CB1E6BAB6E9B8A10004, 38134), -- ChatProfanity
(603412935, 28766, 'itIT', 0xE5AFACE8A1A3E5B89D0004, 38134), -- ChatProfanity
(603412935, 28765, 'itIT', 0xE7A588E7BFA00004, 38134), -- ChatProfanity
(603412935, 28764, 'itIT', 0xE5B08FE5ADA6E58D9AE5A3ABE7BFA00004, 38134), -- ChatProfanity
(603412935, 28763, 'itIT', 0xE694BFE59D9BE9BB91E9A9AC0004, 38134), -- ChatProfanity
(603412935, 28762, 'itIT', 0xE694BFE6B2BBE6B581E6B0930004, 38134), -- ChatProfanity
(603412935, 28761, 'itIT', 0xE788B1E59BBDE88085E5908CE79B9FE7BD91E7AB990004, 38134), -- ChatProfanity
(603412935, 28760, 'itIT', 0xE6AF9BE79A87E5B89D0004, 38134), -- ChatProfanity
(603412935, 28759, 'itIT', 0xE999A4E58C85E5AD900004, 38134), -- ChatProfanity
(603412935, 28758, 'itIT', 0xE89BA4E79A870004, 38134), -- ChatProfanity
(603412935, 28757, 'itIT', 0xE89BA4E89F86E698AFE8B0810004, 38134), -- ChatProfanity
(603412935, 28756, 'itIT', 0xE89BA4E89F86E698AFE8AAB00004, 38134), -- ChatProfanity
(603412935, 28755, 'itIT', 0xE680BBE4B9A6E8AEB0E79785E58DB10004, 38134), -- ChatProfanity
(603412935, 28754, 'itIT', 0xE88081E6B19FE79785E58DB10004, 38134), -- ChatProfanity
(603412935, 28753, 'itIT', 0xE6B19FE9A9BEE5B4A90004, 38134), -- ChatProfanity
(603412935, 28752, 'itIT', 0xE6B19FE5898DE79A870004, 38134), -- ChatProfanity
(603412935, 28751, 'itIT', 0xE6B19FE4B88AE79A870004, 38134), -- ChatProfanity
(603412935, 28750, 'itIT', 0xE99995E8A5BFE5B8A6E5A4B4E5A4A7E593A50004, 38134), -- ChatProfanity
(603412935, 28749, 'itIT', 0xE68A97E9BAA6E9838E0004, 38134), -- ChatProfanity
(603412935, 28748, 'itIT', 0xE6A0BCE890A8E5B094E78E8B0004, 38134), -- ChatProfanity
(603412935, 28747, 'itIT', 0xE890A8E6A0BCE5B094E78E8B0004, 38134), -- ChatProfanity
(3776013982, 337334, 'itIT', 0x0050616C6D6F2064656C6C6120546967726520686120756E6120706F727461746120646920247B246D312B357D206D20652C207175616E646F207669656E65206C616E636961746F2C20746920666120736361747461726520697374616E74616E65616D656E746520766572736F20696C206265727361676C696F2E0D0A0D0A50616C6D6F2064656C6C61205469677265206170706C69636120756E206566666574746F206368652061756D656E7461206C612070726F626162696C6974C3A0206469206372697469636F20636F6E74726F207175656C206265727361676C696F2064656C20243334343032316D3125207065722024333434303231642E204C276566666574746F206E6F6E207075C3B2206170706C696361727369207069C3B920646920756E6120766F6C7461206F676E6920243333373334316420706572206265727361676C696F2E0000, 38134), -- Spell
(813076512, 80114, 'itIT', 0x2401000057640500, 38134), -- SpellLabel
(813076512, 80113, 'itIT', 0x1A00000057640500, 38134), -- SpellLabel
(813076512, 80112, 'itIT', 0x1000000057640500, 38134), -- SpellLabel
(3776013982, 353367, 'itIT', 0x0052696475636520692064616E6E69207375626974692064656C20247331252E0000, 38134), -- Spell
(3776013982, 319278, 'itIT', 0x0041756D656E7461206C612054656D7072612064656C20247331252E0D0A243F733331363731345B52696475636520692064616E6E69207375626974692064656C20247333252E5D5B5D0000, 38134), -- Spell
(3776013982, 316714, 'itIT', 0x477261646F20320041756D656E7461206C612054656D7072612064656C20247331252E0D0A52696475636520692064616E6E69207375626974692064656C20247B2461627328247332297D252E0000, 38134), -- Spell
(3776013982, 300346, 'itIT', 0x005065726D65747465206469206C616E63696172652046756F636F204C756E6172652C2050616369666963617A696F6E652C2052696D6F7A696F6E6520436F7272757A696F6E6520652052696E61736369746120696E20466F726D612064274F72736F2E0D0A0D0A52696475636520692064616E6E69207375626974692064656C20247332252E0000, 38134), -- Spell
(3776013982, 245013, 'itIT', 0x0052696475636520692064616E6E69207375626974692064656C202473322520652061756D656E7461206C2761726D61747572612064656C20247331252E0000, 38134), -- Spell
(3776013982, 48263, 'itIT', 0x0041756D656E7461206C612054656D7072612064656C20247331252E0D0A243F733331363731345B52696475636520692064616E6E69207375626974692064656C20247333252E5D5B5D0000, 38134), -- Spell
(3776013982, 71, 'itIT', 0x004C61206661746963612064656C6C61206261747461676C69612072696475636520692064616E6E69207375626974692064656C20247333252C2061756D656E7461206C612054656D7072612064656C20247332252065206C2761726D61747572612064656C20247331252064656C6C612074756120466F727A612E0000, 38134), -- Spell
(3776013982, 337541, 'itIT', 0x004D6172636869617475726120417264656E746520637572612064656C2024733125206465692064616E6E6920696E697A69616C6920696E666C6974746920696E2024333337353433642065206F676E69206E656D69636F20636F6C7069746F20646120536967696C6C6F2064656C6C61204669616D6D612061756D656E746120692064616E6E6920697374616E74616E656920696E666C697474692064616C6C612073756363657373697661204D6172636869617475726120417264656E74652064656C20243333373534327331252E20536920616363756D756C612066696E6F206120243333373534327520766F6C74652E0000, 38134), -- Spell
(3776013982, 281242, 'itIT', 0x00492064616E6E6920696E666C69747469206D6172636869616E6F20696C206265727361676C696F2C2061756D656E74616E646F6E6520692064616E6E69206D6167696369207375626974692064656C2024313439307331252E0000, 38134), -- Spell
(3776013982, 255260, 'itIT', 0x00492064616E6E6920696E666C69747469206D6172636869616E6F20696C206265727361676C696F2C2061756D656E74616E646F6E6520692064616E6E69206D6167696369207375626974692064656C2024313439307331252E0000, 38134), -- Spell
(603412935, 28746, 'itIT', 0x5C62725C733F615C733F705C733F655C733F5C620000, 38134), -- ChatProfanity
(603412935, 28745, 'itIT', 0x5C62725C733F655C733F745C733F615C733F725C733F64285C733F737C5C733F655C733F64293F5C620000, 38134), -- ChatProfanity
(4033975491, 436804, 'itIT', 0x00000000000000000000000000000000000000000000000044AA06000A59FF0E030000000000000000000000000000000000000000000000000000803F00000000FFFFFFFFFFFF00000000000000CDCC4C3DCDCC4C3DCC0B0200, 38134), -- SpellVisualKitModelAttach
(3386943305, 171057, 'itIT', 0x07787800000000000000004A00B20200000000081000000000000400000000000000000001000040000000000000000000E05A0200, 38134), -- CreatureDifficulty
(3386943305, 170644, 'itIT', 0x07787800000000000000001000B2020000000008100000000000000000000000000000000100000000000000000000000068590200, 38134), -- CreatureDifficulty
(3899321669, 4791, 'itIT', 0xB71200000101180B0300, 38134), -- SpellAuraVisibility
(3899321669, 4790, 'itIT', 0xB61200000001180B0300, 38134), -- SpellAuraVisibility
(4033975491, 440494, 'itIT', 0x0000000000000000CDCC4C3E000000000000000000000000AEB80600D058FF00000000000000000000000000000000000000000000000000003333333F0000000000009E009F0000000000000000000000000000000051160200, 38134), -- SpellVisualKitModelAttach
(4033975491, 440493, 'itIT', 0x0000000000000000CDCCCC3D000000000000000000000000ADB806007F87FF00000000000000000000000000000000000000000000000000003333333F0000000000009E009F0000000000000000000000000000000051160200, 38134), -- SpellVisualKitModelAttach
(4033975491, 417672, 'itIT', 0x000000000000000000000000000000000000000000000000885F06000F5AFF00000000000000000000000000000000000000000000000000000000C03F00000000FFFFFFFFFFFF00000800000000000000000000000021030200, 38134), -- SpellVisualKitModelAttach
(4033975491, 417626, 'itIT', 0x0000000000000000000000000000000000000000000000005A5F0600E64BFF0000000000000000000000000000000000000000000000000000333373400000000000009E009F0000000000000000000000000000000009030200, 38134), -- SpellVisualKitModelAttach
(1181150530, 380178, 'itIT', 0x02000000AEB8060051160200, 38134), -- SpellVisualKitEffect
(1181150530, 380177, 'itIT', 0x02000000ADB8060051160200, 38134), -- SpellVisualKitEffect
(3776013982, 321136, 'itIT', 0x004F676E692024733120246C6C616E63696F3A6C616E63693B20646920536375646F2064656C2056697274756F736F2C206C612073756363657373697661205061726F6C6120646920476C6F72696120C3A820707269766120646920636F73746F2E0000, 38134), -- Spell
(3776013982, 341220, 'itIT', 0x000024407370656C6C6465736333343132313200, 38134), -- Spell
(3865974254, 183187, 'itIT', 0x93CB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183165, 'itIT', 0x7DCB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183141, 'itIT', 0x65CB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183136, 'itIT', 0x60CB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183135, 'itIT', 0x5FCB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183131, 'itIT', 0x5BCB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183122, 'itIT', 0x52CB020000000000, 38134), -- ModifiedReagentItem
(3776013982, 352816, 'itIT', 0x000000, 38134), -- Spell
(600565378, 300040, 'itIT', 0xA06D01000000803F0000803F0074BA0200, 38134), -- CreatureXDisplayInfo
(813076512, 79920, 'itIT', 0x9703000075A80400, 38134), -- SpellLabel
(13330255, 73366, 'itIT', 0x081D0200F3D60200, 38134), -- ItemXItemEffect
(3865974254, 186099, 'itIT', 0xF3D6020000000000, 38134), -- ModifiedReagentItem
(600565378, 299890, 'itIT', 0x4A6400000000803F0000803F001CBA0200, 38134), -- CreatureXDisplayInfo
(600565378, 299885, 'itIT', 0x0A6F01000000803F0000803F0017BA0200, 38134), -- CreatureXDisplayInfo
(3865974254, 172899, 'itIT', 0x63A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172898, 'itIT', 0x62A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172897, 'itIT', 0x61A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172896, 'itIT', 0x60A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172895, 'itIT', 0x5FA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172894, 'itIT', 0x5EA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172893, 'itIT', 0x5DA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172892, 'itIT', 0x5CA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172891, 'itIT', 0x5BA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172890, 'itIT', 0x5AA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171099, 'itIT', 0x5B9C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171098, 'itIT', 0x5A9C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171097, 'itIT', 0x599C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171096, 'itIT', 0x589C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171095, 'itIT', 0x579C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171094, 'itIT', 0x569C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171093, 'itIT', 0x559C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171092, 'itIT', 0x549C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171091, 'itIT', 0x539C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171090, 'itIT', 0x529C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 168316, 'itIT', 0x7C91020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164959, 'itIT', 0x5F84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164958, 'itIT', 0x5E84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164957, 'itIT', 0x5D84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164956, 'itIT', 0x5C84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164955, 'itIT', 0x5B84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164954, 'itIT', 0x5A84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164953, 'itIT', 0x5984020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164952, 'itIT', 0x5884020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164951, 'itIT', 0x5784020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164950, 'itIT', 0x5684020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164587, 'itIT', 0xEB82020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164586, 'itIT', 0xEA82020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164585, 'itIT', 0xE982020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164584, 'itIT', 0xE882020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164583, 'itIT', 0xE782020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164582, 'itIT', 0xE682020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164581, 'itIT', 0xE582020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164580, 'itIT', 0xE482020000000000, 38134), -- ModifiedReagentItem
(3865974254, 159570, 'itIT', 0x526F020000000000, 38134), -- ModifiedReagentItem
(3865974254, 155622, 'itIT', 0xE65F020000000000, 38134), -- ModifiedReagentItem
(3205218938, 43871, 'itIT', 0x43555252454E43595F534541534F4E5F544F54414C5F4D4158494D554D004C696D6974652073746167696F6E616C653A20257325732F25730001, 38134), -- GlobalStrings
(3776013982, 324919, 'itIT', 0x0024407370656C6C646573633332323834310000, 38134), -- Spell
(3776013982, 322841, 'itIT', 0x0041756D656E746120692064616E6E6920696E666C6974746920646120243F613231323631325B56696C73636174746F5D3F613231323631335B417373616C746F20496E6665726E616C655D5B5D2064656C20247331252E0044616E6E6920696E666C6974746920646120243F613231323631325B56696C73636174746F5D3F613231323631335B417373616C746F20496E6665726E616C655D5B5D2061756D656E746174692064656C20247331252E00, 38134), -- Spell
(3776013982, 294588, 'itIT', 0x0041756D656E7461206C612070726F626162696C6974C3A0206469206372697469636F2064656C20247B2473312A2432393435373873317D252E0000, 38134), -- Spell
(3776013982, 294587, 'itIT', 0x0041756D656E7461206C612070726F626162696C6974C3A0206469206372697469636F2064656C20247B2473312A2432393435373873317D252E0000, 38134), -- Spell
(3865974254, 180318, 'itIT', 0x5EC0020000000000, 38134), -- ModifiedReagentItem
(3865974254, 180317, 'itIT', 0x5DC0020000000000, 38134), -- ModifiedReagentItem
(3865974254, 176406, 'itIT', 0x16B1020000000000, 38134), -- ModifiedReagentItem
(3865974254, 168564, 'itIT', 0x7492020000000000, 38134), -- ModifiedReagentItem
(3776013982, 352497, 'itIT', 0x000000, 38134), -- Spell
(3776013982, 327193, 'itIT', 0x00417A7A65726120696C2074656D706F20646920726563757065726F20646920536375646F2064656C2056656E64696361746F72652E2049207375636365737369766920246E2053637564692064656C2056656E64696361746F7265206E6F6E2068616E6E6F2074656D706F20646920726563757065726F206520696E666C6967676F6E6F20696C20247332252064692064616E6E692061676769756E746976692E0049207375636365737369766920246E2053637564692064656C2056656E64696361746F7265206E6F6E2068616E6E6F2074656D706F20646920726563757065726F206520696E666C6967676F6E6F20696C20247732252064692064616E6E692061676769756E746976692E00, 38134), -- Spell
(3776013982, 321995, 'itIT', 0x005366727574746120696C20676869616363696F206368652073636F727265206E656C6C652076656E652C207269647563656E646F20696C20636F73746F20696E20706F74656E7A612072756E6963612064656C6C65206162696C6974C3A02064656C2024733125207065722024642E204E6F6E2061747469766120696C2074656D706F20646920726563757065726F20676C6F62616C652E00436F73746F20696E20706F74656E7A612072756E6963612064656C6C65206162696C6974C3A0207269646F74746F2064656C20247331252E00, 38134), -- Spell
(3776013982, 248518, 'itIT', 0x54616C656E746F2050765000496C207375636365737369766F20696E63616E746573696D6F2064276174746163636F206C616E636961746F2073756C206265727361676C696F2066612073C3AC2063686520747574746920676C6920696E63616E746573696D692064276174746163636F2070657220692073756363657373697669202473312073207369616E6F207265696E646972697A7A6174692073756C2074756F2066616D69676C696F2E0D0A0D0A496C2066616D69676C696F20646576276573736572652061206D656E6F20646920243234383531396131206D2064692064697374616E7A612064616C206265727361676C696F20616666696E6368C3A920676C6920696E63616E746573696D6920706F7373616E6F20657373657265207265696E646972697A7A6174692E0000, 38134), -- Spell
(3776013982, 243435, 'itIT', 0x0054692072656E6465207069C3B920726573697374656E74652C2061756D656E74616E646F206C612073616C7574652061747475616C652065206D617373696D612064656C20247331252065207269647563656E646F20692064616E6E69207375626974692064656C2024733225207065722024642E0053616C757465206D617373696D612061756D656E746174612064656C20247731252E0D0A44616E6E6920737562697469207269646F7474692064656C20247732252E243F2477343E315B0D0A2477342064616E6E6920737562697469206173736F72626974692E5D5B5D00, 38134), -- Spell
(3776013982, 235219, 'itIT', 0x00417A7A65726120692074656D706920646920726563757065726F206469204573706C6F73696F6E652047656C6964612C20436F6E6F2064692046726564646F2C20426172726965726120646920476869616363696F206520426C6F63636F20646920476869616363696F2E0000, 38134), -- Spell
(3776013982, 209584, 'itIT', 0x54616C656E746F2050765000466F726E6973636520696D6D756E6974C3A02061676C6920656666657474692064692073696C656E7A69616D656E746F206520696E74657272757A696F6E65207065722024642E00496D6D756E65206120656666657474692064692073696C656E7A69616D656E746F206520696E74657272757A696F6E652E00, 38134), -- Spell
(3776013982, 202335, 'itIT', 0x54616C656E746F205076500041756D656E746120692064616E6E6920696E666C697474692064616C207375636365737369766F204C616E63696F2064656C20426172696C652064656C2024733125206520676C69207065726D657474652064692073746F72646972652074757474692069206265727361676C6920636F6C70697469207065722024323032333436642E004C616E63696F2064656C20426172696C6520696E666C6967676520696C20247331252064692064616E6E692061676769756E7469766920652073746F7264697363652074757474692069206265727361676C6920636F6C70697469207065722024323032333436642E00, 38134), -- Spell
(3776013982, 34477, 'itIT', 0x005265696E646972697A7A61207475747461206C61206D696E61636369612067656E65726174612073756C206265727361676C696F206D656D62726F2064656C2067727570706F206F2064656C6C27696E63757273696F6E652070657220243335303739642C206120696E697A696172652064616C2070726F7373696D6F206174746163636F206C616E636961746F20656E74726F2024642E004D696E6163636961207265696E646972697A7A6174612064616C20436163636961746F72652E00, 38134), -- Spell
(3359787322, 19830, 'itIT', 0x764D0000, 38134), -- WorldState
(3359787322, 19710, 'itIT', 0xFE4C0000, 38134), -- WorldState
(3359787322, 19709, 'itIT', 0xFD4C0000, 38134), -- WorldState
(3359787322, 19384, 'itIT', 0xB84B0000, 38134), -- WorldState
(368401261, 5214, 'itIT', 0x5B8800000000000000000000000000000000000000000000, 38134), -- CombatCondition
(368401261, 4771, 'itIT', 0x848400000000000000000000000000000000000000000000, 38134), -- CombatCondition
(3776013982, 163708, 'itIT', 0x0041756D656E746120692064616E6E69206D616769636920696E666C697474692064656C203230252E0D0A0D0A476C69204172616B6B6F612053657468656B6B20706F73736F6E6F206C616E6369617265204669616D6D612056696E636F6C616D616769652E0044616E6E69206D616769636920696E666C697474692061756D656E746174692064656C203230252E0D0A0D0A476C69204172616B6B6F612053657468656B6B20706F73736F6E6F206C616E6369617265204669616D6D612056696E636F6C616D616769652E00, 38134), -- Spell
(3776013982, 352329, 'itIT', 0x000000, 38134), -- Spell
(3865974254, 52489, 'itIT', 0x09CD000000000000, 38134), -- ModifiedReagentItem
(3037505077, 52489, 'itIT', 0x0100, 38134), -- TradeSkillItem
(3776013982, 220358, 'itIT', 0x0024407370656C6C646573633130313534360000, 38134), -- Spell
(3776013982, 340433, 'itIT', 0x004C27416E696D756D2052616666696E61746F2073636F72726520696E2074652C2061756D656E74616E646F20692064616E6E6920696E666C697474692065206C65206375726520666F726E6974652064656C2024733125207065722024642E0044616E6E6920696E666C697474692061756D656E746174692064656C20247331252E0D0A4375726520666F726E6974652061756D656E746174652064656C20247332252E00, 38134), -- Spell
(3776013982, 335161, 'itIT', 0x004C27416E696D756D20726163636F6C746F20646169204D6173746F646F6E7469206D616C66756E7A696F6E616E74692061756D656E7461206C612076656C6F636974C3A0206469206D6F76696D656E746F2064656C2024733125206520666120657275747461726520696C20706572736F6E616767696F206F676E69202474332073207065722024642C20696E666C696767656E646F202433343434323173312064616E6E6920646120617263616E6F206169206E656D69636920766963696E69206520666F726E656E646F2024333434343232733120637572652061676C6920616C6C6561746920766963696E692E0056656C6F636974C3A0206469206D6F76696D656E746F2061756D656E746174612064656C20247331252E202433343434323173312064616E6E6920646120617263616E6F20696E666C69747469206169206E656D69636920766963696E69206520616C6C6561746920766963696E692063757261746920646920243334343432327331206F676E692024743320732E00, 38134), -- Spell
(3205218938, 43287, 'itIT', 0x4741525249534F4E5F464F4C4C4F5745525F4F4E5F4D495353494F4E5F434F4D504C45544500496E206D697373696F6E65202D20436F6D706C65746174610001, 38134), -- GlobalStrings
(3205218938, 43286, 'itIT', 0x4741525249534F4E5F464F4C4C4F5745525F4D495353494F4E5F434F4D504C4554454400436F6D706C65746174610001, 38134), -- GlobalStrings
(3205218938, 43283, 'itIT', 0x434F56454E414E545F464F4C4C4F5745525F4D495353494F4E5F434F4D504C45544500496E20417676656E74757261202D20436F6D706C65746174610001, 38134), -- GlobalStrings
(261693969, 59853, 'itIT', 0xFFFFFFFFFFFFFFFF53746F7269652064692074C3A83A20536962696C6C6120506572647574610000CDE900007599F633010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F88700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(261693969, 59852, 'itIT', 0xFFFFFFFFFFFFFFFF53746F7269652064692074C3A83A2047756262696E7320652054756262696E730000CCE900007499F533010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F78700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(261693969, 59850, 'itIT', 0xFFFFFFFFFFFFFFFF53746F7269652064692074C3A83A2056756C63610000CAE900007299F433010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F78700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(261693969, 59848, 'itIT', 0xFFFFFFFFFFFFFFFF53746F7269652064692074C3A83A2054656F7461720000C8E900007199F333010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F78700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(3776013982, 320740, 'itIT', 0x000000, 38134), -- Spell
(3776013982, 350249, 'itIT', 0x00446973746F72636520696C20666C7573736F2074656D706F72616C652C2061756D656E74616E646F206C612063656C65726974C3A02064656C2024733125206120736520737465737369206520616C6C652070726F7072696520496D6D6167696E692053706563756C617269207065722024313130393039642E0043656C65726974C3A02061756D656E746174612064656C20247731252E20243F2457343E305B56656C6F636974C3A02064656C2074656D706F2061756D656E746174612064656C20247734252E5D5B5D00, 38134), -- Spell
(3776013982, 320914, 'itIT', 0x00416C746572617A696F6E652054656D706F72616C6520666F726E6973636520756E6120446973746F7273696F6E652054656D706F72616C652061676769756E74697661206120736520737465737369206520616C6C652070726F7072696520496D6D6167696E692053706563756C61726920636F6E20756E276566666963616369612064656C20247331252E204E6F6E207375626973636520676C69206566666574746920646920537069617A7A616D656E746F2054656D706F72616C65206F20616C74726920656666657474692073696D696C692E00446973746F7273696F6E652054656D706F72616C652061676769756E7469766120666F726E697461206120736520737465737369206520616C6C652070726F7072696520496D6D6167696E692053706563756C61726920636F6E20756E276566666963616369612064656C20247331252E204E6F6E207375626973636520676C69206566666574746920646920537069617A7A616D656E746F2054656D706F72616C65206F20616C74726920656666657474692073696D696C692E00, 38134), -- Spell
(3893700160, 169, 'itIT', 0x0F000000E2000000D20000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 168, 'itIT', 0x0E000000E2000000CF0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 167, 'itIT', 0x0D000000DF000000CF0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 166, 'itIT', 0x0C000000DF000000CF0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 165, 'itIT', 0x0B000000DC000000CB0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 164, 'itIT', 0x0A000000DC000000CB0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 163, 'itIT', 0x09000000D8000000C80000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 162, 'itIT', 0x08000000D8000000C80000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 161, 'itIT', 0x07000000D5000000C80000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 160, 'itIT', 0x06000000D2000000C50000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 159, 'itIT', 0x05000000D2000000C20000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 158, 'itIT', 0x04000000CF000000C20000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 157, 'itIT', 0x03000000CB000000BE0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 156, 'itIT', 0x02000000C8000000BB0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 155, 'itIT', 0x0100000000000000B70000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3776013982, 351967, 'itIT', 0x000000, 38134), -- Spell
(3776013982, 340882, 'itIT', 0x005269636869616D612047617373696E6F2C20696E206361736F20666F737365206C6F6E74616E6F206F206D6F72746F2E0047617373696E6F207269636869616D61746F2C20696E206361736F20666F737365206C6F6E74616E6F206F206D6F72746F2E00, 38134), -- Spell
(2340571112, 755, 'itIT', 0xBD000000D51C0000D0040000060000008F1B00000000000000000000, 38134), -- ItemBonusListGroupEntry
(2998606315, 212, 'itIT', 0x0000000005000000803A09000000000000000000, 38134), -- ScheduledInterval
(3359787322, 20659, 'itIT', 0xB3500000, 38134); -- WorldState

INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(4021368146, 4553, 'itIT', 0x53746967696120436164757461000000000000000000D8020000424400000000000000000000000000000000000000, 38134), -- Vignette
(2202435563, 997132, 'itIT', 0x0C370F00240127010000F3170700, 38134), -- QuestPOIPoint
(2202435563, 997131, 'itIT', 0x0B370F00240128010000F2170700, 38134), -- QuestPOIPoint
(2921112328, 464883, 'itIT', 0xF31707003B097E06000001E1E9000001000000871306000000000000000000, 38134), -- QuestPOIBlob
(2921112328, 464882, 'itIT', 0xF21707003B097E06000001E1E9000001000000871306000000000000000000, 38134), -- QuestPOIBlob
(3776013982, 335718, 'itIT', 0x00436172696361206520496E74657276656E746F206174746976616E6F20536375646F2053616C646F2070657220247B2473312F313030307D20732C20526976696E636974612120652067656E6572616E6F20247B2433333537333473312F31307D207261626269612E0000, 38134), -- Spell
(2948698321, 339, 'itIT', 0x6D68C604BDD61274, 38134), -- TactKeyLookup
(2948698321, 278, 'itIT', 0x7CB28F52811F5830, 38134), -- TactKeyLookup
(3776013982, 328547, 'itIT', 0x4E6563726F7369676E6F726900496E63617374726120756E206163756C656F206F7373656F206E656C206265727361676C696F2C20696E666C696767656E646F202473312064616E6E6920697374616E74616E65616D656E74652065202433323430373373312064616E6E692064612073616E6775696E616D656E746F2061676769756E74697669206F676E692024333234303733743120732066696E6368C3A9206E6F6E206D756F7265206F20657363652064616C20636F6D62617474696D656E746F2E0D0A0D0A52697072697374696E61203120636172696361207175616E646F20696C206265727361676C696F206D756F72652E0D0A0D0A7C634646464646464646466F726E6973636520312070756E746F20636F6D626F206520312070756E746F20636F6D626F2061676769756E7469766F20706572206F676E69206163756C656F206F7373656F2061747469766F2E7C720000, 38134), -- Spell
(1369604944, 2081, 'itIT', 0x000000000000000000000000000000000000000000000000210800006E1C00000000FF2200000000000000002C010000EE0204020000410B0000000000000000002208, 38134), -- SpellVisualMissile
(4033975491, 439153, 'itIT', 0x00000000000000000000000000000000000000000000000071B3060092001500000000000000000000000000000000000000000000000000000000803F00000000FFFFFFFFFFFF00000C000000000000000000000000FF340200, 38134), -- SpellVisualKitModelAttach
(4033975491, 439152, 'itIT', 0x00000000000000000000000000000000000000000000000070B3060092001600000000000000000000000000000000000000000000000000000000803F00000000FFFFFFFFFFFF00000C000000000000000000000000FF340200, 38134), -- SpellVisualKitModelAttach
(1181150530, 377991, 'itIT', 0x050000001ABB020096D20100, 38134), -- SpellVisualKitEffect
(1181150530, 377990, 'itIT', 0x0500000019BB0200F3290200, 38134), -- SpellVisualKitEffect
(1181150530, 377988, 'itIT', 0x0500000019BB020054180200, 38134), -- SpellVisualKitEffect
(1181150530, 377987, 'itIT', 0x0500000018BB020088F60100, 38134), -- SpellVisualKitEffect
(1181150530, 377986, 'itIT', 0x0500000017BB020088F60100, 38134), -- SpellVisualKitEffect
(1181150530, 377985, 'itIT', 0x0500000016BB0200820F0200, 38134), -- SpellVisualKitEffect
(1181150530, 377984, 'itIT', 0x0500000015BB02009FFA0100, 38134), -- SpellVisualKitEffect
(1181150530, 377983, 'itIT', 0x050000006C4E01004B4B0100, 38134), -- SpellVisualKitEffect
(1181150530, 377982, 'itIT', 0x0200000071B30600FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377981, 'itIT', 0x0200000070B30600FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377980, 'itIT', 0x05000000EFCC0100FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377979, 'itIT', 0x06000000B7D20500FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377978, 'itIT', 0x0500000014BB020052F20100, 38134), -- SpellVisualKitEffect
(1181150530, 377977, 'itIT', 0x0500000013BB0200D8030200, 38134), -- SpellVisualKitEffect
(3425193231, 278473, 'itIT', 0x060000000D0000000000000000000000000000000000000002000000494B01001EA30100, 38134), -- SpellVisualEvent
(3425193231, 278472, 'itIT', 0x060000000D0000000000000000000000000000000000000001000000494B01001EA30100, 38134), -- SpellVisualEvent
(3425193231, 278471, 'itIT', 0x030000000D0000000000000000000000000000000000000001000000FF3402001EA30100, 38134), -- SpellVisualEvent
(3425193231, 278470, 'itIT', 0x010000000200000000000000000000000000000000000000010000004A4B01001EA30100, 38134), -- SpellVisualEvent
(859088734, 381623, 'itIT', 0xFFFFFFFF360000000000, 38134), -- SpellVisualAnim
(4146370265, 107294, 'itIT', 0x0000000000000000000000000000000000000000000000000000000000000000FF22000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SpellVisual
(3266400455, 613060, 'itIT', 0x1ABB02002C713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613059, 'itIT', 0x1ABB02002B713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613058, 'itIT', 0x1ABB02002A713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613057, 'itIT', 0x1ABB020029713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613056, 'itIT', 0x1ABB020028713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613055, 'itIT', 0x19BB0200BC6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613054, 'itIT', 0x19BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613053, 'itIT', 0x19BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613052, 'itIT', 0x19BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613051, 'itIT', 0x19BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613050, 'itIT', 0x19BB0200B76A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613049, 'itIT', 0x19BB0200B66A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613043, 'itIT', 0x18BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613042, 'itIT', 0x18BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613041, 'itIT', 0x18BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613040, 'itIT', 0x18BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613039, 'itIT', 0x18BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613038, 'itIT', 0x17BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613037, 'itIT', 0x17BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613036, 'itIT', 0x17BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613035, 'itIT', 0x17BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613034, 'itIT', 0x17BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613033, 'itIT', 0x16BB0200BC6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613032, 'itIT', 0x16BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613031, 'itIT', 0x16BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613030, 'itIT', 0x16BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613029, 'itIT', 0x16BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613028, 'itIT', 0x16BB0200B76A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613027, 'itIT', 0x16BB0200B66A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613018, 'itIT', 0x15BB0200C36A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613017, 'itIT', 0x15BB0200C26A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613016, 'itIT', 0x15BB0200C16A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613015, 'itIT', 0x15BB0200C06A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613014, 'itIT', 0x15BB0200BF6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613013, 'itIT', 0x15BB0200BE6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613012, 'itIT', 0x15BB0200BD6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613011, 'itIT', 0x14BB02004AE21900010000803F, 38134), -- SoundKitEntry
(3266400455, 613010, 'itIT', 0x14BB02004BE21900010000803F, 38134), -- SoundKitEntry
(3266400455, 613009, 'itIT', 0x14BB02004CE21900010000803F, 38134), -- SoundKitEntry
(3266400455, 613008, 'itIT', 0x13BB0200C36A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613007, 'itIT', 0x13BB0200C26A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613006, 'itIT', 0x13BB0200C16A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613005, 'itIT', 0x13BB0200C06A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613004, 'itIT', 0x13BB0200BF6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613003, 'itIT', 0x13BB0200BE6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613002, 'itIT', 0x13BB0200BD6A3500010000803F, 38134), -- SoundKitEntry
(3232102598, 140456, 'itIT', 0xA82402001ABB02000000A040000000410000000000000000000000000000000000000000020000000000000000E8030000E8030000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000F4010000F4010000580C00000000803F010000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140455, 'itIT', 0xA7240200AF6C02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140454, 'itIT', 0xA6240200C06502000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140453, 'itIT', 0xA5240200D07102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140452, 'itIT', 0xA424020019BB02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140451, 'itIT', 0xA3240200020A00000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140450, 'itIT', 0xA224020018BB02000000A040000000410000000000000000000000000000000000000000020000000000000000E8030000E8030000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140449, 'itIT', 0xA124020017BB02000000A040000000410000000000000000000000000000000000000000020000000000000000F4010000F4010000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140448, 'itIT', 0xA02402003E7502000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140447, 'itIT', 0x9F240200447502000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140446, 'itIT', 0x9E24020016BB02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000100FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140445, 'itIT', 0x9D24020015BB02000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140444, 'itIT', 0x9C240200B9710200000040410000C04100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140443, 'itIT', 0x9B240200956C02000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140442, 'itIT', 0x9A240200177202000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140441, 'itIT', 0x99240200F46F02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140440, 'itIT', 0x98240200817202000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140439, 'itIT', 0x97240200557102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140438, 'itIT', 0x96240200ED6602000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140437, 'itIT', 0x952402001E7102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140436, 'itIT', 0x94240200E56602000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140435, 'itIT', 0x9324020014BB02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140434, 'itIT', 0x9224020013BB02000000A040000000410000000000000000000000000000000000000000020000000000000000F4010000F4010000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140433, 'itIT', 0x91240200666C02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140432, 'itIT', 0x90240200267102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123926, 'itIT', 0x16E40100407602000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000002C01000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123714, 'itIT', 0x42E30100437502000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000101F4010000F4010000570C0000E8030000E8030000580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123675, 'itIT', 0x1BE30100457502000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123670, 'itIT', 0x16E301003D7502000000A04000002041000000000000000000000000000000000000000002E6000000E6000000E6000000E6000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123594, 'itIT', 0xCAE20100F17402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123515, 'itIT', 0x7BE20100A27402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000002C01000000000000000000000001C8000000C8000000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123514, 'itIT', 0x7AE20100A17402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000009600000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123504, 'itIT', 0x70E201009F7402000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001401F0000401F0000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123503, 'itIT', 0x6FE201009E7402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000002C010000000000000000000000016400000064000000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123502, 'itIT', 0x6EE201009D7402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000009600000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122935, 'itIT', 0x37E00100507202000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000100FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122901, 'itIT', 0x15E00100167202000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000100FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122891, 'itIT', 0x0BE00100187202000000C0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122821, 'itIT', 0xC5DF0100D1710200000000400000804000000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122814, 'itIT', 0xBEDF0100C87102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122807, 'itIT', 0xB7DF0100C17102000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001BC020000BC020000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122806, 'itIT', 0xB6DF0100C07102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122804, 'itIT', 0xB4DF0100BE7102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000009600000000000000000000000001C8000000C8000000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122709, 'itIT', 0x55DF01004A7102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122629, 'itIT', 0x05DF0100F97002000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B44300000000000000C800000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122404, 'itIT', 0x24DE0100F56F02000000C0400000404100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000B80B0000B80B0000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121643, 'itIT', 0x2BDB0100D76C02000000803F0000004000000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B4430000000000000000000000000000000000000001012C0100002C010000570C0000E8030000E8030000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121613, 'itIT', 0x0DDB0100976C02000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B4430000000000000000000000000000000000000000012C0100002C010000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121609, 'itIT', 0x09DB0100906C02000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000B80B0000B80B0000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121587, 'itIT', 0xF3DA0100686C02000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000E8030000E8030000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 120239, 'itIT', 0xAFD50100E66602000000C040000040410000000000000000000000000000000000000000000000000000000000F4010000F4010000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001E8030000E8030000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 119974, 'itIT', 0xA6D40100D66502000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000002FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 25856, 'itIT', 0x00650000C9E600000000A04000002041000000000000000000000000000000000000000002E6000000E6000000E6000000E6000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(1485693696, 5565, 'itIT', 0x1ABB0200010000000069620000000000000100, 38134); -- SoundEnvelope
