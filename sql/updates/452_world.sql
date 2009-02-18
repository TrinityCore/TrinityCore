-- link gift of the wild to mark of the wild

DELETE FROM `spell_chain` WHERE `spell_id` = 21849;
DELETE FROM `spell_chain` WHERE `spell_id` = 21850;
DELETE FROM `spell_chain` WHERE `spell_id` = 26991;

INSERT INTO `spell_chain` (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (21849,0,1126,1,0);
INSERT INTO `spell_chain` (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (21850,21849,1126,2,0);
INSERT INTO `spell_chain` (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (26991,21850,1126,3,0);

