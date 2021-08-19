DELETE FROM `broadcast_text_locale` WHERE `locale` = 'deDE' AND `ID` IN (209968, 208581);
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(209968, 'deDE', '', 'Willkommen. Habt Ihr Interesse an Schlüsselsteinen?', 38134),
(208581, 'deDE', 'Grüße, BENUTZERNAME. Ich hoffe, Ihr habt einen ZUFALLSGENERIERTES POSITIVES ADJEKTIV Tag.', '', 38134);

DELETE FROM `item_search_name_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(52489, 'deDE', 'Strassbesetzte Sonnenbrille', 38134);

DELETE FROM `currency_types_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `currency_types_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1191, 'deDE', 'Tapferkeitspunkte', 'Eine Währung, mit der Gegenstände aus mythischen Dungeons verbessert werden können.', 38134),
(1602, 'deDE', 'Eroberung', 'Errungen durch gewertete PvP-Aktivitäten. Wird zum Kauf von Ausrüstung in Oribos verwendet.', 38134),
(1828, 'deDE', 'Seelenasche', 'Eine Rohenergiequelle, die in Torghast gefunden werden kann. Treibt die Kammer des Runenmetzes an.', 38134);

DELETE FROM `spell_name_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(328547, 'deDE', 'Gezackter Knochenstachel', 38134),
(335718, 'deDE', 'Revanche', 38134),
(340882, 'deDE', 'Gasbeutel rufen', 38134),
(351967, 'deDE', 'Rosenpustel rufen', 38134),
(320914, 'deDE', 'Stundenglas des Chronomanten', 38134),
(350249, 'deDE', 'Zeitkrümmung', 38134),
(320740, 'deDE', 'Fixieren', 38134),
(335161, 'deDE', 'Animaausstoß', 38134),
(340433, 'deDE', 'Gabe von Sündensturz', 38134),
(220358, 'deDE', 'Wirbelschläge', 38134),
(352329, 'deDE', '[DNT] Learn Bananas', 38134),
(163708, 'deDE', 'Verzaubertes Freudenfeuer', 38134),
(34477, 'deDE', 'Irreführung', 38134),
(202335, 'deDE', 'Fass aufmachen', 38134),
(209584, 'deDE', 'Zenfokustee', 38134),
(235219, 'deDE', 'Kälteeinbruch', 38134),
(243435, 'deDE', 'Stärkendes Gebräu', 38134),
(248518, 'deDE', 'Ableiten', 38134),
(321995, 'deDE', 'Hypothermische Präsenz', 38134),
(327193, 'deDE', 'Ruhmreicher Moment', 38134),
(352497, 'deDE', '[DNT] Teleport', 38134),
(294587, 'deDE', 'Obleronstacheln x2', 38134),
(294588, 'deDE', 'Obleronstacheln x3', 38134),
(322841, 'deDE', 'Zornschwinge', 38134),
(324919, 'deDE', 'Zornschwinge', 38134),
(352816, 'deDE', '[DNT] Grant Keystone', 38134),
(341220, 'deDE', 'Armbrust der Schlundgebundenen', 38134),
(321136, 'deDE', 'Strahlendes Licht', 38134),
(255260, 'deDE', 'Chaosbrandmal', 38134),
(281242, 'deDE', 'Chaosbrandmal', 38134),
(337541, 'deDE', 'Geist der Finsterflamme', 38134),
(71, 'deDE', 'Frontkämpfer', 38134),
(48263, 'deDE', 'Veteran des Dritten Krieges', 38134),
(245013, 'deDE', 'Gleichgewicht des Braumeisters', 38134),
(300346, 'deDE', 'Bärenadept', 38134),
(316714, 'deDE', 'Veteran des Dritten Krieges', 38134),
(319278, 'deDE', 'Veteran des Vierten Krieges', 38134),
(353367, 'deDE', 'Aegis des Lichts', 38134),
(337334, 'deDE', 'Kiefers Himmelsgriff', 38134),
(336061, 'deDE', 'Schleimansturm', 38134),
(340271, 'deDE', 'Geronnene Ansteckung', 38134),
(327332, 'deDE', 'Waffe verzaubern', 38134),
(45525, 'deDE', 'Arkane Intelligenz', 38134),
(354135, 'deDE', 'Bottom Barrier Visual', 38134),
(321828, 'deDE', 'Klatschspiel', 38134),
(321832, 'deDE', 'Völkerball', 38134),
(326180, 'deDE', 'Fangspiel', 38134),
(322416, 'deDE', 'Felsfraktur', 38134);

DELETE FROM `criteria_tree_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(91079, 'deDE', 'Login with Bananas license (Charity Pet 2021)', 38134),
(91080, 'deDE', '', 38134),
(91081, 'deDE', 'Earn character-level Bananas achievement', 38134),
(91082, 'deDE', '', 38134),
(91386, 'deDE', 'Ve\'nari reputation is Apprehensive', 38134),
(91388, 'deDE', 'Ve\'nari reputation is Tentative', 38134),
(91390, 'deDE', 'Ve\'nari reputation is Ambivalent', 38134),
(91392, 'deDE', 'Ve\'nari reputation is Cordial', 38134),
(91393, 'deDE', '', 38134),
(91503, 'deDE', 'Do You Have All Rank 1s in a Covenant Sanctum?', 38134),
(91504, 'deDE', 'Login test for backporting of \"do you have all level 1 buildings\"', 38134),
(91505, 'deDE', '', 38134),
(91506, 'deDE', 'Do You Have All Rank 2s in a Covenant Sanctum?', 38134),
(91507, 'deDE', 'Login test for backporting of \"do you have all level 2 buildings\"', 38134),
(91508, 'deDE', '', 38134),
(91509, 'deDE', 'Do You Have All Rank 3s in a Covenant Sanctum?', 38134),
(91510, 'deDE', 'Login test for backporting of \"do you have all level 3 buildings\"', 38134),
(91511, 'deDE', '', 38134),
(91387, 'deDE', 'Ruf bei Ve\'nari ist Besorgt', 38134),
(91389, 'deDE', 'Ruf bei Ve\'nari ist Unverbindlich', 38134),
(91391, 'deDE', 'Ruf bei Ve\'nari ist Zwiespältig', 38134),
(87404, 'deDE', 'Gewinnt bei Wertung 1000 oder höher gewertete PvP-Schlachten in Saison 1 von Shadowlands', 38134),
(87408, 'deDE', 'Gewinnt bei Wertung 1000 oder höher gewertete PvP-Schlachten in Saison 1 von Shadowlands', 38134);

DELETE FROM `specialization_spells_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `specialization_spells_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(5164, 'deDE', '', 38134),
(5369, 'deDE', '', 38134),
(5480, 'deDE', '', 38134),
(6271, 'deDE', '', 38134),
(6285, 'deDE', '', 38134),
(6286, 'deDE', '', 38134),
(6287, 'deDE', '', 38134),
(6288, 'deDE', '', 38134),
(6289, 'deDE', '', 38134),
(6292, 'deDE', '', 38134),
(6293, 'deDE', '', 38134),
(6294, 'deDE', '', 38134),
(6295, 'deDE', '', 38134),
(6298, 'deDE', '', 38134),
(6299, 'deDE', '', 38134),
(6306, 'deDE', '', 38134),
(6377, 'deDE', '', 38134),
(6455, 'deDE', '', 38134),
(6457, 'deDE', '', 38134),
(6463, 'deDE', '', 38134),
(6478, 'deDE', '', 38134),
(6531, 'deDE', '', 38134),
(6532, 'deDE', '', 38134),
(6533, 'deDE', '', 38134),
(6534, 'deDE', '', 38134),
(6535, 'deDE', '', 38134),
(6608, 'deDE', '', 38134),
(5262, 'deDE', '', 38134),
(6609, 'deDE', '', 38134),
(5320, 'deDE', '', 38134),
(5521, 'deDE', '', 38134),
(5580, 'deDE', '', 38134),
(5938, 'deDE', '', 38134),
(6113, 'deDE', '', 38134),
(6114, 'deDE', '', 38134),
(6193, 'deDE', '', 38134),
(6195, 'deDE', '', 38134),
(6324, 'deDE', '', 38134),
(6400, 'deDE', '', 38134),
(6434, 'deDE', '', 38134),
(6447, 'deDE', '', 38134),
(6515, 'deDE', '', 38134),
(6516, 'deDE', '', 38134),
(6610, 'deDE', '', 38134);

DELETE FROM `battlemaster_list_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `battlemaster_list_locale` (`ID`, `locale`, `Name_lang`, `GameType_lang`, `ShortDescription_lang`, `LongDescription_lang`, `VerifiedBuild`) VALUES
(100, 'deDE', 'Gew. Schlachtfeld', '', '', '', 38134),
(866, 'deDE', 'Alle Arenen', 'Rauferei', '', '', 38134),
(1047, 'deDE', 'Mugambala', '', '', '', 38134),
(1048, 'deDE', 'Das Robodrom', '', '', '', 38134),
(1049, 'deDE', 'Hakenkap', '', '', '', 38134),
(1050, 'deDE', 'Emyriumdomäne', '', '', '', 38134);

DELETE FROM `area_table_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(12876, 'deDE', 'Sitz des Primus', 38134),
(12917, 'deDE', 'Sündensturz', 38134),
(12924, 'deDE', 'Ardenwald', 38134),
(13387, 'deDE', 'Ardenwald', 38134),
(6852, 'deDE', 'Die Feuerprobe', 38134);

DELETE FROM `char_titles_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `char_titles_locale` (`ID`, `locale`, `Name_lang`, `Name1_lang`, `VerifiedBuild`) VALUES
(679, 'deDE', 'Baron %s', 'Baron %s', 38134),
(680, 'deDE', 'Baronin %s', 'Baronin %s', 38134),
(682, 'deDE', 'Graf %s', 'Graf %s', 38134),
(683, 'deDE', 'Gräfin %s', 'Gräfin %s', 38134);

