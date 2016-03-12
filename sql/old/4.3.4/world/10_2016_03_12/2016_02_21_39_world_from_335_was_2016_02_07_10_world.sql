-- DB/Item: Bryntroll, the Bone Arbiter
-- UPDATE `item_template` SET `spellcooldown_1`=-1 WHERE `entry`=50415; 
-- UPDATE `item_template` SET `spellppmRate_1`=2 WHERE `entry` IN (50415,50709);
DELETE FROM `spell_bonus_data` WHERE `entry` IN (71839,71838);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(71839,0,0,0,0,'Drain Life'),
(71838,0,0,0,0,'Drain Life');
