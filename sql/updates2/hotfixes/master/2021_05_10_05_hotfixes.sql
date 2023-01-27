DELETE FROM `broadcast_text_locale` WHERE `locale` = 'frFR' AND `ID` IN (209968, 208581);
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(209968, 'frFR', '', 'Bienvenue, l\’$gami:amie;. Vous vous intéressez aux clés mythiques ?', 38134),
(208581, 'frFR', 'Salutations, UTILISATEUR. J\’espère que vous passez une ADJECTIF POSITIF ALÉATOIRE journée.', '', 38134);

DELETE FROM `item_search_name_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(52489, 'frFR', 'Lunettes de soleil en strass', 38134);

DELETE FROM `currency_types_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `currency_types_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1191, 'frFR', 'Vaillance', 'Une monnaie utilisée pour augmenter la puissance des objets des donjons mythiques.', 38134),
(1602, 'frFR', 'Points de conquête', 'Obtenus lors d\’activités en JcJ coté. Permettent d\’acheter de l\’équipement à Oribos.', 38134),
(1828, 'frFR', 'Cendre d\’âme', 'Source d\’énergie brute trouvée dans Tourment. Sert à alimenter la chambre du Runomancien.', 38134);

DELETE FROM `spell_name_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(328547, 'frFR', 'Pointe d\’os dentelée', 38134),
(335718, 'frFR', 'Représailles', 38134),
(340882, 'frFR', 'Appeler le Ballonné', 38134),
(351967, 'frFR', 'Appeler Bonne-Bouille', 38134),
(320914, 'frFR', 'Sablier de chronomancien', 38134),
(350249, 'frFR', 'Distorsion temporelle', 38134),
(320740, 'frFR', 'Fixer', 38134),
(335161, 'frFR', 'Échappement d\’anima', 38134),
(340433, 'frFR', 'Faveur de Tombe-Vice', 38134),
(220358, 'frFR', 'Frappes du cyclone', 38134),
(352329, 'frFR', '[DNT] Learn Bananas', 38134),
(163708, 'frFR', 'Feu de joie envoûté', 38134),
(34477, 'frFR', 'Détournement', 38134),
(202335, 'frFR', 'Double tonneau', 38134),
(209584, 'frFR', 'Thé de focalisation zen', 38134),
(235219, 'frFR', 'Frimaire', 38134),
(243435, 'frFR', 'Boisson fortifiante', 38134),
(248518, 'frFR', 'Intrusion', 38134),
(321995, 'frFR', 'Présence hypothermique', 38134),
(327193, 'frFR', 'Moment de gloire', 38134),
(352497, 'frFR', '[DNT] Teleport', 38134),
(294587, 'frFR', 'Pointes d\’Obléron x2', 38134),
(294588, 'frFR', 'Pointes d\’Obléron x3', 38134),
(322841, 'frFR', 'Aile-furie', 38134),
(324919, 'frFR', 'Aile-furie', 38134),
(352816, 'frFR', '[DNT] Grant Keystone', 38134),
(341220, 'frFR', 'Arbalète antrelige', 38134),
(321136, 'frFR', 'Lumière rayonnante', 38134),
(255260, 'frFR', 'Marque du chaos', 38134),
(281242, 'frFR', 'Marque du chaos', 38134),
(337541, 'frFR', 'Esprit de la flamme noire', 38134),
(71, 'frFR', 'Avant-garde', 38134),
(48263, 'frFR', 'Vétéran de la troisième guerre', 38134),
(245013, 'frFR', 'Équilibre du brasseur', 38134),
(300346, 'frFR', 'Adepte ursin', 38134),
(316714, 'frFR', 'Vétéran de la troisième guerre', 38134),
(319278, 'frFR', 'Vétéran de la Quatrième guerre', 38134),
(353367, 'frFR', 'Égide de Lumière', 38134),
(337334, 'frFR', 'Paume céleste de Keefer', 38134),
(336061, 'frFR', 'Charge gélatineuse', 38134),
(340271, 'frFR', 'Contagion figée', 38134),
(327332, 'frFR', 'Imprégnation d\’arme', 38134),
(45525, 'frFR', 'Intelligence des Arcanes', 38134),
(354135, 'frFR', 'Bottom Barrier Visual', 38134),
(321828, 'frFR', 'Trois petits chats', 38134),
(321832, 'frFR', 'Balle aux prisonniers', 38134),
(326180, 'frFR', 'Loup glacé', 38134),
(322416, 'frFR', 'Crevasse rocheuse', 38134);

DELETE FROM `criteria_tree_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(91079, 'frFR', 'Login with Bananas license (Charity Pet 2021)', 38134),
(91080, 'frFR', '', 38134),
(91081, 'frFR', 'Earn character-level Bananas achievement', 38134),
(91082, 'frFR', '', 38134),
(91386, 'frFR', 'Ve\'nari reputation is Apprehensive', 38134),
(91388, 'frFR', 'Ve\'nari reputation is Tentative', 38134),
(91390, 'frFR', 'Ve\'nari reputation is Ambivalent', 38134),
(91392, 'frFR', 'Ve\'nari reputation is Cordial', 38134),
(91393, 'frFR', '', 38134),
(91503, 'frFR', 'Do You Have All Rank 1s in a Covenant Sanctum?', 38134),
(91504, 'frFR', 'Login test for backporting of \"do you have all level 1 buildings\"', 38134),
(91505, 'frFR', '', 38134),
(91506, 'frFR', 'Do You Have All Rank 2s in a Covenant Sanctum?', 38134),
(91507, 'frFR', 'Login test for backporting of \"do you have all level 2 buildings\"', 38134),
(91508, 'frFR', '', 38134),
(91509, 'frFR', 'Do You Have All Rank 3s in a Covenant Sanctum?', 38134),
(91510, 'frFR', 'Login test for backporting of \"do you have all level 3 buildings\"', 38134),
(91511, 'frFR', '', 38134),
(91387, 'frFR', 'Ve\’nari vous considère avec crainte', 38134),
(91389, 'frFR', 'Ve\’nari vous considère avec hésitation', 38134),
(91391, 'frFR', 'Ve\’nari vous considère avec incertitude', 38134),
(87404, 'frFR', 'Gagner des matchs de JcJ cotés lors de la saison 1 de Shadowlands en ayant une cote de 1000 ou plus', 38134),
(87408, 'frFR', 'Gagner des matchs de JcJ cotés lors de la saison 1 de Shadowlands en ayant une cote de 1000 ou plus', 38134);

DELETE FROM `specialization_spells_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `specialization_spells_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(5164, 'frFR', '', 38134),
(5369, 'frFR', '', 38134),
(5480, 'frFR', '', 38134),
(6271, 'frFR', '', 38134),
(6285, 'frFR', '', 38134),
(6286, 'frFR', '', 38134),
(6287, 'frFR', '', 38134),
(6288, 'frFR', '', 38134),
(6289, 'frFR', '', 38134),
(6292, 'frFR', '', 38134),
(6293, 'frFR', '', 38134),
(6294, 'frFR', '', 38134),
(6295, 'frFR', '', 38134),
(6298, 'frFR', '', 38134),
(6299, 'frFR', '', 38134),
(6306, 'frFR', '', 38134),
(6377, 'frFR', '', 38134),
(6455, 'frFR', '', 38134),
(6457, 'frFR', '', 38134),
(6463, 'frFR', '', 38134),
(6478, 'frFR', '', 38134),
(6531, 'frFR', '', 38134),
(6532, 'frFR', '', 38134),
(6533, 'frFR', '', 38134),
(6534, 'frFR', '', 38134),
(6535, 'frFR', '', 38134),
(6608, 'frFR', '', 38134),
(5262, 'frFR', '', 38134),
(6609, 'frFR', '', 38134),
(5320, 'frFR', '', 38134),
(5521, 'frFR', '', 38134),
(5580, 'frFR', '', 38134),
(5938, 'frFR', '', 38134),
(6113, 'frFR', '', 38134),
(6114, 'frFR', '', 38134),
(6193, 'frFR', '', 38134),
(6195, 'frFR', '', 38134),
(6324, 'frFR', '', 38134),
(6400, 'frFR', '', 38134),
(6434, 'frFR', '', 38134),
(6447, 'frFR', '', 38134),
(6515, 'frFR', '', 38134),
(6516, 'frFR', '', 38134),
(6610, 'frFR', '', 38134);

DELETE FROM `battlemaster_list_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `battlemaster_list_locale` (`ID`, `locale`, `Name_lang`, `GameType_lang`, `ShortDescription_lang`, `LongDescription_lang`, `VerifiedBuild`) VALUES
(100, 'frFR', 'Champ de bataille coté', '', '', '', 38134),
(866, 'frFR', 'Toutes les arènes', 'Choc', '', '', 38134),
(1047, 'frFR', 'Mugambala', '', '', '', 38134),
(1048, 'frFR', 'Le Robodrome', '', '', '', 38134),
(1049, 'frFR', 'Pointe du Crochet', '', '', '', 38134),
(1050, 'frFR', 'Domaine Empyréen', '', '', '', 38134);

DELETE FROM `area_table_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(12876, 'frFR', 'Siège du Primat', 38134),
(12917, 'frFR', 'Tombe-Vice', 38134),
(12924, 'frFR', 'Sylvarden', 38134),
(13387, 'frFR', 'Sylvarden', 38134),
(6852, 'frFR', 'Ordalie', 38134);

DELETE FROM `char_titles_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `char_titles_locale` (`ID`, `locale`, `Name_lang`, `Name1_lang`, `VerifiedBuild`) VALUES
(679, 'frFR', 'Baron %s', 'Baron %s', 38134),
(680, 'frFR', 'Baronne %s', 'Baronne %s', 38134),
(682, 'frFR', 'Comte %s', 'Comte %s', 38134),
(683, 'frFR', 'Comtesse %s', 'Comtesse %s', 38134);