DELETE FROM `item_sparse_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(52489, 'deDE', '', '', '', '', 'Strassbesetzte Sonnenbrille', 38134),
(180317, 'deDE', '', '', '', '', 'Seelenvoller Heiltrank', 38134),
(180318, 'deDE', '', '', '', '', 'Seelenvoller Manatrank', 38134),
(155622, 'deDE', '', '', '', '', 'Trophäe des Kriegsfürsten', 38134),
(159570, 'deDE', '', '', '', '', 'Kampfgeborenes Siegel', 38134),
(164580, 'deDE', '', '', '', '', 'Kampfgeborenes Siegel', 38134),
(164581, 'deDE', '', '', '', '', 'Kampfgeborenes Siegel', 38134),
(164582, 'deDE', '', '', '', '', 'Kampfgeborenes Siegel', 38134),
(164583, 'deDE', '', '', '', '', 'Kampfgeborenes Siegel', 38134),
(164584, 'deDE', '', '', '', '', 'Trophäe des Kriegsfürsten', 38134),
(164585, 'deDE', '', '', '', '', 'Trophäe des Kriegsfürsten', 38134),
(164586, 'deDE', '', '', '', '', 'Trophäe des Kriegsfürsten', 38134),
(164587, 'deDE', '', '', '', '', 'Trophäe des Kriegsfürsten', 38134),
(164950, 'deDE', '', '', '', '', 'Trophäe des Kriegsfürsten', 38134),
(164951, 'deDE', '', '', '', '', 'Kampfgeborenes Siegel', 38134),
(164952, 'deDE', '', '', '', '', 'Kampfgeborenes Siegel', 38134),
(164953, 'deDE', '', '', '', '', 'Kampfgeborenes Siegel', 38134),
(164954, 'deDE', '', '', '', '', 'Kampfgeborenes Siegel', 38134),
(164955, 'deDE', '', '', '', '', 'Kampfgeborenes Siegel', 38134),
(164956, 'deDE', '', '', '', '', 'Trophäe des Kriegsfürsten', 38134),
(164957, 'deDE', '', '', '', '', 'Trophäe des Kriegsfürsten', 38134),
(164958, 'deDE', '', '', '', '', 'Trophäe des Kriegsfürsten', 38134),
(164959, 'deDE', '', '', '', '', 'Trophäe des Kriegsfürsten', 38134),
(168316, 'deDE', '', '', '', '', 'Kampfgeborenes Siegel', 38134),
(171090, 'deDE', '', '', '', '', 'Kampfgeborenes Siegel', 38134),
(171091, 'deDE', '', '', '', '', 'Kampfgeborenes Siegel', 38134),
(171092, 'deDE', '', '', '', '', 'Kampfgeborenes Siegel', 38134),
(171093, 'deDE', '', '', '', '', 'Kampfgeborenes Siegel', 38134),
(171095, 'deDE', '', '', '', '', 'Trophäe des Kriegsfürsten', 38134),
(171096, 'deDE', '', '', '', '', 'Trophäe des Kriegsfürsten', 38134),
(171097, 'deDE', '', '', '', '', 'Trophäe des Kriegsfürsten', 38134),
(171098, 'deDE', '', '', '', '', 'Trophäe des Kriegsfürsten', 38134),
(171099, 'deDE', '', '', '', '', 'Trophäe des Kriegsfürsten', 38134),
(172890, 'deDE', '', '', '', '', 'Kampfgeborenes Siegel', 38134),
(172891, 'deDE', '', '', '', '', 'Kampfgeborenes Siegel', 38134),
(172892, 'deDE', '', '', '', '', 'Kampfgeborenes Siegel', 38134),
(172893, 'deDE', '', '', '', '', 'Kampfgeborenes Siegel', 38134),
(172894, 'deDE', '', '', '', '', 'Kampfgeborenes Siegel', 38134),
(172895, 'deDE', '', '', '', '', 'Trophäe des Kriegsfürsten', 38134),
(172896, 'deDE', '', '', '', '', 'Trophäe des Kriegsfürsten', 38134),
(172897, 'deDE', '', '', '', '', 'Trophäe des Kriegsfürsten', 38134),
(172898, 'deDE', '', '', '', '', 'Trophäe des Kriegsfürsten', 38134),
(172899, 'deDE', '', '', '', '', 'Trophäe des Kriegsfürsten', 38134),
(186099, 'deDE', 'Dieses Gerät lässt in Eurer Ausrüstung einen räumlichen Miniaturriss entstehen, der Platz für einen Edelstein bietet.', '', '', '', 'Apparat für räumliche Neuausrichtung', 38134),
(183122, 'deDE', '', '', '', '', 'Umhang des Todes', 38134),
(183131, 'deDE', '', '', '', '', 'Stygische Greifkette', 38134),
(183135, 'deDE', '', '', '', '', 'Die Gefallenen rufen', 38134),
(183136, 'deDE', '', '', '', '', 'Entflammende Schlundratte', 38134),
(183141, 'deDE', '', '', '', '', 'Stygisches Magma', 38134),
(183165, 'deDE', '', '', '', '', 'Armbrust der Schlundgebundenen', 38134),
(183187, 'deDE', '', '', '', '', 'Schattenweberbeschwörungsformel', 38134),
(174876, 'deDE', '', '', '', '', 'Ausgestochenes Auge von N\'Zoth', 38134),
(187116, 'deDE', '', '', '', '', 'Zielattrappe', 38134);

DELETE FROM `map_difficulty_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `map_difficulty_locale` (`ID`, `locale`, `Message_lang`, `VerifiedBuild`) VALUES
(4775, 'deDE', '', 38134);

DELETE FROM `mount_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `mount_locale` (`ID`, `locale`, `Name_lang`, `SourceText_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1458, 'deDE', 'Wanderndes Urtum', '|cFFFFD200Promotion|r', 'Die Urtume sind standhafte Verteidiger der Wälder Azeroths, sie sind aber auch für ihre eindrucksvollen Kronen aus Blättern bekannt, die im Wechsel der Jahreszeiten ihre Farbe ändern.', 38134);

