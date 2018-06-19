-- Table `quest_offer_reward_locale`
DELETE FROM `quest_offer_reward_locale` WHERE ID IN ('12593','12619','12842','12848','12636','12641','12657','12850','12849','12670','12680','12687') AND (locale = "frFR");
INSERT INTO `quest_offer_reward_locale` VALUES
('12593', 'frFR', 'Vous avez entendu l’appel du roi-liche, $c. L’heure de répondre à votre maître a sonné.', '25996'),
('12619', 'frFR', 'Très bien, $N. Vous avez créé votre première arme runique. Avec elle, vous sèmerez chaos et destruction ! Vous laisserez une traînée de carnage derrière vous, jonchée des cadavres de tous ceux qui osent s’opposer au Fléau.', '25996'),
('12842', 'frFR', 'Souvenez-vous de ces paroles, chevalier de la mort : les forgerunes sont des instruments du Fléau. Il n\'en existe qu\'à Achérus, à Naxxramas et au coeur de la Couronne de glace ! Vous ne pouvez blasonner votre arme qu\'à proximité d\'une forgerune.$B$BRevenez souvent, et blasonnez toutes vos armes. Un chevalier de la mort doit être prêt à affronter tous ceux qui s\'opposent à lui !', '25996'),
('12848', 'frFR', 'Comme je m\’y attendais, mon chevalier a triomphé ! Vous êtes prêt, $N.', '25996'),
('12636', 'frFR', 'Il sera bientôt temps de verser le sang de nos ennemis. Vous devez d’abord apprendre à connaître ce que vous cherchez à détruire, avant de vous jeter à corps perdu dans la bataille. C’est ce qui différencie le chevalier de la mort de la simple goule.$B$BJe vais vous faire don de la vision par-delà la vision, champion. Vous utiliserez l\’œil d’Achérus pour voler les secrets de nos ennemis.', '25996'),
('12641', 'frFR', 'Comme prévu, ils se préparent pour la bataille. Mais il y a autre chose… Je sens un ancien ennemi. Un ennemi que j\’ai détruit il y a déjà bien longtemps…$B$BCe n\’est pas grave. Nous allons envoyer toute la puissance du Fléau contre eux avant qu\’ils aient une chance d’évacuer leurs maisons et de mettre en place leurs défenses.', '25996'),
('12657', 'frFR', 'Les cors de guerre retentiront bientôt sur cette terre, réveillant les morts et appelant les machines de guerre du Fléau. Je plains ceux qui se dresseront sur notre route !$B$BVous et les vôtres dirigerez l’assaut, $N. La prochaine fois que je regarderai les terres écarlates, ma vision sera noircie par les légions d\’Achérus. La marche vers la Nouvelle-Avalon débute maintenant.', '25996'),
('12850', 'frFR', 'La guerre a commencé, chevalier de la mort ! Je vais vous placer sur l\un de mes meilleurs griffons et vous envoyer à Brèche-de-Mort. Chaos, mort, destruction ! Vous serez le messager de tout ceci et bien plus encore !', '25996'),
('12849', 'frFR', 'Vous trouverez les trois écoles du sang, du givre et de l’impie ici, dans la salle de commande. Chacune a un maître qui pourra vous enseigner les arts ténébreux.$B$BJe suis le seigneur Thorval, le maître du sang. Dame Alistra règne sur l’impie, et l’archi-liche Amal’thazad gouverne le givre.$B$BRevenez vous entraîner lorsque vous monterez en puissance !', '25996'),
('12670', 'frFR', 'Sentez-vous ça ?$B$B<Valanar renifle l\’air.>$B$BDe la viande fraîche… L\’odeur des croisés écarlates flotte dans l\’air.$B$B<Valanar salive.>$B$BExcusez-moi, $C. Mon goût pour la gastronomie ne vous intéresse probablement pas. Vous êtes ici pour travailler ! Pour mener l\’assaut ! Oui... Je sais. le roi-liche m\’a raconté tout ce que j\’ai besoin de savoir sur vous, $n.$B$BLe bain de sang va commencer.', '25996'),
('12680', 'frFR', 'Et maintenant, la véritable épreuve. Saurez-vous maîtriser un destrier non attaché et prendre ce que vous désirez le plus ?', '25996'),
('12687', 'frFR', 'Vous avez réussi là où la plupart des initiés échouent, $n. Vous serez grassement récompensé.', '25996');

-- Table `quest_request_items_locale`
DELETE FROM `quest_request_items_locale` WHERE ID IN ('12619','12641') AND (locale = "frFR");
INSERT INTO `quest_request_items_locale` VALUES
('12619', 'frFR', 'La lame runique est une extension de votre être ! Sans lame runique, vous ne pourrez pas vous battre.', '25996'),
('12641', 'frFR', 'Notre assaut contre la Croisade écarlate entrera dans la légende.', '25996');