DELETE FROM `item_sparse_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(52489, 'frFR', '', '', '', '', 'Lunettes de soleil en strass', 38134),
(180317, 'frFR', '', '', '', '', 'Potion de soins méditative', 38134),
(180318, 'frFR', '', '', '', '', 'Potion de mana méditative', 38134),
(155622, 'frFR', '', '', '', '', 'Trophée du chef de guerre', 38134),
(159570, 'frFR', '', '', '', '', 'Cachet du champ d\’honneur', 38134),
(164580, 'frFR', '', '', '', '', 'Cachet du champ d\’honneur', 38134),
(164581, 'frFR', '', '', '', '', 'Cachet du champ d\’honneur', 38134),
(164582, 'frFR', '', '', '', '', 'Cachet du champ d\’honneur', 38134),
(164583, 'frFR', '', '', '', '', 'Cachet du champ d\’honneur', 38134),
(164584, 'frFR', '', '', '', '', 'Trophée du chef de guerre', 38134),
(164585, 'frFR', '', '', '', '', 'Trophée du chef de guerre', 38134),
(164586, 'frFR', '', '', '', '', 'Trophée du chef de guerre', 38134),
(164587, 'frFR', '', '', '', '', 'Trophée du chef de guerre', 38134),
(164950, 'frFR', '', '', '', '', 'Trophée du chef de guerre', 38134),
(164951, 'frFR', '', '', '', '', 'Cachet du champ d\’honneur', 38134),
(164952, 'frFR', '', '', '', '', 'Cachet du champ d\’honneur', 38134),
(164953, 'frFR', '', '', '', '', 'Cachet du champ d\’honneur', 38134),
(164954, 'frFR', '', '', '', '', 'Cachet du champ d\’honneur', 38134),
(164955, 'frFR', '', '', '', '', 'Cachet du champ d\’honneur', 38134),
(164956, 'frFR', '', '', '', '', 'Trophée du chef de guerre', 38134),
(164957, 'frFR', '', '', '', '', 'Trophée du chef de guerre', 38134),
(164958, 'frFR', '', '', '', '', 'Trophée du chef de guerre', 38134),
(164959, 'frFR', '', '', '', '', 'Trophée du chef de guerre', 38134),
(168316, 'frFR', '', '', '', '', 'Cachet du champ d\’honneur', 38134),
(171090, 'frFR', '', '', '', '', 'Cachet du champ d\’honneur', 38134),
(171091, 'frFR', '', '', '', '', 'Cachet du champ d\’honneur', 38134),
(171092, 'frFR', '', '', '', '', 'Cachet du champ d\’honneur', 38134),
(171093, 'frFR', '', '', '', '', 'Cachet du champ d\’honneur', 38134),
(171095, 'frFR', '', '', '', '', 'Trophée du chef de guerre', 38134),
(171096, 'frFR', '', '', '', '', 'Trophée du chef de guerre', 38134),
(171097, 'frFR', '', '', '', '', 'Trophée du chef de guerre', 38134),
(171098, 'frFR', '', '', '', '', 'Trophée du chef de guerre', 38134),
(171099, 'frFR', '', '', '', '', 'Trophée du chef de guerre', 38134),
(172890, 'frFR', '', '', '', '', 'Cachet du champ d\’honneur', 38134),
(172891, 'frFR', '', '', '', '', 'Cachet du champ d\’honneur', 38134),
(172892, 'frFR', '', '', '', '', 'Cachet du champ d\’honneur', 38134),
(172893, 'frFR', '', '', '', '', 'Cachet du champ d\’honneur', 38134),
(172894, 'frFR', '', '', '', '', 'Cachet du champ d\’honneur', 38134),
(172895, 'frFR', '', '', '', '', 'Trophée du chef de guerre', 38134),
(172896, 'frFR', '', '', '', '', 'Trophée du chef de guerre', 38134),
(172897, 'frFR', '', '', '', '', 'Trophée du chef de guerre', 38134),
(172898, 'frFR', '', '', '', '', 'Trophée du chef de guerre', 38134),
(172899, 'frFR', '', '', '', '', 'Trophée du chef de guerre', 38134),
(186099, 'frFR', 'Ce gadget ouvre sur votre équipement une faille spatiale miniature dont la forme est parfaitement adaptée à l\’insertion d\’une gemme.', '', '', '', 'Appareil de réalignement spatial', 38134),
(183122, 'frFR', '', '', '', '', 'Cape de la mort', 38134),
(183131, 'frFR', '', '', '', '', 'Grappin stygique', 38134),
(183135, 'frFR', '', '', '', '', 'Invocation des défunts', 38134),
(183136, 'frFR', '', '', '', '', 'Rat de l\’Antre incendiaire', 38134),
(183141, 'frFR', '', '', '', '', 'Magma stygique', 38134),
(183165, 'frFR', '', '', '', '', 'Arbalète antrelige', 38134),
(183187, 'frFR', '', '', '', '', 'Incantation tissombre', 38134),
(174876, 'frFR', '', '', '', '', 'Œil arraché à N\’Zoth', 38134),
(187116, 'frFR', '', '', '', '', 'Leurre', 38134);

DELETE FROM `map_difficulty_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `map_difficulty_locale` (`ID`, `locale`, `Message_lang`, `VerifiedBuild`) VALUES
(4775, 'frFR', '', 38134);

DELETE FROM `mount_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `mount_locale` (`ID`, `locale`, `Name_lang`, `SourceText_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1458, 'frFR', 'Ancien vagabond', '|cFFFFD200Promotion|r', 'Fervents défenseurs des forêts d\’Azeroth, les anciens sont réputés pour leurs canopées luxuriantes dont la couleur change au gré des saisons.', 38134);

