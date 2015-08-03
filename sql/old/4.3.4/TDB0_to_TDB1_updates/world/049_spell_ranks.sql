DELETE FROM `spell_ranks` WHERE `spell_id` IN (73318,74258,74495,74496,74497,74517,74519,74522,74559,75156,76666,78670,80731,81199,81708,82774,86008,88053,88868,88961,89718,89719,89720,89721,89722,90265);
INSERT INTO `spell_ranks` (`first_spell_id`,`spell_id`,`rank`) VALUES
( 2259,80731,7), -- Illustrious Grand Master Alchemy
( 2018,76666,7), -- Illustrious Grand Master Blacksmithing
( 7411,74258,7), -- Illustrious Grand Master Enchanting
( 4036,82774,7), -- Illustrious Grand Master Engineering
( 2366,74519,7), -- Illustrious Grand Master Herbalism
(45357,86008,7), -- Illustrious Grand Master Inscription
(25229,73318,7), -- Illustrious Grand Master Jewelcrafting
( 2108,81199,7), -- Illustrious Grand Master Leatherworking
( 2575,74517,7), -- Illustrious Grand Master Mining
( 8613,74522,7), -- Illustrious Grand Master Skinning
( 3908,75156,7), -- Illustrious Grand Master Tailoring
(81708,81708,1), -- Lifeblood
(81708,74497,8), -- Lifeblood
(53120,74496,7), -- Toughness
(53125,74495,7), -- Master of Anatomy
( 2550,88053,7), -- Illustrious Grand Master Cooking
( 3273,74559,7), -- Illustrious Grand Master First Aid
( 7620,88868,7), -- Illustrious Grand Master Fishing
(33388,90265,5), -- Illustrious Grand Master Riding
(78670,78670,1), -- Apprentice Archaeology
(78670,88961,2), -- Journeyman Archaeology
(78670,89718,3), -- Expert Archaeology
(78670,89719,4), -- Artisan Archaeology
(78670,89720,5), -- Master Archaeology
(78670,89721,6), -- Grand Master Archaeology
(78670,89722,7); -- Illustrious Grand Master Archaeology
 
UPDATE `spell_ranks` SET `rank`=`rank`+10 WHERE `first_spell_id`=55428; -- Lifeblood
UPDATE `spell_ranks` SET `rank`=`rank`-9 WHERE `first_spell_id`=55428; -- Lifeblood
UPDATE `spell_ranks` SET `first_spell_id`=81708 WHERE `first_spell_id`=55428; -- Lifeblood