DELETE FROM `player_condition_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(90553, 'deDE', '', 38134),
(90651, 'deDE', '', 38134),
(90652, 'deDE', '', 38134),
(78581, 'deDE', '', 38134),
(87399, 'deDE', 'Ve\'nari muss Euch gegenüber wertschätzend oder positiver eingestellt sein.', 38134);

DELETE FROM `achievement_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(15010, 'deDE', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Apprehensive standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Apprehensive [DNT]', '', 38134),
(15011, 'deDE', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Tentative standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Tentative [DNT]', '', 38134),
(15012, 'deDE', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Ambivalent standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Ambivalent [DNT]', '', 38134),
(15013, 'deDE', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Cordial standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Cordial [DNT]', '', 38134),
(14340, 'deDE', 'Besiegt einen Boss auf dem Pfad des Aufstiegs.', 'Der Pfad zum Aufstieg 1', 'Schaltet weitere Herausforderungen auf dem Pfad des Aufstiegs frei.', 38134),
(14342, 'deDE', 'Besiegt drei Bosse auf dem Pfad des Aufstiegs.', 'Der Pfad zum Aufstieg 3', 'Schaltet weitere Herausforderungen auf dem Pfad des Aufstiegs frei.', 38134),
(14343, 'deDE', 'Besiegt fünf Bosse auf dem Pfad des Aufstiegs.', 'Der Pfad zum Aufstieg 5', 'Schaltet weitere Herausforderungen auf dem Pfad des Aufstiegs frei.', 38134),
(14344, 'deDE', 'Besiegt sieben Bosse auf dem Pfad des Aufstiegs.', 'Der Pfad zum Aufstieg 7', 'Schaltet weitere Herausforderungen auf dem Pfad des Aufstiegs frei.', 38134),
(14345, 'deDE', 'Besiegt zwölf Bosse auf dem Pfad des Aufstiegs.', 'Der Pfad zum Aufstieg 12', 'Schaltet weitere Herausforderungen auf dem Pfad des Aufstiegs frei.', 38134),
(14346, 'deDE', 'Besiegt 16 Bosse auf dem Pfad des Aufstiegs.', 'Der Pfad zum Aufstieg 16', 'Schaltet weitere Herausforderungen auf dem Pfad des Aufstiegs frei.', 38134),
(14348, 'deDE', 'Besiegt 20 Bosse auf dem Pfad des Aufstiegs.', 'Der Pfad zum Aufstieg 20', 'Schaltet weitere Herausforderungen auf dem Pfad des Aufstiegs frei.', 38134),
(14349, 'deDE', 'Besiegt 24 Bosse auf dem Pfad des Aufstiegs.', 'Der Pfad zum Aufstieg 24', 'Schaltet weitere Herausforderungen auf dem Pfad des Aufstiegs frei.', 38134),
(14351, 'deDE', 'Besiegt 39 Bosse auf dem Pfad des Aufstiegs.', 'Der Pfad zum Aufstieg 39', 'Schaltet weitere Herausforderungen auf dem Pfad des Aufstiegs frei.', 38134),
(14502, 'deDE', 'Besteht die ersten acht Prüfungen der Loyalität.', 'Auf dem Weg zur Loyalität', '', 38134),
(14633, 'deDE', 'Schaltet Rang III des Reisenetzwerks Eures Sanktums frei.', 'Meisternavigator', '', 38134),
(14636, 'deDE', 'Schaltet Rang III des Befehlstischs für Eure Sanktumabenteuer frei.', 'Oberster Abenteurer', '', 38134),
(14637, 'deDE', 'Schaltet Rang V des Spezialfeatures Eures Sanktums frei.', 'Ein ganz besonderes Flair', '', 38134),
(14638, 'deDE', 'Schaltet alle mit Eurem Animaleiter verbundenen Orte frei.', 'Die Anima muss fließen', '', 38134),
(14639, 'deDE', 'Benutzt Euren Animaleiter 50 Mal.', 'Williger Wiederhersteller', '', 38134),
(14670, 'deDE', 'Brütet im Konservatorium der Königin jeweils eine Art von Geist aus.', 'Sehr geistreich', '', 38134),
(14675, 'deDE', 'Brütet im Konservatorium der Königin jeweils eine Art von großem Geist aus.', 'Geisterflüsterer', '', 38134),
(14676, 'deDE', 'Brütet im Konservatorium der Königin jeweils eine Art von göttlichem Geist aus.', 'Retter der göttlichen Geister', '', 38134),
(14677, 'deDE', 'Schließt jede von Falirs Geisterbeobachtungsquests im Konservatorium der Königin ab.', 'Spirituelle Beobachtungen', '', 38134),
(14678, 'deDE', 'Schaltet die folgenden Gunstoptionen für Euren Gluthof frei.', 'Höfische Gunst', '', 38134),
(14679, 'deDE', 'Schaltet die folgenden Aufwertungen für Euren Gluthof frei.', 'Partypalast', '', 38134),
(14680, 'deDE', 'Schaltet die folgenden Annehmlichkeiten für Euren Gluthof frei.', 'Etwas für jeden', '', 38134),
(14681, 'deDE', 'Bildet Euren Gluthofgräber in den folgenden Künsten der Dienerschaft aus.', 'Gräberakademie', '', 38134),
(14682, 'deDE', 'Schließt die unten aufgelisteten Gluthoferfolge ab.', 'Der Festherold', 'Bonustitel: Festherold(in)', 38134),
(14683, 'deDE', 'Schaltet die folgenden kosmetischen Optionen für die Gräber Eures Gluthofs frei.', 'Gräberausstatter', '', 38134),
(14684, 'deDE', 'Schließt alle unten aufgelisteten Erfolge zur Monstrositätenflickerei ab.', 'Monströse Momente', '', 38134),
(14723, 'deDE', 'Empfangt die folgenden Gäste bei Eurem Gluthof.', 'Seid hier Gast', '', 38134),
(14724, 'deDE', 'Helft den folgenden Gästen, bei Eurem Gluthof eine begeisterte Stimmung zu erreichen.', 'Gewinnender Gastgeber', '', 38134),
(14725, 'deDE', 'Veranstaltet einen Gluthof mit vier begeisterten Gästen.', 'Glück im Quartett', '', 38134),
(14726, 'deDE', 'Veranstaltet einen Gluthof, bei dem die folgenden Attribute eine hohe Stufe erreichen.', 'Langweilig wird es jedenfalls nie', '', 38134),
(14727, 'deDE', 'Schließt 10 Ereignisse während eines einzelnen Gluthofs ab.', 'Zeremonienmeister', '', 38134),
(14748, 'deDE', 'Erschafft 25 dieser Modeaccessoires durch die Kunst der Monstrositätenflickerei.', 'Kleider machen Monstrositäten', '', 38134),
(14749, 'deDE', 'Helft Rendel, die folgenden Hüte zu finden, damit er sie beim Gluthof tragen kann.', 'Rendels großer Tag', '', 38134),
(14751, 'deDE', 'Baut jedes der folgenden Konstrukte durch die Kunst der Monstrositätenflickerei.', 'Monströse Montage', 'Reittierbelohnung: Auserwählter Tauralus', 38134),
(14752, 'deDE', 'Schließt die unten aufgelisteten Erfolge der Monstrositätenflickerei ab.', 'Abhakliste für Tote', 'Bonustitel: der/die Monströse & Reittierbelohnung: Gepanzerter auserwählter Tauralus', 38134),
(14753, 'deDE', 'Steuert 100 animagebundene Wickel bei, um Beschwörer Gerard beim Herbeirufen von Visektus, dem Gespenst des Krieges, zu helfen.', 'Alles abgewickelt', '', 38134),
(14764, 'deDE', 'Erhaltet mit Chordys Hilfe den großen Glücksbringer.', 'Der große Glücksbringer', '', 38134),
(14775, 'deDE', 'Erreicht bei Marasmius den Status ehrfürchtig.', 'Volle Schwammerkennung', 'Titelbelohnung: Mykologe/Mykologin', 38134),
(14777, 'deDE', 'Wertet jedes Eurer Paktsanktumfeatures auf.', 'Renovierungsexperte', '', 38134),
(14780, 'deDE', 'Schließt im Konservatorium der Königin alle Meditationsquests von Ohm ab und findet Eure innere Ruhe.', 'Meditationsmeister', '', 38134),
(14789, 'deDE', 'Schließt Lias Questreihe ab, um alle Tiergeister im Konservatorium der Königin wiederherzustellen.', 'Alle Geister, groß und klein', '', 38134),
(14833, 'deDE', 'Erschafft jedes dieser Modeaccessoires durch die Kunst der Monstrositätenflickerei.', 'Modemonstrosität', '', 38134),
(14839, 'deDE', 'Bringt drei Seelenbande in Abenteuern auf Stufe 60.', 'Abenteuerliche Bande', '', 38134),
(14840, 'deDE', 'Bringt einen Abenteurer auf Stufe 20.', 'Abenteuer: Erste Erfahrungen', '', 38134),
(14841, 'deDE', 'Bringt einen Abenteurer auf Stufe 40.', 'Abenteuer: Jetzt geht\'s los!', '', 38134),
(14842, 'deDE', 'Bringt einen Abenteurer auf Stufe 60.', 'Abenteuer: Stark und unverwüstlich', '', 38134),
(14843, 'deDE', 'Sammelt alle 12 Abenteurer Eures Pakts.', 'Abenteuer: Harmonie der Vorsehung', '', 38134),
(14844, 'deDE', 'Schließt die folgenden Schlundabenteuer ab.', 'Abenteuer: In die Bresche', '', 38134),
(14845, 'deDE', 'Schließt ein Abenteuer ab.', 'Abenteuer: Ein Schritt in die richtige Richtung', '', 38134),
(14846, 'deDE', 'Schließt 10 Abenteuer ab.', 'Abenteuer: Blätter im Wald', '', 38134),
(14847, 'deDE', 'Schließt 100 Abenteuer ab.', 'Abenteuer: Beschützer der Schattenlande', '', 38134),
(14851, 'deDE', 'Besiegt Kalisthene und Craven Korinth, während Ihr die geistgeschmiedete Aegis verwendet.', 'Bastion des Schutzes', '', 38134),
(14852, 'deDE', 'Besiegt Alderyn und Myn\'ir sowie den Splitterborkalptraum in einer Prüfung der Loyalität mit Mikanikos.', 'Uhusarenstreich', '', 38134),
(14853, 'deDE', 'Besiegt den Manischen Mortimer, nachdem Ihr von \'Feurige Adern\', \'Eingefroren\', und \'Unkontrolliertes Erbrechen\' betroffen wart.', 'All die schillernden Farben der Pein', '', 38134),
(14854, 'deDE', 'Besteht eine Prüfung der Loyalität, indem ihr jedes Stück der Seelenbandausrüstung verwendet.', 'Es ist nicht, was Ihr tragt', '', 38134),
(14856, 'deDE', 'Besteht eine Prüfung der Weisheit mit fünf ausgerüsteten Amuletten.', 'Nette Amulette', '', 38134),
(14857, 'deDE', 'Besiegt Echthra in einer Prüfung der Weisheit, nachdem Ihr 20 Kriecher getötet habt.', 'Acht Beine für ein Halleluja', '', 38134),
(14858, 'deDE', 'Besiegt Craven Korinth in einer Prüfung der Weisheit, nachdem er zwei Animakugeln verschlungen hat.', 'Verflucht durstig', '', 38134),
(14859, 'deDE', 'Besiegt Athanos in einer Prüfung der Weisheit, nachdem Ihr fünf Machtschwünge überlebt hat.', 'Aus dem Schwung', '', 38134),
(14860, 'deDE', 'Besteht eine Prüfung der Weisheit ohne jegliche Seelenbandausrüstung auszurüsten.', 'Nur das Notwendigste', '', 38134),
(14861, 'deDE', 'Besiegt Kalisthene und Athanos in der Prüfung der Weisheit mit Pelagos, Kleia und Mikanikos.', 'Von den Meistern lernen', '', 38134),
(14862, 'deDE', 'Besteht eine Prüfung der Demut, indem ihr jede Seelenbandausrüstung verwendet.', 'Es ist, wie Ihr es tragt', '', 38134),
(14863, 'deDE', 'Besiegt Thran\'tiok in der Prüfung der Weisheit, ohne ihr Schaden zuzufügen, bevor Ihr alle Phylakterien vernichtet habt.', 'Todesvierschmähte', '', 38134),
(14864, 'deDE', 'Besiegt Azaruux in einer Prüfung der Weisheit mit Pelagos, ohne eine Erinnerung zu konfrontieren.', 'Persönlicher Alptraum', '', 38134),
(14865, 'deDE', 'Besteht alle zehn Prüfungen der Demut mit Pelagos, Kleia und Mikanikos.', 'Jünger der Demut', '', 38134),
(14866, 'deDE', 'Besteht alle zehn Prüfungen der Demut ohne jegliche Amulette oder aktive Kohlenpfannen.', 'Meister des Pfades', '', 38134),
(14887, 'deDE', 'Winkt Athanos zum Abschied, nachdem er Euch winkt.', 'Zum Mond', '', 38134),
(15023, 'deDE', 'Wertet alle vier Paktsanktumfeatures auf Rang I auf.', 'Aus den Trümmern', 'Schaltet frei: Erhöhte Animabelohnungen', 38134),
(15024, 'deDE', 'Wertet alle vier Paktsanktumfeatures auf Rang II auf.', 'Dürre? Welche Dürre?', 'Schaltet frei: Erhöhte Animabelohnungen', 38134),
(15025, 'deDE', 'Wertet alle vier Paktsanktumfeatures auf Rang III auf.', 'Sanctum Sanctorum', 'Schaltet frei: Erhöhte Animabelohnungen', 38134);


DELETE FROM `hotfix_blob` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(13330255, 89547, 'deDE', 0xFB1E0200ECDA0200, 38134), -- ItemXItemEffect
(3865974254, 187116, 'deDE', 0xECDA020000000000, 38134), -- ModifiedReagentItem
(3205218938, 34395, 'deDE', 0x4C4F47494E5F504152454E54414C434F4E54524F4C00446572205A756772696666206175662064696573656E204163636F756E742077757264652064757263682064696520656C7465726C696368652046726569676162652062656772656E7A742E2044696520616B7475656C6C652045696E7374656C6C756E67206B616E6E206F6E6C696E6520C3BC62657220646965204163636F756E7476657277616C74756E67206765C3A46E646572742077657264656E2E0002, 38134), -- GlobalStrings
(3205218938, 33881, 'deDE', 0x424E45545F4552524F525F313100446572205A756772696666206175662064696573656E204163636F756E742077757264652064757263682064696520656C7465726C696368652046726569676162652062656772656E7A742E2044696520616B7475656C6C652045696E7374656C6C756E67206B616E6E206F6E6C696E6520C3BC62657220646965204163636F756E7476657277616C74756E67206765C3A46E646572742077657264656E2E0002, 38134), -- GlobalStrings
(3205218938, 33838, 'deDE', 0x415554485F504152454E54414C5F434F4E54524F4C00446572205A756772696666206175662064696573656E204163636F756E742077757264652064757263682064696520656C7465726C696368652046726569676162652062656772656E7A742E2044696520616B7475656C6C652045696E7374656C6C756E67206B616E6E206F6E6C696E6520C3BC62657220646965204163636F756E7476657277616C74756E67206765C3A46E646572742077657264656E2E0002, 38134), -- GlobalStrings
(1754233351, 4164, 'deDE', 0x69ED040011C2B8323FF3665F3F00004843000048430000000000000000000000000000000000000000000000000000803F0000803F0000A040, 38134), -- SpellMissile
(240389885, 5745, 'deDE', 0x005238383800000000020202020000000001000000080000000A0000000C00000000000000000000000000000000000000, 38134), -- UnitCondition
(3776013982, 322416, 'deDE', 0x00446572205A61756265726E6465206CC3A473737420737465696E69676520526973736520756E74657220616C6C656E204765676E65726E20696E20646572204EC3A46865206175666272656368656E2C2064696520243332323431387331206BC3B6727065726C696368656E205363686164656E20766572757273616368656E20756E642073696520696E20646965204C756674207363686C65756465726E2E0000, 38134), -- Spell
(3865974254, 174876, 'deDE', 0x1CAB020000000000, 38134), -- ModifiedReagentItem
(3776013982, 326180, 'deDE', 0x0024407370656C6C646573633332313837330D0A0000, 38134), -- Spell
(3776013982, 321832, 'deDE', 0x0024407370656C6C646573633331303430360D0A0000, 38134), -- Spell
(3776013982, 321828, 'deDE', 0x004E6562656C7275666572696E20737069656C742024407370656C6C6E616D65333231383238206D69742065696E656D204765676E65722C2066C3BC67742069686D20247331204E617475727363686164656E207A7520756E6420766572776972727420646173205A69656C2066C3BC7220246420446965736572205A6175626572206B616E6E20766F6D205A69656C20756E74657262726F6368656E2077657264656E2E200056657277697272742E00, 38134), -- Spell
(2640972154, 324, 'deDE', 0x44657220476C7574686F6600440100006F00000000000000050000000001000000000000000500000002000000, 38134), -- GarrTalentTree
(2640972154, 321, 'deDE', 0x4D6F6E7374726F736974C3A474656E66616272696B00410100006F00000000000000050000000000000000000000000500000004000000, 38134), -- GarrTalentTree
(2640972154, 320, 'deDE', 0x50666164206465732041756673746965677300400100006F00000000000000050000A31400000000000000000500000001000000, 38134), -- GarrTalentTree
(2640972154, 319, 'deDE', 0x446173204B6F6E7365727661746F7269756D20646572204BC3B66E6967696E003F0100006F00000000000000050000000000000000000000000500000003000000, 38134), -- GarrTalentTree
(4033975491, 441527, 'deDE', 0x00000000666646C000005040000000000000000000000000B7BC06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000000000000FA390200, 38134), -- SpellVisualKitModelAttach
(4033975491, 441526, 'deDE', 0x000000006666464000005040000000000000000000000000B6BC06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000000000000FA390200, 38134), -- SpellVisualKitModelAttach
(4033975491, 441525, 'deDE', 0x000000000000000000005040000000000000000000000000B5BC06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000000000000FA390200, 38134), -- SpellVisualKitModelAttach
(4033975491, 429002, 'deDE', 0x00000000666646C000003040000000000000000000000000CA8B06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF00000000000000000000000000000009210200, 38134), -- SpellVisualKitModelAttach
(4033975491, 429001, 'deDE', 0x000000006666464000003040000000000000000000000000C98B06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF00000000000000000000000000000009210200, 38134), -- SpellVisualKitModelAttach
(4033975491, 429000, 'deDE', 0x000000000000000000003040000000000000000000000000C88B06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF00000000000000000000000000000009210200, 38134), -- SpellVisualKitModelAttach
(1181150530, 381714, 'deDE', 0x02000000B7BC0600FA390200, 38134), -- SpellVisualKitEffect
(1181150530, 381713, 'deDE', 0x02000000B6BC0600FA390200, 38134), -- SpellVisualKitEffect
(1181150530, 381712, 'deDE', 0x02000000B5BC0600FA390200, 38134), -- SpellVisualKitEffect
(3425193231, 280125, 'deDE', 0x090000000A0000000000000000000000000000000000000003000000FA39020075A60100, 38134), -- SpellVisualEvent
(4146370265, 108149, 'deDE', 0x0000000000000000000000000000000000000000000000000000000000000000FF22000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SpellVisual
(3776013982, 354135, 'deDE', 0x000000, 38134), -- Spell
(2939349194, 723, 'deDE', 0x57656C74626F7373652028536861646F776C616E6473290057656C74626F73736500030000002301000000008C4E0100AE08000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 722, 'deDE', 0x5363686C6F7373204E61746872696120284865726F6973636829004865726F697363680003020B0123000000D7008C4E0100F8080F00001E0000000000, 38134), -- GroupFinderActivity
(2939349194, 721, 'deDE', 0x5363686C6F7373204E61746872696120284D7974686973636829004D797468697363680003030B0123000000E6008C4E0100F808100000140000000000, 38134), -- GroupFinderActivity
(2939349194, 720, 'deDE', 0x5363686C6F7373204E61746872696120284E6F726D616C29004E6F726D616C0003010B0123000000C8008C4E0100F8080E00001E0000000000, 38134), -- GroupFinderActivity
(2939349194, 719, 'deDE', 0x5468656174657220646572205363686D65727A656E20284865726F6973636829004865726F697363680002010A016300000073008C4E0100F508020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 718, 'deDE', 0x5468656174657220646572205363686D65727A656E20284D7974686973636829004D797468697363680002010A016300000073008C4E0100F508170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 717, 'deDE', 0x5468656174657220646572205363686D65727A656E20284D797468697363686572205363686CC3BC7373656C737465696E29004D797468697363682B0002010A01C300000073008C4E0100F508080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 716, 'deDE', 0x5468656174657220646572205363686D65727A656E20284E6F726D616C29004E6F726D616C0002010A016300000000008C4E0100F508010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 715, 'deDE', 0x4E656B726F746973636865205363686E6569736520284865726F6973636829004865726F6973636800020109016300000073008C4E0100EE08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 714, 'deDE', 0x4E656B726F746973636865205363686E6569736520284D7974686973636829004D7974686973636800020109016300000073008C4E0100EE08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 713, 'deDE', 0x4E656B726F746973636865205363686E6569736520284D797468697363686572205363686CC3BC7373656C737465696E29004D797468697363682B0002010901C300000073008C4E0100EE08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 712, 'deDE', 0x4E656B726F746973636865205363686E6569736520284E6F726D616C29004E6F726D616C00020109016300000000008C4E0100EE08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 711, 'deDE', 0x537069747A656E206465732041756673746965677320284865726F6973636829004865726F6973636800020108016300000073008C4E0100ED08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 710, 'deDE', 0x537069747A656E206465732041756673746965677320284D7974686973636829004D7974686973636800020108016300000073008C4E0100ED08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 709, 'deDE', 0x537069747A656E206465732041756673746965677320284D797468697363686572205363686CC3BC7373656C737465696E29004D797468697363682B0002010801C300000073008C4E0100ED08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 708, 'deDE', 0x537069747A656E206465732041756673746965677320284E6F726D616C29004E6F726D616C00020108016300000000008C4E0100ED08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 707, 'deDE', 0x426C75746967652054696566656E20284865726F6973636829004865726F6973636800020107016300000073008C4E0100EC08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 706, 'deDE', 0x426C75746967652054696566656E20284D7974686973636829004D7974686973636800020107016300000073008C4E0100EC08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 705, 'deDE', 0x426C75746967652054696566656E20284D797468697363686572205363686CC3BC7373656C737465696E29004D797468697363682B0002010701C300000073008C4E0100EC08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 704, 'deDE', 0x426C75746967652054696566656E20284E6F726D616C29004E6F726D616C00020107016300000000008C4E0100EC08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 703, 'deDE', 0x4E6562656C20766F6E205469726E612053636974686520284D797468697363686572205363686CC3BC7373656C737465696E29004D797468697363682B0002010601C300000073008C4E0100F208080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 702, 'deDE', 0x4E6562656C20766F6E205469726E612053636974686520284D7974686973636829004D7974686973636800020106016300000073008C4E0100F208170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 701, 'deDE', 0x4E6562656C20766F6E205469726E612053636974686520284865726F6973636829004865726F6973636800020106016300000073008C4E0100F208020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 700, 'deDE', 0x4E6562656C20766F6E205469726E612053636974686520284E6F726D616C29004E6F726D616C00020106016300000000008C4E0100F208010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 699, 'deDE', 0x48616C6C656E206465722053C3BC686E6520284D797468697363686572205363686CC3BC7373656C737465696E29004D797468697363682B0002010501C300000073008C4E0100EF08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 698, 'deDE', 0x48616C6C656E206465722053C3BC686E6520284D7974686973636829004D7974686973636800020105016300000073008C4E0100EF08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 697, 'deDE', 0x48616C6C656E206465722053C3BC686E6520284865726F6973636829004865726F6973636800020105016300000073008C4E0100EF08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 696, 'deDE', 0x48616C6C656E206465722053C3BC686E6520284E6F726D616C29004E6F726D616C00020105016300000000008C4E0100EF08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 695, 'deDE', 0x44696520416E64726520536569746520284D797468697363686572205363686CC3BC7373656C737465696E29004D797468697363682B0002010401C300000073008C4E0100F308080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 694, 'deDE', 0x44696520416E64726520536569746520284D7974686973636829004D7974686973636800020104016300000073008C4E0100F308170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 693, 'deDE', 0x44696520416E64726520536569746520284865726F6973636829004865726F6973636800020104016300000073008C4E0100F308020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 692, 'deDE', 0x44696520416E64726520536569746520284E6F726D616C29004E6F726D616C00020104016300000000008C4E0100F308010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 691, 'deDE', 0x5365756368656E737475727A20284D797468697363686572205363686CC3BC7373656C737465696E29004D797468697363682B0002010301C300000073008C4E0100F108080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 690, 'deDE', 0x5365756368656E737475727A20284D7974686973636829004D7974686973636800020103016300000073008C4E0100F108170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 689, 'deDE', 0x5365756368656E737475727A20284865726F6973636829004865726F6973636800020103016300000073008C4E0100F108020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 688, 'deDE', 0x5365756368656E737475727A20284E6F726D616C29004E6F726D616C00020103016300000000008C4E0100F108010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 657, 'deDE', 0x57656C74626F7373652028426174746C6520666F7220417A65726F7468290057656C74626F7373650003000000230100000000BF5300000000000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 498, 'deDE', 0x5A7566C3A46C6C69676572206865726F6973636865722044756E67656F6E2028426174746C6520666F7220417A65726F746829004865726F697363680002028800620000003A00BF5300006A06020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 497, 'deDE', 0x5A7566C3A46C6C69676572206E6F726D616C65722044756E67656F6E2028426174746C6520666F7220417A65726F746829004E6F726D616C0002008800620000000000BF5300006A06010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 458, 'deDE', 0x57656C74626F73736520284C6567696F6E290057656C74626F7373650003000000230100000000BF530000C404000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 418, 'deDE', 0x5A7566C3A46C6C69676572206865726F6973636865722044756E67656F6E20284C6567696F6E29004865726F697363680002026F00620000003200BF530000C404020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 417, 'deDE', 0x5A7566C3A46C6C69676572206E6F726D616C65722044756E67656F6E20284C6567696F6E29004E6F726D616C0002006F00620000000000BF530000C404010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 398, 'deDE', 0x57656C74626F7373652028447261656E6F72290057656C74626F7373650003000000230100000000BF5300005C04000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 397, 'deDE', 0x57656C74626F737365202850616E6461726961290057656C74626F7373650003000000230100000000BF5300006603000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 396, 'deDE', 0x5A7566C3A46C6C69676572206865726F6973636865722044756E67656F6E20285761726C6F72647329004865726F697363680002006D00620000000000BF5300005C04020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 395, 'deDE', 0x5A7566C3A46C6C69676572206E6F726D616C65722044756E67656F6E20285761726C6F72647329004E6F726D616C0002006D00620000000000BF5300005C04010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 364, 'deDE', 0x5A7566C3A46C6C69676572206865726F6973636865722044756E67656F6E202850616E646172696129004865726F697363680002005400620000000000BF5300006603020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 363, 'deDE', 0x5A7566C3A46C6C69676572206E6F726D616C65722044756E67656F6E202850616E646172696129004E6F726D616C0002005400620000000000BF5300006603010000050100000000, 38134), -- GroupFinderActivity
(3776013982, 45525, 'deDE', 0x00457268C3B66874202464206C616E672064696520496E74656C6C6967656E7A2065696E65732056657262C3BC6E646574656E20756D20247331252E00496E74656C6C6967656E7A20756D202473312520657268C3B668742E00, 38134), -- Spell
(3776013982, 327332, 'deDE', 0x00446572205A61756265726E6465207665727A617562657274207365696E65205761666665206D697420416E696D612E20446965206EC3A463687374656E203520416E67726966666520696E6E657268616C6220766F6E20246420766572757273616368656E207A7573C3A4747A6C696368656E2041726B616E7363686164656E2E0057616666656E616E67726966666520766572757273616368656E207A7573C3A4747A6C696368202433323733333173312041726B616E7363686164656E2E00, 38134), -- Spell
(3776013982, 340271, 'deDE', 0x0056657272696E676572742064656E2065726C697474656E656E205363686164656E20766F6E2056657262C3BC6E646574656E20696E6E657268616C6220766F6E203135204D657465726E20756D20243334303237337331252E0045726C697474656E6572205363686164656E20766F6E2056657262C3BC6E646574656E20696E6E657268616C6220766F6E203135204D657465726E20756D20243334303237337331252076657272696E676572742E00, 38134), -- Spell
(3776013982, 336061, 'deDE', 0x000000, 38134), -- Spell
(603412935, 28771, 'deDE', 0xE4B8ADE59BBDE9AB98E5B182E4BABAE4BA8BE58F98E58AA80004, 38134), -- ChatProfanity
(603412935, 28770, 'deDE', 0xE4B8ADE59BBDE9AB98E5B182E69D83E58A9BE69697E4BA890004, 38134), -- ChatProfanity
(603412935, 28769, 'deDE', 0xE4B8ADE59BBDE5AE98E59CBAE68385E69D80E6A1880004, 38134), -- ChatProfanity
(603412935, 28768, 'deDE', 0xE69CB1E6BAB6E59FBA0004, 38134), -- ChatProfanity
(603412935, 28767, 'deDE', 0xE69CB1E6BAB6E9B8A10004, 38134), -- ChatProfanity
(603412935, 28766, 'deDE', 0xE5AFACE8A1A3E5B89D0004, 38134), -- ChatProfanity
(603412935, 28765, 'deDE', 0xE7A588E7BFA00004, 38134), -- ChatProfanity
(603412935, 28764, 'deDE', 0xE5B08FE5ADA6E58D9AE5A3ABE7BFA00004, 38134), -- ChatProfanity
(603412935, 28763, 'deDE', 0xE694BFE59D9BE9BB91E9A9AC0004, 38134), -- ChatProfanity
(603412935, 28762, 'deDE', 0xE694BFE6B2BBE6B581E6B0930004, 38134), -- ChatProfanity
(603412935, 28761, 'deDE', 0xE788B1E59BBDE88085E5908CE79B9FE7BD91E7AB990004, 38134), -- ChatProfanity
(603412935, 28760, 'deDE', 0xE6AF9BE79A87E5B89D0004, 38134), -- ChatProfanity
(603412935, 28759, 'deDE', 0xE999A4E58C85E5AD900004, 38134), -- ChatProfanity
(603412935, 28758, 'deDE', 0xE89BA4E79A870004, 38134), -- ChatProfanity
(603412935, 28757, 'deDE', 0xE89BA4E89F86E698AFE8B0810004, 38134), -- ChatProfanity
(603412935, 28756, 'deDE', 0xE89BA4E89F86E698AFE8AAB00004, 38134), -- ChatProfanity
(603412935, 28755, 'deDE', 0xE680BBE4B9A6E8AEB0E79785E58DB10004, 38134), -- ChatProfanity
(603412935, 28754, 'deDE', 0xE88081E6B19FE79785E58DB10004, 38134), -- ChatProfanity
(603412935, 28753, 'deDE', 0xE6B19FE9A9BEE5B4A90004, 38134), -- ChatProfanity
(603412935, 28752, 'deDE', 0xE6B19FE5898DE79A870004, 38134), -- ChatProfanity
(603412935, 28751, 'deDE', 0xE6B19FE4B88AE79A870004, 38134), -- ChatProfanity
(603412935, 28750, 'deDE', 0xE99995E8A5BFE5B8A6E5A4B4E5A4A7E593A50004, 38134), -- ChatProfanity
(603412935, 28749, 'deDE', 0xE68A97E9BAA6E9838E0004, 38134), -- ChatProfanity
(603412935, 28748, 'deDE', 0xE6A0BCE890A8E5B094E78E8B0004, 38134), -- ChatProfanity
(603412935, 28747, 'deDE', 0xE890A8E6A0BCE5B094E78E8B0004, 38134), -- ChatProfanity
(3776013982, 337334, 'deDE', 0x00457268C3B6687420646965205265696368776569746520766F6E202754696765726B6C617565272061756620247B246D312B357D204D6574657220756E64206265696D2045696E7361747A20737072696E67742049687220736F666F7274207A756D205A69656C2E0D0A0D0A2754696765726B6C617565272062656C65677420646173205A69656C207A7573C3A4747A6C696368206D69742065696E656D20456666656B742C206465722045757265206B726974697363686520547265666665726368616E636520676567656E20646173205A69656C2066C3BC7220243334343032316420756D20243334343032316D312520657268C3B668742E2044696573657220456666656B74206B616E6E2070726F205A69656C206E75722065696E6D616C20616C6C652024333337333431642061756674726574656E2E0000, 38134), -- Spell
(813076512, 80114, 'deDE', 0x2401000057640500, 38134), -- SpellLabel
(813076512, 80113, 'deDE', 0x1A00000057640500, 38134), -- SpellLabel
(813076512, 80112, 'deDE', 0x1000000057640500, 38134), -- SpellLabel
(3776013982, 353367, 'deDE', 0x00526564757A696572742065726C697474656E656E205363686164656E20756D20247331252E0000, 38134), -- Spell
(3776013982, 319278, 'deDE', 0x00457268C3B668742064696520417573646175657220756D20247331252E0D0A243F733331363731345B526564757A696572742064656E2065726C697474656E656E205363686164656E20756D20247333252E5D5B5D0000, 38134), -- Spell
(3776013982, 316714, 'deDE', 0x52616E67203200457268C3B668742064696520417573646175657220756D20247331252E0D0A526564757A696572742064656E2065726C697474656E656E205363686164656E20756D20247B2461627328247332297D252E0000, 38134), -- Spell
(3776013982, 300346, 'deDE', 0x00274D6F6E646665756572272C2027426573C3A46E66746967656E272C2027566572646572626E697320656E746665726E656E2720756E64202757696564657267656275727427206BC3B66E6E656E20696E2042C3A472656E67657374616C742065696E67657365747A742077657264656E2E0D0A0D0A526564757A696572742073C3A46D746C696368656E2065726C697474656E656E205363686164656E20756D20247332252E0000, 38134), -- Spell
(3776013982, 245013, 'deDE', 0x00526564757A696572742073C3A46D746C696368656E2065726C697474656E656E205363686164656E20756D202473322520756E6420657268C3B6687420457572652052C3BC7374756E6720756D20247331252E0000, 38134), -- Spell
(3776013982, 48263, 'deDE', 0x00457268C3B668742064696520417573646175657220756D20247331252E0D0A243F733331363731345B526564757A696572742064656E2065726C697474656E656E205363686164656E20756D20247333252E5D5B5D0000, 38134), -- Spell
(3776013982, 71, 'deDE', 0x00496872207365696420766F6D204B616D70662067657374C3A4686C742C2077617320457572656E2065726C697474656E656E205363686164656E20756D202473332520726564757A696572742C204575726520417573646175657220756D202473322520657268C3B6687420756E6420457572652052C3BC7374756E6720756D2024733125204575726572205374C3A4726B6520657268C3B668742E0000, 38134), -- Spell
(3776013982, 337541, 'deDE', 0x00457565722027466C616D6D656E646573204272616E646D616C27206865696C742045756368206A65747A7420696D205665726C61756620766F6E20243333373534336420756D2024733125206465732076657275727361636874656E20496E697469616C7363686164656E7320756E64206A6564657220766F6E20457572656D20275A65696368656E2064657220466C616D6D652720676574726F6666656E65204765676E657220657268C3B668742064656E20736F666F72746967656E205363686164656E204575726573206EC3A463687374656E2045696E7361747A657320766F6E2027466C616D6D656E646573204272616E646D616C2720756D20243333373534327331252E20426973207A752024333337353432752D6D616C2073746170656C6261722E0000, 38134), -- Spell
(3776013982, 281242, 'deDE', 0x0045756572205363686164656E2066C3BC67742064656D205A69656C2065696E204272616E646D616C207A752C206461732064657373656E2065726C697474656E656E204D616769657363686164656E20756D20243134393073312520657268C3B668742E0000, 38134), -- Spell
(3776013982, 255260, 'deDE', 0x0045756572205363686164656E2066C3BC67742064656D205A69656C2065696E204272616E646D616C207A752C206461732064657373656E2065726C697474656E656E204D616769657363686164656E20756D20243134393073312520657268C3B668742E0000, 38134), -- Spell
(603412935, 28746, 'deDE', 0x5C62725C733F615C733F705C733F655C733F5C620000, 38134), -- ChatProfanity
(603412935, 28745, 'deDE', 0x5C62725C733F655C733F745C733F615C733F725C733F64285C733F737C5C733F655C733F64293F5C620000, 38134), -- ChatProfanity
(4033975491, 436804, 'deDE', 0x00000000000000000000000000000000000000000000000044AA06000A59FF0E030000000000000000000000000000000000000000000000000000803F00000000FFFFFFFFFFFF00000000000000CDCC4C3DCDCC4C3DCC0B0200, 38134), -- SpellVisualKitModelAttach
(3386943305, 171057, 'deDE', 0x07787800000000000000004A00B20200000000081000000000000400000000000000000001000040000000000000000000E05A0200, 38134), -- CreatureDifficulty
(3386943305, 170644, 'deDE', 0x07787800000000000000001000B2020000000008100000000000000000000000000000000100000000000000000000000068590200, 38134), -- CreatureDifficulty
(3899321669, 4791, 'deDE', 0xB71200000101180B0300, 38134), -- SpellAuraVisibility
(3899321669, 4790, 'deDE', 0xB61200000001180B0300, 38134), -- SpellAuraVisibility
(4033975491, 440494, 'deDE', 0x0000000000000000CDCC4C3E000000000000000000000000AEB80600D058FF00000000000000000000000000000000000000000000000000003333333F0000000000009E009F0000000000000000000000000000000051160200, 38134), -- SpellVisualKitModelAttach
(4033975491, 440493, 'deDE', 0x0000000000000000CDCCCC3D000000000000000000000000ADB806007F87FF00000000000000000000000000000000000000000000000000003333333F0000000000009E009F0000000000000000000000000000000051160200, 38134), -- SpellVisualKitModelAttach
(4033975491, 417672, 'deDE', 0x000000000000000000000000000000000000000000000000885F06000F5AFF00000000000000000000000000000000000000000000000000000000C03F00000000FFFFFFFFFFFF00000800000000000000000000000021030200, 38134), -- SpellVisualKitModelAttach
(4033975491, 417626, 'deDE', 0x0000000000000000000000000000000000000000000000005A5F0600E64BFF0000000000000000000000000000000000000000000000000000333373400000000000009E009F0000000000000000000000000000000009030200, 38134), -- SpellVisualKitModelAttach
(1181150530, 380178, 'deDE', 0x02000000AEB8060051160200, 38134), -- SpellVisualKitEffect
(1181150530, 380177, 'deDE', 0x02000000ADB8060051160200, 38134), -- SpellVisualKitEffect
(3776013982, 321136, 'deDE', 0x004E616368206A657765696C732024733120246C45696E7361747A3A45696E73C3A4747A656E3B20766F6E2027536368696C6420646572205265636874736368616666656E656E2720776972642045756572206EC3A46368737465732027576F72742064657220486572726C6963686B65697427206B6F7374656E6C6F732E0000, 38134), -- Spell
(3776013982, 341220, 'deDE', 0x000024407370656C6C6465736333343132313200, 38134), -- Spell
(3865974254, 183187, 'deDE', 0x93CB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183165, 'deDE', 0x7DCB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183141, 'deDE', 0x65CB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183136, 'deDE', 0x60CB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183135, 'deDE', 0x5FCB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183131, 'deDE', 0x5BCB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183122, 'deDE', 0x52CB020000000000, 38134), -- ModifiedReagentItem
(3776013982, 352816, 'deDE', 0x000000, 38134), -- Spell
(600565378, 300040, 'deDE', 0xA06D01000000803F0000803F0074BA0200, 38134), -- CreatureXDisplayInfo
(813076512, 79920, 'deDE', 0x9703000075A80400, 38134), -- SpellLabel
(13330255, 73366, 'deDE', 0x081D0200F3D60200, 38134), -- ItemXItemEffect
(3865974254, 186099, 'deDE', 0xF3D6020000000000, 38134), -- ModifiedReagentItem
(600565378, 299890, 'deDE', 0x4A6400000000803F0000803F001CBA0200, 38134), -- CreatureXDisplayInfo
(600565378, 299885, 'deDE', 0x0A6F01000000803F0000803F0017BA0200, 38134), -- CreatureXDisplayInfo
(3865974254, 172899, 'deDE', 0x63A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172898, 'deDE', 0x62A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172897, 'deDE', 0x61A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172896, 'deDE', 0x60A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172895, 'deDE', 0x5FA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172894, 'deDE', 0x5EA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172893, 'deDE', 0x5DA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172892, 'deDE', 0x5CA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172891, 'deDE', 0x5BA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172890, 'deDE', 0x5AA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171099, 'deDE', 0x5B9C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171098, 'deDE', 0x5A9C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171097, 'deDE', 0x599C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171096, 'deDE', 0x589C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171095, 'deDE', 0x579C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171094, 'deDE', 0x569C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171093, 'deDE', 0x559C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171092, 'deDE', 0x549C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171091, 'deDE', 0x539C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171090, 'deDE', 0x529C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 168316, 'deDE', 0x7C91020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164959, 'deDE', 0x5F84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164958, 'deDE', 0x5E84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164957, 'deDE', 0x5D84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164956, 'deDE', 0x5C84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164955, 'deDE', 0x5B84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164954, 'deDE', 0x5A84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164953, 'deDE', 0x5984020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164952, 'deDE', 0x5884020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164951, 'deDE', 0x5784020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164950, 'deDE', 0x5684020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164587, 'deDE', 0xEB82020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164586, 'deDE', 0xEA82020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164585, 'deDE', 0xE982020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164584, 'deDE', 0xE882020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164583, 'deDE', 0xE782020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164582, 'deDE', 0xE682020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164581, 'deDE', 0xE582020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164580, 'deDE', 0xE482020000000000, 38134), -- ModifiedReagentItem
(3865974254, 159570, 'deDE', 0x526F020000000000, 38134), -- ModifiedReagentItem
(3865974254, 155622, 'deDE', 0xE65F020000000000, 38134), -- ModifiedReagentItem
(3205218938, 43871, 'deDE', 0x43555252454E43595F534541534F4E5F544F54414C5F4D4158494D554D00536169736F6E6D6178696D756D3A20257325732F25730001, 38134), -- GlobalStrings
(3776013982, 324919, 'deDE', 0x0024407370656C6C646573633332323834310000, 38134), -- Spell
(3776013982, 322841, 'deDE', 0x00457268C3B668742064656E205363686164656E20766F6E20243F613231323631325B2754657566656C73726175736368275D3F613231323631335B27496E6665726E6F65696E7363686C6167275D5B5D20756D20247331252E005363686164656E20766F6E20243F613231323631325B2754657566656C73726175736368275D3F613231323631335B27496E6665726E6F65696E7363686C6167275D5B5D20756D202473312520657268C3B668742E00, 38134), -- Spell
(3776013982, 294588, 'deDE', 0x00457268C3B6687420646965206B726974697363686520547265666665726368616E636520756D20247B2473312A2432393435373873317D252E0000, 38134), -- Spell
(3776013982, 294587, 'deDE', 0x00457268C3B6687420646965206B726974697363686520547265666665726368616E636520756D20247B2473312A2432393435373873317D252E0000, 38134), -- Spell
(3865974254, 180318, 'deDE', 0x5EC0020000000000, 38134), -- ModifiedReagentItem
(3865974254, 180317, 'deDE', 0x5DC0020000000000, 38134), -- ModifiedReagentItem
(3865974254, 176406, 'deDE', 0x16B1020000000000, 38134), -- ModifiedReagentItem
(3865974254, 168564, 'deDE', 0x7492020000000000, 38134), -- ModifiedReagentItem
(3776013982, 352497, 'deDE', 0x000000, 38134), -- Spell
(3776013982, 327193, 'deDE', 0x005365747A74206469652041626B6C696E677A65697420766F6E2027536368696C64206465732052C3A4636865727327207A7572C3BC636B2E2045757265206EC3A463687374656E20246E2045696E73C3A4747A6520766F6E2027536368696C64206465732052C3A463686572732720686162656E206B65696E652041626B6C696E677A65697420756E6420766572757273616368656E2024733225206D656872205363686164656E2E0045757265206EC3A463687374656E20246E2045696E73C3A4747A6520766F6E2027536368696C64206465732052C3A463686572732720686162656E206B65696E652041626B6C696E677A65697420756E6420766572757273616368656E2024773225206D656872205363686164656E2E00, 38134), -- Spell
(3776013982, 321995, 'deDE', 0x004E65686D74206461732045697320696E20457572656E20416465726E2067616E7A20616E2C20776173206469652052756E656E6D616368746B6F7374656E2045757265722046C3A46869676B656974656E202464206C616E6720756D20247331252076657272696E676572742E204CC3B673742064696520676C6F62616C652041626B6C696E677A656974206E69636874206175732E0052756E656E6D616368746B6F7374656E2045757265722046C3A46869676B656974656E20756D20247331252076657272696E676572742E00, 38134), -- Spell
(3776013982, 248518, 'deDE', 0x5076502D54616C656E7400446572206EC3A463687374652061756620646173205A69656C2067657769726B7465206665696E646C69636865205A61756265722062657769726B742C206461737320616C6C6520776569746572656E206665696E646C696368656E205A6175626572202473312053656B2E206C616E672061756620457572656E204265676C656974657220616267656C65697465742077657264656E2E0D0A0D0A45756572204265676C6569746572206D757373207369636820696E6E657268616C6220766F6E20243234383531396131204D657465726E20756D20646173205A69656C2061756668616C74656E2C2064616D6974205A617562657220616267656C65697465742077657264656E2E0000, 38134), -- Spell
(3776013982, 243435, 'deDE', 0x004CC3A473737420457572652048617574207A7520537465696E2077657264656E2C20776173204575726520616B7475656C6C6520736F776965206D6178696D616C6520476573756E646865697420756D202473312520657268C3B6687420756E6420457572656E2065726C697474656E656E205363686164656E20756D20247332252076657272696E676572742E2048C3A46C74202464206C616E6720616E2E004D6178696D616C6520476573756E646865697420756D202477312520657268C3B668742E0D0A45726C697474656E6572205363686164656E20756D20247732252076657272696E676572742E243F2477343E315B0D0A4162736F72626965727420247734205363686164656E2E5D5B5D00, 38134), -- Spell
(3776013982, 235219, 'deDE', 0x005363686C6965C39F74206469652041626B6C696E677A656974204575726572205A617562657220274569736261727269657265272C202746726F73746E6F7661272C20274BC3A46C74656B6567656C2720756E642027456973626C6F636B272061622E0000, 38134), -- Spell
(3776013982, 209584, 'deDE', 0x5076502D54616C656E7400476577C3A4687274202464206C616E6720496D6D756E6974C3A47420676567656E205374696C6C652D20756E6420556E7465726272656368756E6773656666656B74652E00496D6D756E20676567656E205374696C6C652D20756E6420556E7465726272656368756E6773656666656B74652E00, 38134), -- Spell
(3776013982, 202335, 'deDE', 0x5076502D54616C656E7400446572205363686164656E204575726573206EC3A463687374656E2045696E7361747A657320766F6E20274661737368696562272069737420756D202473312520657268C3B6687420756E6420626574C3A475627420616C6C6520676574726F6666656E656E205A69656C652066C3BC72202432303233343664002746617373686965622720766572757273616368742024733125207A7573C3A4747A6C696368656E205363686164656E20756E6420626574C3A475627420616C6C6520676574726F6666656E656E205A69656C652066C3BC7220243230323334366400, 38134), -- Spell
(3776013982, 34477, 'deDE', 0x004C656974657420457572652065727A657567746520426564726F68756E67206175662064617320617573676577C3A4686C7465204772757070656E2D206F646572205363686C616368747A7567736D6974676C69656420756D2E2044657220456666656B7420626567696E6E74206D697420457572656D206EC3A463687374656E20416E677269666620696E6E657268616C6220766F6E20246420756E642068C3A46C742024333530373964206C616E6720616E2E00426564726F68756E67207769726420766F6D204AC3A467657220756D67656C65697465742E00, 38134), -- Spell
(3359787322, 19830, 'deDE', 0x764D0000, 38134), -- WorldState
(3359787322, 19710, 'deDE', 0xFE4C0000, 38134), -- WorldState
(3359787322, 19709, 'deDE', 0xFD4C0000, 38134), -- WorldState
(3359787322, 19384, 'deDE', 0xB84B0000, 38134), -- WorldState
(368401261, 5214, 'deDE', 0x5B8800000000000000000000000000000000000000000000, 38134), -- CombatCondition
(368401261, 4771, 'deDE', 0x848400000000000000000000000000000000000000000000, 38134), -- CombatCondition
(3776013982, 163708, 'deDE', 0x00457268C3B668742064656E205A61756265727363686164656E20756D203230252E0D0A0D0A45726DC3B6676C696368742065732064656E2053657468656B6B6172616B6B6F612C20275665727A6175626572746520466C616D6D6527207A75207769726B656E2E00457268C3B668742064656E205A61756265727363686164656E20756D203230252E0D0A0D0A45726DC3B6676C696368742065732064656E2053657468656B6B6172616B6B6F612C20275665727A6175626572746520466C616D6D6527207A75207769726B656E2E00, 38134), -- Spell
(3776013982, 352329, 'deDE', 0x000000, 38134), -- Spell
(3865974254, 52489, 'deDE', 0x09CD000000000000, 38134), -- ModifiedReagentItem
(3037505077, 52489, 'deDE', 0x0100, 38134), -- TradeSkillItem
(3776013982, 220358, 'deDE', 0x0024407370656C6C646573633130313534360000, 38134), -- Spell
(3776013982, 340433, 'deDE', 0x005665726665696E6572746520416E696D61206475726368737472C3B66D74204575636820756E6420657268C3B6687420457572656E2076657275727361636874656E205363686164656E20736F776965204575726520686572766F726765727566656E65204865696C756E67202464206C616E6720756D20247331252E00566572757273616368746572205363686164656E20756D202473312520657268C3B668742E0D0A486572766F726765727566656E65204865696C756E6720756D202473322520657268C3B668742E00, 38134), -- Spell
(3776013982, 335161, 'deDE', 0x00566F6E20646566656B74656E20476F6C696174687320676573616D6D656C74657220416E696D6161757373746FC39F20657268C3B6687420646965204265776567756E6773676573636877696E6469676B65697420756D202473312520756E64206CC3A47373742064656E20537069656C657263686172616B74657220616C6C65202474332053656B2E206175736272656368656E2C20776173204765676E65726E20696E20646572204EC3A46865202433343434323173312041726B616E7363686164656E207A7566C3BC677420756E642056657262C3BC6E6465746520696E20646572204EC3A4686520756D2024333434343232733120476573756E6468656974206865696C742E2048C3A46C74202464206C616E6720616E2E004265776567756E6773676573636877696E6469676B65697420756D202473312520657268C3B668742E2046C3BC677420616C6C65202474332053656B2E204765676E65726E20696E20646572204EC3A46865202433343434323173312041726B616E7363686164656E207A7520756E64206865696C742056657262C3BC6E6465746520696E20646572204EC3A4686520646162656920756D2024333434343232733120476573756E64686569742E00, 38134), -- Spell
(3205218938, 43287, 'deDE', 0x4741525249534F4E5F464F4C4C4F5745525F4F4E5F4D495353494F4E5F434F4D504C45544500417566204D697373696F6E202D20416267657363686C6F7373656E0001, 38134), -- GlobalStrings
(3205218938, 43286, 'deDE', 0x4741525249534F4E5F464F4C4C4F5745525F4D495353494F4E5F434F4D504C4554454400416267657363686C6F7373656E0001, 38134), -- GlobalStrings
(3205218938, 43283, 'deDE', 0x434F56454E414E545F464F4C4C4F5745525F4D495353494F4E5F434F4D504C455445004175662065696E656D204162656E7465756572202D20416267657363686C6F7373656E0001, 38134), -- GlobalStrings
(261693969, 59853, 'deDE', 0xFFFFFFFFFFFFFFFF5465656765706C61756465723A205665726C6F72656E6520536962796C6C650000CDE900007599F633010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F88700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(261693969, 59852, 'deDE', 0xFFFFFFFFFFFFFFFF5465656765706C61756465723A2047756262696E7320756E642054756262696E730000CCE900007499F533010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F78700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(261693969, 59850, 'deDE', 0xFFFFFFFFFFFFFFFF5465656765706C61756465723A2056756C63610000CAE900007299F433010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F78700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(261693969, 59848, 'deDE', 0xFFFFFFFFFFFFFFFF5465656765706C61756465723A205468656F7461720000C8E900007199F333010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F78700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(3776013982, 320740, 'deDE', 0x000000, 38134), -- Spell
(3776013982, 350249, 'deDE', 0x004B72C3BC6D6D742064656E204C61756620646572205A6569742C20776F647572636820457565722054656D706F20756E6420646173204575726572205370696567656C62696C646572202431313039303964206C616E6720756D202473312520657268C3B6687420776972642E0054656D706F20756D202477312520657268C3B668742E20243F2457343E305B5A6569747261746520756D202477342520657268C3B668742E5D5B5D00, 38134), -- Spell
(3776013982, 320914, 'deDE', 0x0057C3A46872656E6420275A656974766572736368696562756E672720616B746976206973742C20657268616C7465742049687220756E642045757265205370696567656C62696C64657220247331252064657320456666656B747320766F6E20275A6569746B72C3BC6D6D756E67272E204E6963687420766F6E202754656D706F72616C65205665727A657272756E6727206F64657220C3A4686E6C696368656E20456666656B74656E20626574726F6666656E2E0057C3A46872656E6420275A656974766572736368696562756E672720616B746976206973742C20657268616C7465742049687220756E642045757265205370696567656C62696C64657220247331252064657320456666656B747320766F6E20275A6569746B72C3BC6D6D756E67272E204E6963687420766F6E202754656D706F72616C65205665727A657272756E6727206F64657220C3A4686E6C696368656E20456666656B74656E20626574726F6666656E2E00, 38134), -- Spell
(3893700160, 169, 'deDE', 0x0F000000E2000000D20000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 168, 'deDE', 0x0E000000E2000000CF0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 167, 'deDE', 0x0D000000DF000000CF0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 166, 'deDE', 0x0C000000DF000000CF0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 165, 'deDE', 0x0B000000DC000000CB0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 164, 'deDE', 0x0A000000DC000000CB0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 163, 'deDE', 0x09000000D8000000C80000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 162, 'deDE', 0x08000000D8000000C80000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 161, 'deDE', 0x07000000D5000000C80000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 160, 'deDE', 0x06000000D2000000C50000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 159, 'deDE', 0x05000000D2000000C20000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 158, 'deDE', 0x04000000CF000000C20000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 157, 'deDE', 0x03000000CB000000BE0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 156, 'deDE', 0x02000000C8000000BB0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 155, 'deDE', 0x0100000000000000B70000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3776013982, 351967, 'deDE', 0x000000, 38134), -- Spell
(3776013982, 340882, 'deDE', 0x00527566742047617362657574656C2C2066616C6C732065722076657273636877756E64656E206F64657220746F74206973742E00527566742047617362657574656C2C2066616C6C732065722076657273636877756E64656E206F64657220746F74206973742E00, 38134), -- Spell
(2340571112, 755, 'deDE', 0xBD000000D51C0000D0040000060000008F1B00000000000000000000, 38134), -- ItemBonusListGroupEntry
(2998606315, 212, 'deDE', 0x0000000005000000803A09000000000000000000, 38134), -- ScheduledInterval
(3359787322, 20659, 'deDE', 0xB3500000, 38134); -- WorldState

INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(4021368146, 4553, 'deDE', 0x46616C6C656E2067656C617373656E6520537479676961000000000000000000D8020000424400000000000000000000000000000000000000, 38134), -- Vignette
(2202435563, 997132, 'deDE', 0x0C370F00240127010000F3170700, 38134), -- QuestPOIPoint
(2202435563, 997131, 'deDE', 0x0B370F00240128010000F2170700, 38134), -- QuestPOIPoint
(2921112328, 464883, 'deDE', 0xF31707003B097E06000001E1E9000001000000871306000000000000000000, 38134), -- QuestPOIBlob
(2921112328, 464882, 'deDE', 0xF21707003B097E06000001E1E9000001000000871306000000000000000000, 38134), -- QuestPOIBlob
(3776013982, 335718, 'deDE', 0x0027537475726D616E67726966662720756E64202745696E73636872656974656E2720676577C3A46872656E20457563682027536368696C64626C6F636B272066C3BC7220247B2473312F313030307D2053656B2E20736F77696520275261636865212720756E642065727A657567656E20247B2433333537333473312F31307D205775742E0000, 38134), -- Spell
(2948698321, 339, 'deDE', 0x6D68C604BDD61274, 38134), -- TactKeyLookup
(2948698321, 278, 'deDE', 0x7CB28F52811F5830, 38134), -- TactKeyLookup
(3776013982, 328547, 'deDE', 0x4E656B726F6C6F72647300537465636B742065696E656E204B6E6F6368656E7374616368656C20696E20646173205A69656C2C2064657220247331205363686164656E20736F77696520616C6C65202433323430373374312053656B2E2024333234303733733120426C7574756E67737363686164656E20766572757273616368742C2062697320646173205A69656C20737469726274206F6465722064656E204B616D7066207665726CC3A47373742E0D0A0D0A57656E6E20646173205A69656C2073746972627420776972642C20776972642031204175666C6164756E67206572737461747465742E0D0A0D0A7C634646464646464646476577C3A4687274203120436F6D626F70756E6B7420706C7573203120776569746572656E2070726F20616B746976656D204B6E6F6368656E7374616368656C2E7C720000, 38134), -- Spell
(1369604944, 2081, 'deDE', 0x000000000000000000000000000000000000000000000000210800006E1C00000000FF2200000000000000002C010000EE0204020000410B0000000000000000002208, 38134), -- SpellVisualMissile
(4033975491, 439153, 'deDE', 0x00000000000000000000000000000000000000000000000071B3060092001500000000000000000000000000000000000000000000000000000000803F00000000FFFFFFFFFFFF00000C000000000000000000000000FF340200, 38134), -- SpellVisualKitModelAttach
(4033975491, 439152, 'deDE', 0x00000000000000000000000000000000000000000000000070B3060092001600000000000000000000000000000000000000000000000000000000803F00000000FFFFFFFFFFFF00000C000000000000000000000000FF340200, 38134), -- SpellVisualKitModelAttach
(1181150530, 377991, 'deDE', 0x050000001ABB020096D20100, 38134), -- SpellVisualKitEffect
(1181150530, 377990, 'deDE', 0x0500000019BB0200F3290200, 38134), -- SpellVisualKitEffect
(1181150530, 377988, 'deDE', 0x0500000019BB020054180200, 38134), -- SpellVisualKitEffect
(1181150530, 377987, 'deDE', 0x0500000018BB020088F60100, 38134), -- SpellVisualKitEffect
(1181150530, 377986, 'deDE', 0x0500000017BB020088F60100, 38134), -- SpellVisualKitEffect
(1181150530, 377985, 'deDE', 0x0500000016BB0200820F0200, 38134), -- SpellVisualKitEffect
(1181150530, 377984, 'deDE', 0x0500000015BB02009FFA0100, 38134), -- SpellVisualKitEffect
(1181150530, 377983, 'deDE', 0x050000006C4E01004B4B0100, 38134), -- SpellVisualKitEffect
(1181150530, 377982, 'deDE', 0x0200000071B30600FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377981, 'deDE', 0x0200000070B30600FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377980, 'deDE', 0x05000000EFCC0100FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377979, 'deDE', 0x06000000B7D20500FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377978, 'deDE', 0x0500000014BB020052F20100, 38134), -- SpellVisualKitEffect
(1181150530, 377977, 'deDE', 0x0500000013BB0200D8030200, 38134), -- SpellVisualKitEffect
(3425193231, 278473, 'deDE', 0x060000000D0000000000000000000000000000000000000002000000494B01001EA30100, 38134), -- SpellVisualEvent
(3425193231, 278472, 'deDE', 0x060000000D0000000000000000000000000000000000000001000000494B01001EA30100, 38134), -- SpellVisualEvent
(3425193231, 278471, 'deDE', 0x030000000D0000000000000000000000000000000000000001000000FF3402001EA30100, 38134), -- SpellVisualEvent
(3425193231, 278470, 'deDE', 0x010000000200000000000000000000000000000000000000010000004A4B01001EA30100, 38134), -- SpellVisualEvent
(859088734, 381623, 'deDE', 0xFFFFFFFF360000000000, 38134), -- SpellVisualAnim
(4146370265, 107294, 'deDE', 0x0000000000000000000000000000000000000000000000000000000000000000FF22000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SpellVisual
(3266400455, 613060, 'deDE', 0x1ABB02002C713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613059, 'deDE', 0x1ABB02002B713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613058, 'deDE', 0x1ABB02002A713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613057, 'deDE', 0x1ABB020029713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613056, 'deDE', 0x1ABB020028713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613055, 'deDE', 0x19BB0200BC6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613054, 'deDE', 0x19BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613053, 'deDE', 0x19BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613052, 'deDE', 0x19BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613051, 'deDE', 0x19BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613050, 'deDE', 0x19BB0200B76A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613049, 'deDE', 0x19BB0200B66A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613043, 'deDE', 0x18BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613042, 'deDE', 0x18BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613041, 'deDE', 0x18BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613040, 'deDE', 0x18BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613039, 'deDE', 0x18BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613038, 'deDE', 0x17BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613037, 'deDE', 0x17BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613036, 'deDE', 0x17BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613035, 'deDE', 0x17BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613034, 'deDE', 0x17BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613033, 'deDE', 0x16BB0200BC6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613032, 'deDE', 0x16BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613031, 'deDE', 0x16BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613030, 'deDE', 0x16BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613029, 'deDE', 0x16BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613028, 'deDE', 0x16BB0200B76A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613027, 'deDE', 0x16BB0200B66A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613018, 'deDE', 0x15BB0200C36A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613017, 'deDE', 0x15BB0200C26A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613016, 'deDE', 0x15BB0200C16A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613015, 'deDE', 0x15BB0200C06A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613014, 'deDE', 0x15BB0200BF6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613013, 'deDE', 0x15BB0200BE6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613012, 'deDE', 0x15BB0200BD6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613011, 'deDE', 0x14BB02004AE21900010000803F, 38134), -- SoundKitEntry
(3266400455, 613010, 'deDE', 0x14BB02004BE21900010000803F, 38134), -- SoundKitEntry
(3266400455, 613009, 'deDE', 0x14BB02004CE21900010000803F, 38134), -- SoundKitEntry
(3266400455, 613008, 'deDE', 0x13BB0200C36A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613007, 'deDE', 0x13BB0200C26A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613006, 'deDE', 0x13BB0200C16A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613005, 'deDE', 0x13BB0200C06A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613004, 'deDE', 0x13BB0200BF6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613003, 'deDE', 0x13BB0200BE6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613002, 'deDE', 0x13BB0200BD6A3500010000803F, 38134), -- SoundKitEntry
(3232102598, 140456, 'deDE', 0xA82402001ABB02000000A040000000410000000000000000000000000000000000000000020000000000000000E8030000E8030000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000F4010000F4010000580C00000000803F010000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140455, 'deDE', 0xA7240200AF6C02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140454, 'deDE', 0xA6240200C06502000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140453, 'deDE', 0xA5240200D07102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140452, 'deDE', 0xA424020019BB02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140451, 'deDE', 0xA3240200020A00000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140450, 'deDE', 0xA224020018BB02000000A040000000410000000000000000000000000000000000000000020000000000000000E8030000E8030000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140449, 'deDE', 0xA124020017BB02000000A040000000410000000000000000000000000000000000000000020000000000000000F4010000F4010000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140448, 'deDE', 0xA02402003E7502000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140447, 'deDE', 0x9F240200447502000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140446, 'deDE', 0x9E24020016BB02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000100FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140445, 'deDE', 0x9D24020015BB02000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140444, 'deDE', 0x9C240200B9710200000040410000C04100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140443, 'deDE', 0x9B240200956C02000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140442, 'deDE', 0x9A240200177202000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140441, 'deDE', 0x99240200F46F02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140440, 'deDE', 0x98240200817202000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140439, 'deDE', 0x97240200557102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140438, 'deDE', 0x96240200ED6602000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140437, 'deDE', 0x952402001E7102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140436, 'deDE', 0x94240200E56602000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140435, 'deDE', 0x9324020014BB02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140434, 'deDE', 0x9224020013BB02000000A040000000410000000000000000000000000000000000000000020000000000000000F4010000F4010000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140433, 'deDE', 0x91240200666C02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140432, 'deDE', 0x90240200267102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123926, 'deDE', 0x16E40100407602000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000002C01000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123714, 'deDE', 0x42E30100437502000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000101F4010000F4010000570C0000E8030000E8030000580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123675, 'deDE', 0x1BE30100457502000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123670, 'deDE', 0x16E301003D7502000000A04000002041000000000000000000000000000000000000000002E6000000E6000000E6000000E6000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123594, 'deDE', 0xCAE20100F17402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123515, 'deDE', 0x7BE20100A27402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000002C01000000000000000000000001C8000000C8000000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123514, 'deDE', 0x7AE20100A17402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000009600000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123504, 'deDE', 0x70E201009F7402000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001401F0000401F0000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123503, 'deDE', 0x6FE201009E7402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000002C010000000000000000000000016400000064000000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123502, 'deDE', 0x6EE201009D7402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000009600000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122935, 'deDE', 0x37E00100507202000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000100FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122901, 'deDE', 0x15E00100167202000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000100FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122891, 'deDE', 0x0BE00100187202000000C0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122821, 'deDE', 0xC5DF0100D1710200000000400000804000000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122814, 'deDE', 0xBEDF0100C87102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122807, 'deDE', 0xB7DF0100C17102000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001BC020000BC020000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122806, 'deDE', 0xB6DF0100C07102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122804, 'deDE', 0xB4DF0100BE7102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000009600000000000000000000000001C8000000C8000000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122709, 'deDE', 0x55DF01004A7102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122629, 'deDE', 0x05DF0100F97002000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B44300000000000000C800000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122404, 'deDE', 0x24DE0100F56F02000000C0400000404100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000B80B0000B80B0000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121643, 'deDE', 0x2BDB0100D76C02000000803F0000004000000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B4430000000000000000000000000000000000000001012C0100002C010000570C0000E8030000E8030000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121613, 'deDE', 0x0DDB0100976C02000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B4430000000000000000000000000000000000000000012C0100002C010000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121609, 'deDE', 0x09DB0100906C02000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000B80B0000B80B0000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121587, 'deDE', 0xF3DA0100686C02000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000E8030000E8030000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 120239, 'deDE', 0xAFD50100E66602000000C040000040410000000000000000000000000000000000000000000000000000000000F4010000F4010000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001E8030000E8030000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 119974, 'deDE', 0xA6D40100D66502000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000002FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 25856, 'deDE', 0x00650000C9E600000000A04000002041000000000000000000000000000000000000000002E6000000E6000000E6000000E6000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(1485693696, 5565, 'deDE', 0x1ABB0200010000000069620000000000000100, 38134); -- SoundEnvelope