DELETE FROM `player_condition_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(90553, 'frFR', '', 38134),
(90651, 'frFR', '', 38134),
(90652, 'frFR', '', 38134),
(78581, 'frFR', '', 38134),
(87399, 'frFR', 'Ve\’nari doit vous considérer avec approbation ou avoir une plus haute opinion de vous.', 38134);

DELETE FROM `achievement_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(15010, 'frFR', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Apprehensive standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Apprehensive [DNT]', '', 38134),
(15011, 'frFR', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Tentative standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Tentative [DNT]', '', 38134),
(15012, 'frFR', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Ambivalent standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Ambivalent [DNT]', '', 38134),
(15013, 'frFR', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Cordial standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Cordial [DNT]', '', 38134),
(14340, 'frFR', 'Vaincre 1 boss sur la voie de l\’Ascension.', 'La voie vers l\’Ascension 1', 'Débloquer de nouveaux défis sur la voie de l\’Ascension.', 38134),
(14342, 'frFR', 'Vaincre trois boss sur la voie de l\’Ascension.', 'La voie vers l\’Ascension 3', 'Débloquer de nouveaux défis sur la voie de l\’Ascension.', 38134),
(14343, 'frFR', 'Vaincre cinq boss sur la voie de l\’Ascension.', 'La voie vers l\’Ascension 5', 'Débloquer de nouveaux défis sur la voie de l\’Ascension.', 38134),
(14344, 'frFR', 'Vaincre sept boss sur la voie de l\’Ascension.', 'La voie vers l\’Ascension 7', 'Débloquer de nouveaux défis sur la voie de l\’Ascension.', 38134),
(14345, 'frFR', 'Vaincre 12 boss sur la voie de l\’Ascension.', 'La voie vers l\’Ascension 12', 'Débloquer de nouveaux défis sur la voie de l\’Ascension.', 38134),
(14346, 'frFR', 'Vaincre 16 boss sur la voie de l\’Ascension.', 'La voie vers l\’Ascension 16', 'Débloquer de nouveaux défis sur la voie de l\’Ascension.', 38134),
(14348, 'frFR', 'Vaincre 20 boss sur la voie de l\’Ascension.', 'La voie vers l\’Ascension 20', 'Débloquer de nouveaux défis sur la voie de l\’Ascension.', 38134),
(14349, 'frFR', 'Vaincre 24 boss sur la voie de l\’Ascension.', 'La voie vers l\’Ascension 24', 'Débloquer de nouveaux défis sur la voie de l\’Ascension.', 38134),
(14351, 'frFR', 'Vaincre 39 boss sur la voie de l\’Ascension.', 'La voie vers l\’Ascension 39', 'Débloquer de nouveaux défis sur la voie de l\’Ascension.', 38134),
(14502, 'frFR', 'Surmonter les huit premières épreuves de la loyauté.', 'En quête de loyauté', '', 38134),
(14633, 'frFR', 'Débloquer le rang III du réseau de transport de votre sanctum.', 'Maître navigateur', '', 38134),
(14636, 'frFR', 'Débloquer le rang III de la table de commandement des aventures de votre sanctum.', 'Aventurier en chef', '', 38134),
(14637, 'frFR', 'Débloquer le rang V de la fonctionnalité spéciale de votre sanctum.', 'Spécialité de votre congrégation', '', 38134),
(14638, 'frFR', 'Débloquer tous les emplacements reliés à votre conducteur d\’anima.', 'Que l\’anima coule à flots !', '', 38134),
(14639, 'frFR', 'Utiliser votre conducteur d\’anima à 50 reprises.', 'Priorité à la restauration', '', 38134),
(14670, 'frFR', 'Incuber chaque type d\’esprit au moins une fois dans le jardin d\’hiver de la Reine.', 'À votre santé', '', 38134),
(14675, 'frFR', 'Incuber chaque type d\’esprit supérieur au moins une fois dans le jardin d\’hiver de la Reine.', '$GLe:La; Sans-Entraves qui murmurait à l\’oreille des esprits', '', 38134),
(14676, 'frFR', 'Incuber chaque type d\’esprit divin au moins une fois dans le jardin d\’hiver de la Reine.', 'Il faut sauver les esprits divins', '', 38134),
(14677, 'frFR', 'Terminer toutes les quêtes d\’observation des esprits de Falir dans le jardin d\’hiver de la reine.', 'Observations spirituelles', '', 38134),
(14678, 'frFR', 'Déverrouiller les cadeaux suivants pour votre réception de la cour des Braises.', 'Cadeaux de la cour', '', 38134),
(14679, 'frFR', 'Déverrouiller les améliorations suivantes pour votre réception de la cour des Braises.', 'C\’est la fête au palais', '', 38134),
(14680, 'frFR', 'Déverrouiller les services suivants pour votre réception de la cour des Braises.', 'Il y en a pour tous les goûts', '', 38134),
(14681, 'frFR', 'Former votre majordome purotin aux arts suivants à la cour des Braises.', 'Purotins Academy', '', 38134),
(14682, 'frFR', 'Accomplir les hauts faits de la cour des Braises listés ci-dessous.', 'Le héraut des festivités', 'Titre : Héraut des festivités', 38134),
(14683, 'frFR', 'Déverrouiller les options d\’apparence suivantes pour votre purotin de la cour des Braises.', 'À la mode purotine', '', 38134),
(14684, 'frFR', 'Accomplir les quêtes de Suture abominable suivantes', 'Vies abominables', '', 38134),
(14723, 'frFR', 'Accueillir les invités suivants à votre réception de la cour des Braises.', 'Invités d\’honneur', '', 38134),
(14724, 'frFR', 'Aider les invités suivants à atteindre l\’humeur Ravie lors d\’une réception de la cour des Braises.', 'Aux petits soins', '', 38134),
(14725, 'frFR', 'Organiser une réception de la cour des Braises avec quatre invités Ravis.', 'Au comble du bonheur', '', 38134),
(14726, 'frFR', 'Organiser des réceptions de la cour des Braises avec les attributs suivants à des niveaux élevés.', 'On ne s\’ennuie jamais', '', 38134),
(14727, 'frFR', 'Terminer 10 événements au cours d\’une seule réception de la cour des Braises.', 'Maître des cérémonies', '', 38134),
(14748, 'frFR', 'Fabriquer 25 des accessoires de mode suivants avec Suture abominable.', 'Garde-robe tendance', '', 38134),
(14749, 'frFR', 'Aider Rondel à trouver les chapeaux suivants à porter à la cour des Braises.', 'Le grand jour de Rondel', '', 38134),
(14751, 'frFR', 'Construire chacun des assemblages suivants avec Suture abominable.', 'Équipe au complet', 'Récompense : monture tauralus élu', 38134),
(14752, 'frFR', 'Accomplir les hauts faits de Suture abominable listés ci-dessous.', 'S\’occuper quand on est mort', 'Titre : abominable - Récompense : monture tauralus élu cuirassé', 38134),
(14753, 'frFR', 'Donner 100 bandelettes d\’anima à l\’invocateur Gérard pour aider à invoquer le spectre de guerre Visectus.', 'Pourvoyeur de bandelettes', '', 38134),
(14764, 'frFR', 'Avec l\’aide de Cordier, obtenir le grigri supérieur.', 'Le grigri supérieur', '', 38134),
(14775, 'frFR', 'Être exalté auprès de Marasmius.', 'Fongiquement vôtre', 'Titre : le/la fongique', 38134),
(14777, 'frFR', 'Mettre à niveau toutes vos fonctionnalités du sanctum de la congrégation.', 'Expert en restauration', '', 38134),
(14780, 'frFR', 'Terminer toutes les quêtes de méditation d\’Ohm dans le jardin d\’hiver de la reine et communier avec votre paix intérieure.', 'Maître de la méditation', '', 38134),
(14789, 'frFR', 'Terminer la suite de quêtes de Lia pour restaurer tous les esprits animaux du jardin d\’hiver de la Reine.', 'Une vue des esprits', '', 38134),
(14833, 'frFR', 'Fabriquer chacun des accessoires de mode suivants avec Suture abominable.', 'Abomination à la mode', '', 38134),
(14839, 'frFR', 'Faire progresser 3 âmes liées jusqu\’au niveau 60 dans les aventures.', 'Les liens de l\’aventure', '', 38134),
(14840, 'frFR', 'Faire progresser un aventurier jusqu\’au niveau 20.', 'Aventures : Apprendre les ficelles', '', 38134),
(14841, 'frFR', 'Faire progresser un aventurier jusqu\’au niveau 40.', 'Aventures : Il y a du progrès', '', 38134),
(14842, 'frFR', 'Faire progresser un aventurier jusqu\’au niveau 60.', 'Aventures : Force et résilience', '', 38134),
(14843, 'frFR', 'Obtenir les 12 aventuriers de votre congrégation.', 'Aventures : Harmonie du Dessein', '', 38134),
(14844, 'frFR', 'Terminer les aventures de l\’Antre suivantes.', 'Aventures : Premier pas', '', 38134),
(14845, 'frFR', 'Terminer une aventure.', 'Aventures : Un pas dans la bonne direction', '', 38134),
(14846, 'frFR', 'Terminer 10 aventures.', 'Aventures : Comme des feuilles dans la forêt', '', 38134),
(14847, 'frFR', 'Terminer 100 aventures.', 'Aventures : Défenseur de l\’Ombreterre', '', 38134),
(14851, 'frFR', 'Vaincre Kalisthène et Corinth le Pleutre en utilisant l\’égide forgée par l\’esprit.', 'Bastion de protection', '', 38134),
(14852, 'frFR', 'Vaincre Alderyn et Myn\’ir, et le cauchemar brise-écorce, dans une épreuve de la loyauté en tant que Mikanikos.', 'Ça hulule dans les brancards', '', 38134),
(14853, 'frFR', 'Vaincre Mortimer le Dément après avoir été affecté par Veines ardentes, Gelé et Vomissement incontrôlable.', 'Poussée de fièvre', '', 38134),
(14854, 'frFR', 'Surmonter une épreuve de loyauté en utilisant chaque pièce d\’équipement d\’âme liée.', 'L\’habit ne fait pas le moine', '', 38134),
(14856, 'frFR', 'Surmonter une épreuve de la sagesse en vous équipant des 5 charmes.', 'Du charme à revendre', '', 38134),
(14857, 'frFR', 'Vaincre Echthra dans une épreuve de la sagesse après avoir tué 20 rampants.', 'Combattants miniatures', '', 38134),
(14858, 'frFR', 'Vaincre Corinth le Pleutre dans une épreuve de la sagesse après qu\’il a consommé 2 orbes d\’anima.', 'Malédiction de soif intarissable', '', 38134),
(14859, 'frFR', 'Vaincre Athanos dans une épreuve de la sagesse après avoir survécu à 5 horions puissants.', 'Sagesse brutale', '', 38134),
(14860, 'frFR', 'Surmonter une épreuve de la sagesse sans le moindre équipement d\’âme liée.', 'Minimum vital', '', 38134),
(14861, 'frFR', 'Vaincre Kalisthène et Athanos dans une épreuve de la sagesse avec Pélagos, Kléia et Mikanikos.', 'Enseignements des maîtres', '', 38134),
(14862, 'frFR', 'Surmonter une épreuve de l\’humilité en utilisant chaque pièce d\’équipement d\’âme liée.', 'Élégance ombreterrienne', '', 38134),
(14863, 'frFR', 'Vaincre Thran\’tiok lors d\’une épreuve de la sagesse sans lui infliger de dégâts avant d\’avoir détruit tous les phylactères.', 'Désaveu de la mort', '', 38134),
(14864, 'frFR', 'Vaincre Azaruux dans une épreuve de la sagesse en tant que Pélagos sans affronter le moindre souvenir.', 'Cauchemar personnel', '', 38134),
(14865, 'frFR', 'Surmonter les 10 épreuves de l\’humilité avec Pélagos, Kléia et Mikanikos.', 'Disciple de l\’humilité', '', 38134),
(14866, 'frFR', 'Surmonter les 10 épreuves de l\’humilité sans charme ni brasero actif.', 'Maître de la voie', '', 38134),
(14887, 'frFR', 'Saluer Athanos de la main après son propre salut.', 'Objectif Lune', '', 38134),
(15023, 'frFR', 'Débloquer le rang I des améliorations des quatre congrégations.', 'Reconstruction', 'Débloque : récompenses en anima accrues', 38134),
(15024, 'frFR', 'Débloquer le rang II des améliorations des quatre congrégations.', 'Pénurie palliée', 'Débloque : récompenses en anima accrues', 38134),
(15025, 'frFR', 'Débloquer le rang III des améliorations des quatre congrégations.', 'Supériorité des sanctums', 'Débloque : récompenses en anima accrues', 38134);


DELETE FROM `hotfix_blob` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(13330255, 89547, 'frFR', 0xFB1E0200ECDA0200, 38134), -- ItemXItemEffect
(3865974254, 187116, 'frFR', 0xECDA020000000000, 38134), -- ModifiedReagentItem
(3205218938, 34395, 'frFR', 0x4C4F47494E5F504152454E54414C434F4E54524F4C004CE28099616363C3A87320C3A020636520636F6D707465206573742061637475656C6C656D656E7420626C6F7175C3A920706172206C6520636F6E7472C3B46C6520706172656E74616C2E204C65732072C3A9676C6167657320646520766F74726520636F6D7074652070657576656E7420C3AA747265206D6F64696669C3A97320656E206C69676E652073757220766F74726520706167652064652047657374696F6E20646520636F6D7074652E0002, 38134), -- GlobalStrings
(3205218938, 33881, 'frFR', 0x424E45545F4552524F525F3131004CE28099616363C3A87320C3A020636520636F6D707465206573742061637475656C6C656D656E7420626C6F7175C3A920706172206C6520636F6E7472C3B46C6520706172656E74616C2E204C65732072C3A9676C6167657320646520766F74726520636F6D7074652070657576656E7420C3AA747265206D6F64696669C3A97320656E206C69676E652073757220766F74726520706167652064652047657374696F6E20646520636F6D7074652E0002, 38134), -- GlobalStrings
(3205218938, 33838, 'frFR', 0x415554485F504152454E54414C5F434F4E54524F4C004CE28099616363C3A87320C3A020636520636F6D707465206573742061637475656C6C656D656E7420626C6F7175C3A920706172206C6520636F6E7472C3B46C6520706172656E74616C2E204C65732072C3A9676C6167657320646520766F74726520636F6D7074652070657576656E7420C3AA747265206D6F64696669C3A97320656E206C69676E652073757220766F74726520706167652064652047657374696F6E20646520636F6D7074652E0002, 38134), -- GlobalStrings
(1754233351, 4164, 'frFR', 0x69ED040011C2B8323FF3665F3F00004843000048430000000000000000000000000000000000000000000000000000803F0000803F0000A040, 38134), -- SpellMissile
(240389885, 5745, 'frFR', 0x005238383800000000020202020000000001000000080000000A0000000C00000000000000000000000000000000000000, 38134), -- UnitCondition
(3776013982, 322416, 'frFR', 0x004C65206C616E6365757220666169742073757267697220736F7573206C657320656E6E656D69732070726F63686573206465732063726576617373657320726F636865757365732071756920696E666C6967656E7420243332323431387331C2A0706F696E74732064652064C3A967C3A2747320706879736971756573206574206C65732070726F6A657474656E742064616E73206C657320616972732E0000, 38134), -- Spell
(3865974254, 174876, 'frFR', 0x1CAB020000000000, 38134), -- ModifiedReagentItem
(3776013982, 326180, 'frFR', 0x0024407370656C6C646573633332313837330D0A0000, 38134), -- Spell
(3776013982, 321832, 'frFR', 0x0024407370656C6C646573633331303430360D0A0000, 38134), -- Spell
(3776013982, 321828, 'frFR', 0x004D616E64656272756D65206661697420756E65207061727469652064652024407370656C6C6E616D65333231383238206176656320756E20656E6E656D692C2063652071756920696E666C69676520247331C2A0706F696E74732064652064C3A967C3A27473206465204E617475726520C3A0206C61206369626C65206574206C6120706C6F6E67652064616E73206C6120636F6E667573696F6E2070656E64616E742024642E20436520736F7274207065757420C3AA74726520696E746572726F6D707520706172206C61206369626C652E00456E20706C65696E6520636F6E667573696F6E2E00, 38134), -- Spell
(2640972154, 324, 'frFR', 0x436F757220646573204272616973657300440100006F00000000000000050000000001000000000000000500000002000000, 38134), -- GarrTalentTree
(2640972154, 321, 'frFR', 0x466162726971756520C3A02041626F6D696E6174696F6E7300410100006F00000000000000050000000000000000000000000500000004000000, 38134), -- GarrTalentTree
(2640972154, 320, 'frFR', 0x566F6965206465206CE28099417363656E73696F6E00400100006F00000000000000050000A31400000000000000000500000001000000, 38134), -- GarrTalentTree
(2640972154, 319, 'frFR', 0x4A617264696E2064E280996869766572206465206C61205265696E65003F0100006F00000000000000050000000000000000000000000500000003000000, 38134), -- GarrTalentTree
(4033975491, 441527, 'frFR', 0x00000000666646C000005040000000000000000000000000B7BC06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000000000000FA390200, 38134), -- SpellVisualKitModelAttach
(4033975491, 441526, 'frFR', 0x000000006666464000005040000000000000000000000000B6BC06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000000000000FA390200, 38134), -- SpellVisualKitModelAttach
(4033975491, 441525, 'frFR', 0x000000000000000000005040000000000000000000000000B5BC06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000000000000FA390200, 38134), -- SpellVisualKitModelAttach
(4033975491, 429002, 'frFR', 0x00000000666646C000003040000000000000000000000000CA8B06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF00000000000000000000000000000009210200, 38134), -- SpellVisualKitModelAttach
(4033975491, 429001, 'frFR', 0x000000006666464000003040000000000000000000000000C98B06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF00000000000000000000000000000009210200, 38134), -- SpellVisualKitModelAttach
(4033975491, 429000, 'frFR', 0x000000000000000000003040000000000000000000000000C88B06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF00000000000000000000000000000009210200, 38134), -- SpellVisualKitModelAttach
(1181150530, 381714, 'frFR', 0x02000000B7BC0600FA390200, 38134), -- SpellVisualKitEffect
(1181150530, 381713, 'frFR', 0x02000000B6BC0600FA390200, 38134), -- SpellVisualKitEffect
(1181150530, 381712, 'frFR', 0x02000000B5BC0600FA390200, 38134), -- SpellVisualKitEffect
(3425193231, 280125, 'frFR', 0x090000000A0000000000000000000000000000000000000003000000FA39020075A60100, 38134), -- SpellVisualEvent
(4146370265, 108149, 'frFR', 0x0000000000000000000000000000000000000000000000000000000000000000FF22000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SpellVisual
(3776013982, 354135, 'frFR', 0x000000, 38134), -- Spell
(2939349194, 723, 'frFR', 0x426F737320686F727320696E7374616E63652028536861646F776C616E64732900426F737320686F727320696E7374616E636500030000002301000000008C4E0100AE08000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 722, 'frFR', 0x4368C3A274656175204E617468726961202868C3A9726FC3AF717565290048C3A9726FC3AF7175650003020B0123000000D7008C4E0100F8080F00001E0000000000, 38134), -- GroupFinderActivity
(2939349194, 721, 'frFR', 0x4368C3A274656175204E61746872696120286D7974686971756529004D797468697175650003030B0123000000E6008C4E0100F808100000140000000000, 38134), -- GroupFinderActivity
(2939349194, 720, 'frFR', 0x4368C3A274656175204E61746872696120286E6F726D616C29004E6F726D616C0003010B0123000000C8008C4E0100F8080E00001E0000000000, 38134), -- GroupFinderActivity
(2939349194, 719, 'frFR', 0x5468C3A9C3A2747265206465206C6120536F75666672616E6365202868C3A9726FC3AF717565290048C3A9726FC3AF7175650002010A016300000073008C4E0100F508020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 718, 'frFR', 0x5468C3A9C3A2747265206465206C6120536F75666672616E636520286D7974686971756529004D797468697175650002010A016300000073008C4E0100F508170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 717, 'frFR', 0x5468C3A9C3A2747265206465206C6120536F75666672616E63652028636CC3A9206D7974686971756529004D79746869717565202B0002010A01C300000073008C4E0100F508080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 716, 'frFR', 0x5468C3A9C3A2747265206465206C6120536F75666672616E636520286E6F726D616C29004E6F726D616C0002010A016300000000008C4E0100F508010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 715, 'frFR', 0x53696C6C616765206EC3A963726F7469717565202868C3A9726FC3AF717565290048C3A9726FC3AF71756500020109016300000073008C4E0100EE08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 714, 'frFR', 0x53696C6C616765206EC3A963726F746971756520286D7974686971756529004D7974686971756500020109016300000073008C4E0100EE08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 713, 'frFR', 0x53696C6C616765206EC3A963726F74697175652028636CC3A9206D7974686971756529004D79746869717565202B0002010901C300000073008C4E0100EE08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 712, 'frFR', 0x53696C6C616765206EC3A963726F746971756520286E6F726D616C29004E6F726D616C00020109016300000000008C4E0100EE08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 711, 'frFR', 0x466CC3A863686573206465206CE28099417363656E73696F6E202868C3A9726FC3AF717565290048C3A9726FC3AF71756500020108016300000073008C4E0100ED08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 710, 'frFR', 0x466CC3A863686573206465206CE28099417363656E73696F6E20286D7974686971756529004D7974686971756500020108016300000073008C4E0100ED08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 709, 'frFR', 0x466CC3A863686573206465206CE28099417363656E73696F6E2028636CC3A9206D7974686971756529004D79746869717565202B0002010801C300000073008C4E0100ED08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 708, 'frFR', 0x466CC3A863686573206465206CE28099417363656E73696F6E20286E6F726D616C29004E6F726D616C00020108016300000000008C4E0100ED08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 707, 'frFR', 0x50726F666F6E64657572732053616E6775696E6573202868C3A9726FC3AF717565290048C3A9726FC3AF71756500020107016300000073008C4E0100EC08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 706, 'frFR', 0x50726F666F6E64657572732053616E6775696E657320286D7974686971756529004D7974686971756500020107016300000073008C4E0100EC08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 705, 'frFR', 0x50726F666F6E64657572732053616E6775696E65732028636CC3A9206D7974686971756529004D79746869717565202B0002010701C300000073008C4E0100EC08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 704, 'frFR', 0x50726F666F6E64657572732053616E6775696E657320286E6F726D616C29004E6F726D616C00020107016300000000008C4E0100EC08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 703, 'frFR', 0x4272756D6573206465205469726E61205363697468652028636CC3A9206D7974686971756529004D79746869717565202B0002010601C300000073008C4E0100F208080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 702, 'frFR', 0x4272756D6573206465205469726E612053636974686520286D7974686971756529004D7974686971756500020106016300000073008C4E0100F208170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 701, 'frFR', 0x4272756D6573206465205469726E6120536369746865202868C3A9726FC3AF717565290048C3A9726FC3AF71756500020106016300000073008C4E0100F208020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 700, 'frFR', 0x4272756D6573206465205469726E612053636974686520286E6F726D616C29004E6F726D616C00020106016300000000008C4E0100F208010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 699, 'frFR', 0x53616C6C6573206465206CE28099457870696174696F6E2028636CC3A9206D7974686971756529004D79746869717565202B0002010501C300000073008C4E0100EF08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 698, 'frFR', 0x53616C6C6573206465206CE28099457870696174696F6E20286D7974686971756529004D7974686971756500020105016300000073008C4E0100EF08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 697, 'frFR', 0x53616C6C6573206465206CE28099457870696174696F6E202868C3A9726FC3AF717565290048C3A9726FC3AF71756500020105016300000073008C4E0100EF08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 696, 'frFR', 0x53616C6C6573206465206CE28099457870696174696F6E20286E6F726D616C29004E6F726D616C00020105016300000000008C4E0100EF08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 695, 'frFR', 0x4CE2809941757472652063C3B474C3A92028636CC3A9206D7974686971756529004D79746869717565202B0002010401C300000073008C4E0100F308080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 694, 'frFR', 0x4CE2809941757472652063C3B474C3A920286D7974686971756529004D7974686971756500020104016300000073008C4E0100F308170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 693, 'frFR', 0x4CE2809941757472652063C3B474C3A9202868C3A9726FC3AF717565290048C3A9726FC3AF71756500020104016300000073008C4E0100F308020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 692, 'frFR', 0x4CE2809941757472652063C3B474C3A920286E6F726D616C29004E6F726D616C00020104016300000000008C4E0100F308010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 691, 'frFR', 0x4D616C6570657374652028636CC3A9206D7974686971756529004D79746869717565202B0002010301C300000073008C4E0100F108080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 690, 'frFR', 0x4D616C65706573746520286D7974686971756529004D7974686971756500020103016300000073008C4E0100F108170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 689, 'frFR', 0x4D616C657065737465202868C3A9726FC3AF717565290048C3A9726FC3AF71756500020103016300000073008C4E0100F108020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 688, 'frFR', 0x4D616C65706573746520286E6F726D616C29004E6F726D616C00020103016300000000008C4E0100F108010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 657, 'frFR', 0x426F737320686F727320696E7374616E63652028426174746C6520666F7220417A65726F74682900426F737320686F727320696E7374616E63650003000000230100000000BF5300000000000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 498, 'frFR', 0x446F6E6A6F6E20616CC3A961746F69726520646520426174746C6520666F7220417A65726F7468202868C3A9726FC3AF717565290048C3A9726FC3AF7175650002028800620000003A00BF5300006A06020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 497, 'frFR', 0x446F6E6A6F6E20616CC3A961746F69726520646520426174746C6520666F7220417A65726F746820286E6F726D616C29004E6F726D616C0002008800620000000000BF5300006A06010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 458, 'frFR', 0x426F737320686F727320696E7374616E636520284C6567696F6E2900426F737320686F727320696E7374616E63650003000000230100000000BF530000C404000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 418, 'frFR', 0x446F6E6A6F6E20616CC3A961746F697265206465204C6567696F6E202868C3A9726FC3AF717565290048C3A9726FC3AF7175650002026F00620000003200BF530000C404020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 417, 'frFR', 0x446F6E6A6F6E20616CC3A961746F697265206465204C6567696F6E20286E6F726D616C29004E6F726D616C0002006F00620000000000BF530000C404010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 398, 'frFR', 0x426F737320686F727320696E7374616E63652028447261656E6F722900426F737320686F727320696E7374616E63650003000000230100000000BF5300005C04000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 397, 'frFR', 0x426F737320686F727320696E7374616E6365202850616E64617269652900426F737320686F727320696E7374616E63650003000000230100000000BF5300006603000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 396, 'frFR', 0x446F6E6A6F6E20616CC3A961746F697265206465205761726C6F726473202868C3A9726FC3AF717565290048C3A9726FC3AF7175650002006D00620000000000BF5300005C04020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 395, 'frFR', 0x446F6E6A6F6E20616CC3A961746F697265206465205761726C6F72647320286E6F726D616C29004E6F726D616C0002006D00620000000000BF5300005C04010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 364, 'frFR', 0x446F6E6A6F6E20616CC3A961746F6972652064652050616E6461726965202868C3A9726FC3AF717565290048C3A9726FC3AF7175650002005400620000000000BF5300006603020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 363, 'frFR', 0x446F6E6A6F6E20616CC3A961746F6972652064652050616E646172696520286E6F726D616C29004E6F726D616C0002005400620000000000BF5300006603010000050100000000, 38134), -- GroupFinderActivity
(3776013982, 45525, 'frFR', 0x004175676D656E7465206C27496E74656C6C6967656E6365206427756E20616C6C69C3A920646520247331252070656E64616E742024642E00496E74656C6C6967656E6365206175676D656E74C3A96520646520247331252E00, 38134), -- Spell
(3776013982, 327332, 'frFR', 0x004C65206C616E6365757220696D7072C3A8676E65207365732061726D65732064E28099616E696D612E204C65732035C2A070726F636861696E657320617474617175657320706F7274C3A9657320617520636F757273206465732024642073756976616E74657320696E666C6967656E74206465732064C3A967C3A274732064657320417263616E657320737570706CC3A96D656E7461697265732E004C657320617474617175657320706F7274C3A96573206176656320756E652061726D6520696E666C6967656E7420243332373333317331C2A0706F696E74732064652064C3A967C3A274732064657320417263616E657320737570706CC3A96D656E7461697265732E00, 38134), -- Spell
(3776013982, 340271, 'frFR', 0x0052C3A9647569742064652024333430323733733125206C65732064C3A967C3A2747320737562697320706172206C657320616C6C69C3A97320C3A0206D6F696E73206465203135C2A06DC3A8747265732E0044C3A967C3A2747320737562697320706172206C657320616C6C69C3A97320C3A0206D6F696E73206465203135C2A06DC3A8747265732072C3A9647569747320646520243334303237337331252E00, 38134), -- Spell
(3776013982, 336061, 'frFR', 0x000000, 38134), -- Spell
(603412935, 28771, 'frFR', 0xE4B8ADE59BBDE9AB98E5B182E4BABAE4BA8BE58F98E58AA80004, 38134), -- ChatProfanity
(603412935, 28770, 'frFR', 0xE4B8ADE59BBDE9AB98E5B182E69D83E58A9BE69697E4BA890004, 38134), -- ChatProfanity
(603412935, 28769, 'frFR', 0xE4B8ADE59BBDE5AE98E59CBAE68385E69D80E6A1880004, 38134), -- ChatProfanity
(603412935, 28768, 'frFR', 0xE69CB1E6BAB6E59FBA0004, 38134), -- ChatProfanity
(603412935, 28767, 'frFR', 0xE69CB1E6BAB6E9B8A10004, 38134), -- ChatProfanity
(603412935, 28766, 'frFR', 0xE5AFACE8A1A3E5B89D0004, 38134), -- ChatProfanity
(603412935, 28765, 'frFR', 0xE7A588E7BFA00004, 38134), -- ChatProfanity
(603412935, 28764, 'frFR', 0xE5B08FE5ADA6E58D9AE5A3ABE7BFA00004, 38134), -- ChatProfanity
(603412935, 28763, 'frFR', 0xE694BFE59D9BE9BB91E9A9AC0004, 38134), -- ChatProfanity
(603412935, 28762, 'frFR', 0xE694BFE6B2BBE6B581E6B0930004, 38134), -- ChatProfanity
(603412935, 28761, 'frFR', 0xE788B1E59BBDE88085E5908CE79B9FE7BD91E7AB990004, 38134), -- ChatProfanity
(603412935, 28760, 'frFR', 0xE6AF9BE79A87E5B89D0004, 38134), -- ChatProfanity
(603412935, 28759, 'frFR', 0xE999A4E58C85E5AD900004, 38134), -- ChatProfanity
(603412935, 28758, 'frFR', 0xE89BA4E79A870004, 38134), -- ChatProfanity
(603412935, 28757, 'frFR', 0xE89BA4E89F86E698AFE8B0810004, 38134), -- ChatProfanity
(603412935, 28756, 'frFR', 0xE89BA4E89F86E698AFE8AAB00004, 38134), -- ChatProfanity
(603412935, 28755, 'frFR', 0xE680BBE4B9A6E8AEB0E79785E58DB10004, 38134), -- ChatProfanity
(603412935, 28754, 'frFR', 0xE88081E6B19FE79785E58DB10004, 38134), -- ChatProfanity
(603412935, 28753, 'frFR', 0xE6B19FE9A9BEE5B4A90004, 38134), -- ChatProfanity
(603412935, 28752, 'frFR', 0xE6B19FE5898DE79A870004, 38134), -- ChatProfanity
(603412935, 28751, 'frFR', 0xE6B19FE4B88AE79A870004, 38134), -- ChatProfanity
(603412935, 28750, 'frFR', 0xE99995E8A5BFE5B8A6E5A4B4E5A4A7E593A50004, 38134), -- ChatProfanity
(603412935, 28749, 'frFR', 0xE68A97E9BAA6E9838E0004, 38134), -- ChatProfanity
(603412935, 28748, 'frFR', 0xE6A0BCE890A8E5B094E78E8B0004, 38134), -- ChatProfanity
(603412935, 28747, 'frFR', 0xE890A8E6A0BCE5B094E78E8B0004, 38134), -- ChatProfanity
(3776013982, 337334, 'frFR', 0x005061756D652064752074696772652062C3A96EC3A966696369652064C3A9736F726D6169732064E28099756E6520706F7274C3A96520646520247B246D312B357DC2A06DC3A8747265732E204C6F727371756520766F7573207574696C6973657A20636574746520746563686E697175652C20766F757320766F7573207072C3A96369706974657A2076657273206C61206369626C652E0D0A0D0A5061756D65206475207469677265206175676D656E746520C3A967616C656D656E7420766F73206368616E63657320646520636F757020637269746971756520636F6E747265206C61206369626C6520646520243334343032316D31252070656E64616E742024333434303231642E20436574206566666574206E6520706575742073652070726F647569726520706C75732064E28099756E6520666F697320746F75746573206C657320243333373334316420706F757220636861717565206369626C652E0000, 38134), -- Spell
(813076512, 80114, 'frFR', 0x2401000057640500, 38134), -- SpellLabel
(813076512, 80113, 'frFR', 0x1A00000057640500, 38134), -- SpellLabel
(813076512, 80112, 'frFR', 0x1000000057640500, 38134), -- SpellLabel
(3776013982, 353367, 'frFR', 0x0044C3A967C3A274732073756269732072C3A9647569747320646520247331252E0000, 38134), -- Spell
(3776013982, 319278, 'frFR', 0x00456E647572616E6365206175676D656E74C3A96520646520247331252E0D0A243F733331363731345B44C3A967C3A274732073756269732072C3A9647569747320646520247333252E5D5B5D0000, 38134), -- Spell
(3776013982, 316714, 'frFR', 0x52616E672032004175676D656E7465206CE28099456E647572616E636520646520247331252E0D0A44C3A967C3A274732073756269732072C3A9647569747320646520247B2461627328247332297D252E0000, 38134), -- Spell
(3776013982, 300346, 'frFR', 0x00C389636C6174206C756E616972652C20417061697365722C2044C3A96C697672616E6365206465206C6120636F7272757074696F6E2065742052656E61697373616E636520736F6E74207574696C697361626C657320656E20666F726D652064E280996F7572732E0D0A0D0A4C65732064C3A967C3A2747320737562697320736F6E742072C3A9647569747320646520247332252E0000, 38134), -- Spell
(3776013982, 245013, 'frFR', 0x004C65732064C3A967C3A2747320737562697320736F6E742072C3A96475697473206465202473322520657420766F7472652061726D75726520657374206175676D656E74C3A96520646520247331252E0000, 38134), -- Spell
(3776013982, 48263, 'frFR', 0x00456E647572616E6365206175676D656E74C3A96520646520247331252E0D0A243F733331363731345B44C3A967C3A274732073756269732072C3A9647569747320646520247333252E5D5B5D0000, 38134), -- Spell
(3776013982, 71, 'frFR', 0x00566F757320C3AA746573202467656E64757263693A656E6475726369653B20706172206C612062617461696C6C652C206365207175692072C3A96475697420746F7573206C65732064C3A967C3A2747320737562697320646520247333252E204CE28099456E647572616E636520657374206175676D656E74C3A9652064652024733225206574206CE2809941726D7572652064652024733125206465206C6120466F7263652E0000, 38134), -- Spell
(3776013982, 337541, 'frFR', 0x00566F747265204D617271756520656E666C616D6DC3A96520766F75732072656E6420756E206D6F6E74616E7420646520706F696E74732064652076696520C3A967616C20C3A02024733125206465207365732064C3A967C3A2747320696E6974696175782070656E64616E742024333337353433642E2043686171756520656E6E656D6920746F756368C3A92070617220766F74726520536967696C20646520666575206175676D656E7465206C65732064C3A967C3A2747320696E7374616E74616EC3A97320646520766F7472652070726F636861696E65204D617271756520656E666C616D6DC3A96520646520243333373534327331252E2043756D756C61626C65206A75737175E28099C3A0202433333735343275C2A0666F69732E0000, 38134), -- Spell
(3776013982, 281242, 'frFR', 0x00566F732064C3A967C3A27473206D61727175656E74206C61206369626C652C20636520717569206175676D656E7465206C65732064C3A967C3A27473206D616769717565732073756269732064652024313439307331252E0000, 38134), -- Spell
(3776013982, 255260, 'frFR', 0x00566F732064C3A967C3A27473206D61727175656E74206C61206369626C652C20636520717569206175676D656E7465206C65732064C3A967C3A27473206D616769717565732073756269732064652024313439307331252E0000, 38134), -- Spell
(603412935, 28746, 'frFR', 0x5C62725C733F615C733F705C733F655C733F5C620000, 38134), -- ChatProfanity
(603412935, 28745, 'frFR', 0x5C62725C733F655C733F745C733F615C733F725C733F64285C733F737C5C733F655C733F64293F5C620000, 38134), -- ChatProfanity
(4033975491, 436804, 'frFR', 0x00000000000000000000000000000000000000000000000044AA06000A59FF0E030000000000000000000000000000000000000000000000000000803F00000000FFFFFFFFFFFF00000000000000CDCC4C3DCDCC4C3DCC0B0200, 38134), -- SpellVisualKitModelAttach
(3386943305, 171057, 'frFR', 0x07787800000000000000004A00B20200000000081000000000000400000000000000000001000040000000000000000000E05A0200, 38134), -- CreatureDifficulty
(3386943305, 170644, 'frFR', 0x07787800000000000000001000B2020000000008100000000000000000000000000000000100000000000000000000000068590200, 38134), -- CreatureDifficulty
(3899321669, 4791, 'frFR', 0xB71200000101180B0300, 38134), -- SpellAuraVisibility
(3899321669, 4790, 'frFR', 0xB61200000001180B0300, 38134), -- SpellAuraVisibility
(4033975491, 440494, 'frFR', 0x0000000000000000CDCC4C3E000000000000000000000000AEB80600D058FF00000000000000000000000000000000000000000000000000003333333F0000000000009E009F0000000000000000000000000000000051160200, 38134), -- SpellVisualKitModelAttach
(4033975491, 440493, 'frFR', 0x0000000000000000CDCCCC3D000000000000000000000000ADB806007F87FF00000000000000000000000000000000000000000000000000003333333F0000000000009E009F0000000000000000000000000000000051160200, 38134), -- SpellVisualKitModelAttach
(4033975491, 417672, 'frFR', 0x000000000000000000000000000000000000000000000000885F06000F5AFF00000000000000000000000000000000000000000000000000000000C03F00000000FFFFFFFFFFFF00000800000000000000000000000021030200, 38134), -- SpellVisualKitModelAttach
(4033975491, 417626, 'frFR', 0x0000000000000000000000000000000000000000000000005A5F0600E64BFF0000000000000000000000000000000000000000000000000000333373400000000000009E009F0000000000000000000000000000000009030200, 38134), -- SpellVisualKitModelAttach
(1181150530, 380178, 'frFR', 0x02000000AEB8060051160200, 38134), -- SpellVisualKitEffect
(1181150530, 380177, 'frFR', 0x02000000ADB8060051160200, 38134), -- SpellVisualKitEffect
(3776013982, 321136, 'frFR', 0x004D6F7420646520676C6F697265206772617475697420746F7573206C657320247331C2A06C616E6365727320646520426F75636C6965722064752076657274756575782E0000, 38134), -- Spell
(3776013982, 341220, 'frFR', 0x000024407370656C6C6465736333343132313200, 38134), -- Spell
(3865974254, 183187, 'frFR', 0x93CB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183165, 'frFR', 0x7DCB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183141, 'frFR', 0x65CB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183136, 'frFR', 0x60CB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183135, 'frFR', 0x5FCB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183131, 'frFR', 0x5BCB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183122, 'frFR', 0x52CB020000000000, 38134), -- ModifiedReagentItem
(3776013982, 352816, 'frFR', 0x000000, 38134), -- Spell
(600565378, 300040, 'frFR', 0xA06D01000000803F0000803F0074BA0200, 38134), -- CreatureXDisplayInfo
(813076512, 79920, 'frFR', 0x9703000075A80400, 38134), -- SpellLabel
(13330255, 73366, 'frFR', 0x081D0200F3D60200, 38134), -- ItemXItemEffect
(3865974254, 186099, 'frFR', 0xF3D6020000000000, 38134), -- ModifiedReagentItem
(600565378, 299890, 'frFR', 0x4A6400000000803F0000803F001CBA0200, 38134), -- CreatureXDisplayInfo
(600565378, 299885, 'frFR', 0x0A6F01000000803F0000803F0017BA0200, 38134), -- CreatureXDisplayInfo
(3865974254, 172899, 'frFR', 0x63A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172898, 'frFR', 0x62A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172897, 'frFR', 0x61A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172896, 'frFR', 0x60A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172895, 'frFR', 0x5FA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172894, 'frFR', 0x5EA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172893, 'frFR', 0x5DA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172892, 'frFR', 0x5CA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172891, 'frFR', 0x5BA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172890, 'frFR', 0x5AA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171099, 'frFR', 0x5B9C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171098, 'frFR', 0x5A9C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171097, 'frFR', 0x599C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171096, 'frFR', 0x589C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171095, 'frFR', 0x579C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171094, 'frFR', 0x569C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171093, 'frFR', 0x559C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171092, 'frFR', 0x549C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171091, 'frFR', 0x539C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171090, 'frFR', 0x529C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 168316, 'frFR', 0x7C91020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164959, 'frFR', 0x5F84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164958, 'frFR', 0x5E84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164957, 'frFR', 0x5D84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164956, 'frFR', 0x5C84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164955, 'frFR', 0x5B84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164954, 'frFR', 0x5A84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164953, 'frFR', 0x5984020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164952, 'frFR', 0x5884020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164951, 'frFR', 0x5784020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164950, 'frFR', 0x5684020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164587, 'frFR', 0xEB82020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164586, 'frFR', 0xEA82020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164585, 'frFR', 0xE982020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164584, 'frFR', 0xE882020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164583, 'frFR', 0xE782020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164582, 'frFR', 0xE682020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164581, 'frFR', 0xE582020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164580, 'frFR', 0xE482020000000000, 38134), -- ModifiedReagentItem
(3865974254, 159570, 'frFR', 0x526F020000000000, 38134), -- ModifiedReagentItem
(3865974254, 155622, 'frFR', 0xE65F020000000000, 38134), -- ModifiedReagentItem
(3205218938, 43871, 'frFR', 0x43555252454E43595F534541534F4E5F544F54414C5F4D4158494D554D004D6178696D756D2070617220736169736F6EC2A03A20257325732F25730001, 38134), -- GlobalStrings
(3776013982, 324919, 'frFR', 0x0024407370656C6C646573633332323834310000, 38134), -- Spell
(3776013982, 322841, 'frFR', 0x004C65732064C3A967C3A2747320646520243F613231323631325B5275C3A9652066756C677572616E74655D3F613231323631335B46726170706520696E6665726E616C655D5B5D20736F6E74206175676D656E74C3A97320646520247331252C2E0044C3A967C3A2747320646520243F613231323631325B5275C3A9652066756C677572616E74655D3F613231323631335B46726170706520696E6665726E616C655D5B5D206175676D656E74C3A97320646520247331252E00, 38134), -- Spell
(3776013982, 294588, 'frFR', 0x004175676D656E7465206C6573206368616E63657320646520636F757020637269746971756520646520247B2473312A2432393435373873317D252E0000, 38134), -- Spell
(3776013982, 294587, 'frFR', 0x004175676D656E7465206C6573206368616E63657320646520636F757020637269746971756520646520247B2473312A2432393435373873317D252E0000, 38134), -- Spell
(3865974254, 180318, 'frFR', 0x5EC0020000000000, 38134), -- ModifiedReagentItem
(3865974254, 180317, 'frFR', 0x5DC0020000000000, 38134), -- ModifiedReagentItem
(3865974254, 176406, 'frFR', 0x16B1020000000000, 38134), -- ModifiedReagentItem
(3865974254, 168564, 'frFR', 0x7492020000000000, 38134), -- ModifiedReagentItem
(3776013982, 352497, 'frFR', 0x000000, 38134), -- Spell
(3776013982, 327193, 'frFR', 0x004D65742066696E2061752074656D707320646520726563686172676520646520426F75636C6965722064752076656E676575722E20566F7320246EC2A070726F636861696E7320426F75636C696572732064752076656E67657572206EE280996F6E74207061732064652074656D707320646520726563686172676520657420696E666C6967656E74206465732064C3A967C3A27473206175676D656E74C3A97320646520247332252E004C657320246EC2A070726F636861696E7320426F75636C696572732064752076656E67657572206EE280996F6E74207061732064652074656D707320646520726563686172676520657420696E666C6967656E74206465732064C3A967C3A27473206175676D656E74C3A97320646520247732252E00, 38134), -- Spell
(3776013982, 321995, 'frFR', 0x004C6120676C6163652073652072C3A970616E64206C696272656D656E742064616E7320766F73207665696E65732C206365207175692072C3A9647569742064652024733125206C6520636FC3BB7420656E207075697373616E63652072756E6971756520646520766F7320746563686E69717565732070656E64616E742024642E204E652064C3A9636C656E63686520706173206C652074656D707320646520726563686172676520676C6F62616C2E004C6520636FC3BB7420656E207075697373616E63652072756E697175652064657320746563686E6971756573206573742072C3A96475697420646520247331252E00, 38134), -- Spell
(3776013982, 248518, 'frFR', 0x54616C656E74204A634A004C652070726F636861696E20736F727420686F7374696C65206C616E63C3A920737572206C61206369626C6520656E747261C3AE6E65206C61207265646972656374696F6E2064657320736F72747320686F7374696C6573207665727320766F7472652066616D696C6965722070656E64616E7420247331C2A0732E0D0A0D0A566F7472652066616D696C69657220646F69742073652074726F7576657220C3A0206D6F696E7320646520243234383531396131C2A06DC3A874726573206465206C61206369626C6520706F757220717565206C657320736F72747320736F69656E742072656469726967C3A9732E0000, 38134), -- Spell
(3776013982, 243435, 'frFR', 0x004368616E676520766F747265207065617520656E207069657272652C20636520717569206175676D656E746520766F7320706F696E7473206465207669652061637475656C73206574206D6178696D756D20646520247331252C2065742072C3A964756974206C65732064C3A967C3A2747320737562697320646520247332252070656E64616E742024642E004D6178696D756D20646520706F696E747320646520766965206175676D656E74C3A920646520247731252E0D0A44C3A967C3A274732073756269732072C3A9647569747320646520247732252E243F2477343E315B0D0A4162736F72626520247734C2A0706F696E74732064652064C3A967C3A274732E5D5B5D00, 38134), -- Spell
(3776013982, 235219, 'frFR', 0x004D65742066696E2061752074656D7073206465207265636861726765206465204261727269C3A8726520646520676C6163652C204E6F76612064652067697672652C2043C3B46E652064652066726F696420657420426C6F6320646520676C6163652E0000, 38134), -- Spell
(3776013982, 209584, 'frFR', 0x54616C656E74204A634A0052656E6420696E73656E7369626C6520617578206566666574732064652073696C656E63652065742064E28099696E74657272757074696F6E2070656E64616E742024642E00496E73656E7369626C6520617578206566666574732064652073696C656E63652065742064E28099696E74657272757074696F6E2E00, 38134), -- Spell
(3776013982, 202335, 'frFR', 0x54616C656E74204A634A00566F7472652070726F636861696E2046726163617373652D746F6E6E65617520696E666C6967652024733125C2A064C3A967C3A2747320737570706CC3A96D656E74616972657320657420C3A9746F7572646974206C6573206369626C6573207175E28099696C20746F756368652070656E64616E742024323032333436642E0046726163617373652D746F6E6E65617520696E666C6967652024733125C2A064652064C3A967C3A2747320737570706CC3A96D656E74616972657320657420C3A9746F7572646974206C6573206369626C657320746F756368C3A965732070656E64616E742024323032333436642E00, 38134), -- Spell
(3776013982, 34477, 'frFR', 0x00566F7573207472616E7366C3A972657A206C61206D656E6163652071756520766F75732067C3A96EC3A972657A2076657273206C65206D656D6272652064752067726F757065206F752072616964206369626CC3A92C20C3A02070617274697220646520766F7472652070726F636861696E6520617474617175652065666665637475C3A9652064616E73206C65732024642065742070656E64616E7420243335303739642E004D656E6163652072656469726967C3A9652064752063686173736575722E00, 38134), -- Spell
(3359787322, 19830, 'frFR', 0x764D0000, 38134), -- WorldState
(3359787322, 19710, 'frFR', 0xFE4C0000, 38134), -- WorldState
(3359787322, 19709, 'frFR', 0xFD4C0000, 38134), -- WorldState
(3359787322, 19384, 'frFR', 0xB84B0000, 38134), -- WorldState
(368401261, 5214, 'frFR', 0x5B8800000000000000000000000000000000000000000000, 38134), -- CombatCondition
(368401261, 4771, 'frFR', 0x848400000000000000000000000000000000000000000000, 38134), -- CombatCondition
(3776013982, 163708, 'frFR', 0x004175676D656E7465206C65732064C3A967C3A274732064657320736F727473206465203230252E0D0A0D0A5065726D657420617578206172616B6B6F612073657468656B6B206465206C616E63657220466C616D6D6520656E766FC3BB74C3A9652E004175676D656E7465206C65732064C3A967C3A274732064657320736F727473206465203230252E0D0A0D0A5065726D657420617578206172616B6B6F612073657468656B6B206465206C616E63657220466C616D6D6520656E766FC3BB74C3A9652E00, 38134), -- Spell
(3776013982, 352329, 'frFR', 0x000000, 38134), -- Spell
(3865974254, 52489, 'frFR', 0x09CD000000000000, 38134), -- ModifiedReagentItem
(3037505077, 52489, 'frFR', 0x0100, 38134), -- TradeSkillItem
(3776013982, 220358, 'frFR', 0x0024407370656C6C646573633130313534360000, 38134), -- Spell
(3776013982, 340433, 'frFR', 0x004CE28099616E696D612072616666696EC3A92063697263756C6520C3A0207472617665727320766F7573206574206175676D656E746520766F732064C3A967C3A2747320696E666C6967C3A97320657420766F7320736F696E732070726F64696775C3A97320646520247331252070656E64616E742024642E0044C3A967C3A2747320696E666C6967C3A973206175676D656E74C3A97320646520247331252E0D0A536F696E732070726F64696775C3A973206175676D656E74C3A97320646520247332252E00, 38134), -- Spell
(3776013982, 335161, 'frFR', 0x004C657320C3A96368617070656D656E74732064E28099616E696D612072C3A9637570C3A972C3A97320737572206C657320676F6C69617468732064C3A96665637475657578206175676D656E74656E74206C6120766974657373652064652064C3A9706C6163656D656E7420646520247331252065742070726F766F7175656E74206CE28099C3A972757074696F6E20647520706572736F6E6E6167652D6A6F7565757220746F75746573206C657320247433C2A0732070656E64616E742024642C2063652071756920696E666C69676520243334343432317331C2A0706F696E74732064652064C3A967C3A274732064657320417263616E65732061757820656E6E656D69732070726F636865732065742072656E6420243334343432327331C2A0706F696E7473206465207669652061757820616C6C69C3A9732070726F636865732E00566974657373652064652064C3A9706C6163656D656E74206175676D656E74C3A96520646520247331252E20496E666C69676520243334343432317331C2A0706F696E74732064652064C3A967C3A274732064657320417263616E65732061757820656E6E656D69732070726F636865732065742072656E6420243334343432327331C2A0706F696E7473206465207669652061757820616C6C69C3A9732070726F6368657320746F75746573206C657320247433C2A0732E00, 38134), -- Spell
(3205218938, 43287, 'frFR', 0x4741525249534F4E5F464F4C4C4F5745525F4F4E5F4D495353494F4E5F434F4D504C455445004D697373696F6E202D205465726D696EC3A9650001, 38134), -- GlobalStrings
(3205218938, 43286, 'frFR', 0x4741525249534F4E5F464F4C4C4F5745525F4D495353494F4E5F434F4D504C45544544005465726D696EC3A9650001, 38134), -- GlobalStrings
(3205218938, 43283, 'frFR', 0x434F56454E414E545F464F4C4C4F5745525F4D495353494F4E5F434F4D504C455445004176656E74757265202D205465726D696EC3A9650001, 38134), -- GlobalStrings
(261693969, 59853, 'frFR', 0xFFFFFFFFFFFFFFFF4C65207468C3A920657374207365727669C2A03A20537962696C6C65206CE28099C3A9676172C3A9650000CDE900007599F633010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F88700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(261693969, 59852, 'frFR', 0xFFFFFFFFFFFFFFFF4C65207468C3A920657374207365727669C2A03A2047756262696E732065742054756262696E730000CCE900007499F533010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F78700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(261693969, 59850, 'frFR', 0xFFFFFFFFFFFFFFFF4C65207468C3A920657374207365727669C2A03A2056756C63610000CAE900007299F433010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F78700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(261693969, 59848, 'frFR', 0xFFFFFFFFFFFFFFFF4C65207468C3A920657374207365727669C2A03A205468C3A96F7461720000C8E900007199F333010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F78700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(3776013982, 320740, 'frFR', 0x000000, 38134), -- Spell
(3776013982, 350249, 'frFR', 0x00436F75726265206C6520666C75782074656D706F72656C2C20636520717569206175676D656E7465206C612048C3A27465206465202473312520706F757220766F7320696D61676573206D69726F697220657420766F75732064652024313130393039642E0048C3A27465206175676D656E74C3A96520646520247731252E20243F2457343E305B566974657373652064E28099C3A9636F756C656D656E742064752074656D7073206175676D656E74C3A96520646520247734252E5D5B5D00, 38134), -- Spell
(3776013982, 320914, 'frFR', 0x0050656E64616E7420416C74C3A9726572206C652074656D70732C206C65206C616E636575722065742073657320696D61676573206D69726F6972732062C3A96EC3A966696369656E742064E28099756E6520446973746F7273696F6E2074656D706F72656C6C6520737570706CC3A96D656E746169726520C3A020247331252064652073612076616C6575722E204EE280996573742070617320616666656374C3A9207061722044C3A9706C6163656D656E742074656D706F72616C206F7520617574726573206566666574732073696D696C61697265732E0050656E64616E7420416C74C3A9726572206C652074656D70732C206C65206C616E636575722065742073657320696D61676573206D69726F6972732062C3A96EC3A966696369656E742064E28099756E6520446973746F7273696F6E2074656D706F72656C6C6520737570706CC3A96D656E746169726520C3A020247331252064652073612076616C6575722E204EE280996573742070617320616666656374C3A9207061722044C3A9706C6163656D656E742074656D706F72616C206F7520617574726573206566666574732073696D696C61697265732E00, 38134), -- Spell
(3893700160, 169, 'frFR', 0x0F000000E2000000D20000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 168, 'frFR', 0x0E000000E2000000CF0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 167, 'frFR', 0x0D000000DF000000CF0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 166, 'frFR', 0x0C000000DF000000CF0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 165, 'frFR', 0x0B000000DC000000CB0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 164, 'frFR', 0x0A000000DC000000CB0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 163, 'frFR', 0x09000000D8000000C80000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 162, 'frFR', 0x08000000D8000000C80000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 161, 'frFR', 0x07000000D5000000C80000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 160, 'frFR', 0x06000000D2000000C50000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 159, 'frFR', 0x05000000D2000000C20000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 158, 'frFR', 0x04000000CF000000C20000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 157, 'frFR', 0x03000000CB000000BE0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 156, 'frFR', 0x02000000C8000000BB0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 155, 'frFR', 0x0100000000000000B70000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3776013982, 351967, 'frFR', 0x000000, 38134), -- Spell
(3776013982, 340882, 'frFR', 0x00566F757320617070656C657A206C652042616C6C6F6E6EC3A920656E20636173206465206469737061726974696F6E206F75206465206D6F72742E00417070656C6C65206C652042616C6C6F6E6EC3A920656E20636173206465206469737061726974696F6E206F75206465206D6F72742E00, 38134), -- Spell
(2340571112, 755, 'frFR', 0xBD000000D51C0000D0040000060000008F1B00000000000000000000, 38134), -- ItemBonusListGroupEntry
(2998606315, 212, 'frFR', 0x0000000005000000803A09000000000000000000, 38134), -- ScheduledInterval
(3359787322, 20659, 'frFR', 0xB3500000, 38134); -- WorldState

INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(4021368146, 4553, 'frFR', 0x5374796769657320746F6D62C3A96573000000000000000000D8020000424400000000000000000000000000000000000000, 38134), -- Vignette
(2202435563, 997132, 'frFR', 0x0C370F00240127010000F3170700, 38134), -- QuestPOIPoint
(2202435563, 997131, 'frFR', 0x0B370F00240128010000F2170700, 38134), -- QuestPOIPoint
(2921112328, 464883, 'frFR', 0xF31707003B097E06000001E1E9000001000000871306000000000000000000, 38134), -- QuestPOIBlob
(2921112328, 464882, 'frFR', 0xF21707003B097E06000001E1E9000001000000871306000000000000000000, 38134), -- QuestPOIBlob
(3776013982, 335718, 'frFR', 0x0043686172676520657420496E74657276656E74696F6E20766F757320636F6E66C3A872656E74204D61C3AE747269736520647520626C6F636167652070656E64616E7420247B2473312F313030307D2C20526576616E636865C2A0212065742067C3A96EC3A872656E7420247B2433333537333473312F31307D20706F696E747320646520726167652E0000, 38134), -- Spell
(2948698321, 339, 'frFR', 0x6D68C604BDD61274, 38134), -- TactKeyLookup
(2948698321, 278, 'frFR', 0x7CB28F52811F5830, 38134), -- TactKeyLookup
(3776013982, 328547, 'frFR', 0x4EC3A963726F2D736569676E6575727300566F757320696D706C616E74657A20756E6520706F696E74652064E280996F732064616E73206C61206369626C652071756920737562697420247331C2A0706F696E74732064652064C3A967C3A2747320657420243332343037337331C2A0706F696E74732064652064C3A967C3A2747320646520736169676E656D656E7420746F75746573206C657320243332343037337431C2A073206A75737175E28099C3A0206365207175E28099656C6C65206D657572652E0D0A0D0A52656E642031C2A0636861726765207175616E64206C61206369626C65206D657572742E0D0A0D0A7C634646464646464646436F6E66C3A872652031C2A0706F696E7420646520636F6D626F20706C7573203120706F696E7420737570706CC3A96D656E74616972652070617220706F696E74652064E280996F73206163746976652E7C720000, 38134), -- Spell
(1369604944, 2081, 'frFR', 0x000000000000000000000000000000000000000000000000210800006E1C00000000FF2200000000000000002C010000EE0204020000410B0000000000000000002208, 38134), -- SpellVisualMissile
(4033975491, 439153, 'frFR', 0x00000000000000000000000000000000000000000000000071B3060092001500000000000000000000000000000000000000000000000000000000803F00000000FFFFFFFFFFFF00000C000000000000000000000000FF340200, 38134), -- SpellVisualKitModelAttach
(4033975491, 439152, 'frFR', 0x00000000000000000000000000000000000000000000000070B3060092001600000000000000000000000000000000000000000000000000000000803F00000000FFFFFFFFFFFF00000C000000000000000000000000FF340200, 38134), -- SpellVisualKitModelAttach
(1181150530, 377991, 'frFR', 0x050000001ABB020096D20100, 38134), -- SpellVisualKitEffect
(1181150530, 377990, 'frFR', 0x0500000019BB0200F3290200, 38134), -- SpellVisualKitEffect
(1181150530, 377988, 'frFR', 0x0500000019BB020054180200, 38134), -- SpellVisualKitEffect
(1181150530, 377987, 'frFR', 0x0500000018BB020088F60100, 38134), -- SpellVisualKitEffect
(1181150530, 377986, 'frFR', 0x0500000017BB020088F60100, 38134), -- SpellVisualKitEffect
(1181150530, 377985, 'frFR', 0x0500000016BB0200820F0200, 38134), -- SpellVisualKitEffect
(1181150530, 377984, 'frFR', 0x0500000015BB02009FFA0100, 38134), -- SpellVisualKitEffect
(1181150530, 377983, 'frFR', 0x050000006C4E01004B4B0100, 38134), -- SpellVisualKitEffect
(1181150530, 377982, 'frFR', 0x0200000071B30600FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377981, 'frFR', 0x0200000070B30600FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377980, 'frFR', 0x05000000EFCC0100FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377979, 'frFR', 0x06000000B7D20500FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377978, 'frFR', 0x0500000014BB020052F20100, 38134), -- SpellVisualKitEffect
(1181150530, 377977, 'frFR', 0x0500000013BB0200D8030200, 38134), -- SpellVisualKitEffect
(3425193231, 278473, 'frFR', 0x060000000D0000000000000000000000000000000000000002000000494B01001EA30100, 38134), -- SpellVisualEvent
(3425193231, 278472, 'frFR', 0x060000000D0000000000000000000000000000000000000001000000494B01001EA30100, 38134), -- SpellVisualEvent
(3425193231, 278471, 'frFR', 0x030000000D0000000000000000000000000000000000000001000000FF3402001EA30100, 38134), -- SpellVisualEvent
(3425193231, 278470, 'frFR', 0x010000000200000000000000000000000000000000000000010000004A4B01001EA30100, 38134), -- SpellVisualEvent
(859088734, 381623, 'frFR', 0xFFFFFFFF360000000000, 38134), -- SpellVisualAnim
(4146370265, 107294, 'frFR', 0x0000000000000000000000000000000000000000000000000000000000000000FF22000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SpellVisual
(3266400455, 613060, 'frFR', 0x1ABB02002C713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613059, 'frFR', 0x1ABB02002B713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613058, 'frFR', 0x1ABB02002A713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613057, 'frFR', 0x1ABB020029713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613056, 'frFR', 0x1ABB020028713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613055, 'frFR', 0x19BB0200BC6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613054, 'frFR', 0x19BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613053, 'frFR', 0x19BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613052, 'frFR', 0x19BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613051, 'frFR', 0x19BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613050, 'frFR', 0x19BB0200B76A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613049, 'frFR', 0x19BB0200B66A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613043, 'frFR', 0x18BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613042, 'frFR', 0x18BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613041, 'frFR', 0x18BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613040, 'frFR', 0x18BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613039, 'frFR', 0x18BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613038, 'frFR', 0x17BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613037, 'frFR', 0x17BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613036, 'frFR', 0x17BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613035, 'frFR', 0x17BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613034, 'frFR', 0x17BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613033, 'frFR', 0x16BB0200BC6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613032, 'frFR', 0x16BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613031, 'frFR', 0x16BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613030, 'frFR', 0x16BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613029, 'frFR', 0x16BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613028, 'frFR', 0x16BB0200B76A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613027, 'frFR', 0x16BB0200B66A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613018, 'frFR', 0x15BB0200C36A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613017, 'frFR', 0x15BB0200C26A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613016, 'frFR', 0x15BB0200C16A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613015, 'frFR', 0x15BB0200C06A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613014, 'frFR', 0x15BB0200BF6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613013, 'frFR', 0x15BB0200BE6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613012, 'frFR', 0x15BB0200BD6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613011, 'frFR', 0x14BB02004AE21900010000803F, 38134), -- SoundKitEntry
(3266400455, 613010, 'frFR', 0x14BB02004BE21900010000803F, 38134), -- SoundKitEntry
(3266400455, 613009, 'frFR', 0x14BB02004CE21900010000803F, 38134), -- SoundKitEntry
(3266400455, 613008, 'frFR', 0x13BB0200C36A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613007, 'frFR', 0x13BB0200C26A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613006, 'frFR', 0x13BB0200C16A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613005, 'frFR', 0x13BB0200C06A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613004, 'frFR', 0x13BB0200BF6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613003, 'frFR', 0x13BB0200BE6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613002, 'frFR', 0x13BB0200BD6A3500010000803F, 38134), -- SoundKitEntry
(3232102598, 140456, 'frFR', 0xA82402001ABB02000000A040000000410000000000000000000000000000000000000000020000000000000000E8030000E8030000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000F4010000F4010000580C00000000803F010000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140455, 'frFR', 0xA7240200AF6C02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140454, 'frFR', 0xA6240200C06502000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140453, 'frFR', 0xA5240200D07102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140452, 'frFR', 0xA424020019BB02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140451, 'frFR', 0xA3240200020A00000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140450, 'frFR', 0xA224020018BB02000000A040000000410000000000000000000000000000000000000000020000000000000000E8030000E8030000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140449, 'frFR', 0xA124020017BB02000000A040000000410000000000000000000000000000000000000000020000000000000000F4010000F4010000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140448, 'frFR', 0xA02402003E7502000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140447, 'frFR', 0x9F240200447502000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140446, 'frFR', 0x9E24020016BB02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000100FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140445, 'frFR', 0x9D24020015BB02000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140444, 'frFR', 0x9C240200B9710200000040410000C04100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140443, 'frFR', 0x9B240200956C02000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140442, 'frFR', 0x9A240200177202000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140441, 'frFR', 0x99240200F46F02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140440, 'frFR', 0x98240200817202000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140439, 'frFR', 0x97240200557102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140438, 'frFR', 0x96240200ED6602000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140437, 'frFR', 0x952402001E7102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140436, 'frFR', 0x94240200E56602000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140435, 'frFR', 0x9324020014BB02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140434, 'frFR', 0x9224020013BB02000000A040000000410000000000000000000000000000000000000000020000000000000000F4010000F4010000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140433, 'frFR', 0x91240200666C02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140432, 'frFR', 0x90240200267102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123926, 'frFR', 0x16E40100407602000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000002C01000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123714, 'frFR', 0x42E30100437502000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000101F4010000F4010000570C0000E8030000E8030000580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123675, 'frFR', 0x1BE30100457502000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123670, 'frFR', 0x16E301003D7502000000A04000002041000000000000000000000000000000000000000002E6000000E6000000E6000000E6000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123594, 'frFR', 0xCAE20100F17402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123515, 'frFR', 0x7BE20100A27402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000002C01000000000000000000000001C8000000C8000000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123514, 'frFR', 0x7AE20100A17402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000009600000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123504, 'frFR', 0x70E201009F7402000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001401F0000401F0000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123503, 'frFR', 0x6FE201009E7402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000002C010000000000000000000000016400000064000000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123502, 'frFR', 0x6EE201009D7402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000009600000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122935, 'frFR', 0x37E00100507202000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000100FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122901, 'frFR', 0x15E00100167202000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000100FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122891, 'frFR', 0x0BE00100187202000000C0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122821, 'frFR', 0xC5DF0100D1710200000000400000804000000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122814, 'frFR', 0xBEDF0100C87102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122807, 'frFR', 0xB7DF0100C17102000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001BC020000BC020000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122806, 'frFR', 0xB6DF0100C07102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122804, 'frFR', 0xB4DF0100BE7102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000009600000000000000000000000001C8000000C8000000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122709, 'frFR', 0x55DF01004A7102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122629, 'frFR', 0x05DF0100F97002000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B44300000000000000C800000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122404, 'frFR', 0x24DE0100F56F02000000C0400000404100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000B80B0000B80B0000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121643, 'frFR', 0x2BDB0100D76C02000000803F0000004000000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B4430000000000000000000000000000000000000001012C0100002C010000570C0000E8030000E8030000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121613, 'frFR', 0x0DDB0100976C02000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B4430000000000000000000000000000000000000000012C0100002C010000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121609, 'frFR', 0x09DB0100906C02000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000B80B0000B80B0000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121587, 'frFR', 0xF3DA0100686C02000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000E8030000E8030000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 120239, 'frFR', 0xAFD50100E66602000000C040000040410000000000000000000000000000000000000000000000000000000000F4010000F4010000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001E8030000E8030000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 119974, 'frFR', 0xA6D40100D66502000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000002FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 25856, 'frFR', 0x00650000C9E600000000A04000002041000000000000000000000000000000000000000002E6000000E6000000E6000000E6000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(1485693696, 5565, 'frFR', 0x1ABB0200010000000069620000000000000100, 38134); -- SoundEnvelope
