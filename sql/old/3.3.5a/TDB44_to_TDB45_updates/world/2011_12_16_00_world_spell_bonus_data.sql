-- Bounus coef for Greater Fire Elemental spells
DELETE FROM `spell_bonus_data` WHERE `entry` IN (13376,57984);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`,`ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(13376,0.032,-1,-1,-1,'Greater Fire Elemental - Fire Shield'),
(57984,0.4289,-1,-1,-1,'Greater Fire Elemental - Fire Blast');