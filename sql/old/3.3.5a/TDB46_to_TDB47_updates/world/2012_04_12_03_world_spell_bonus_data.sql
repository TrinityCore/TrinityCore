-- Fixes some spell power stacking exploits
DELETE FROM `spell_bonus_data` WHERE `entry` IN (44525,18798,16614,7712,13897);
INSERT INTO `spell_bonus_data` (`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`ap_dot_bonus`,`comments`) VALUES
(44525,0,0,-1,-1, 'Enchant Weapon - Icebreaker'),
(18798,0,0,-1,-1, 'Item - Freezing Band'),
(16614,0,0,-1,-1, 'Item - Storm Gauntlets'),
(7712,0,0,-1,-1, 'Item - Fiery Retributer | Blazefury Medallion'),
(13897,0,0,-1,-1, 'Enchant Weapon - Fiery Weapon');
