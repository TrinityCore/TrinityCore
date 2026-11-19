-- added missing entry for 3rd rank of gift of the wild

DELETE FROM spell_chain WHERE spell_id = 21849;
DELETE FROM spell_chain WHERE spell_id = 21850;
DELETE FROM spell_chain WHERE spell_id = 26991;

INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (21849,0,21849,1,0);
INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (21850,21849,21849,2,0);
INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (26991,21850,21849,3,0);

-- weaponsmith and armorsmith as blacksmith req spells

DELETE FROM spell_chain WHERE spell_id = 9787;
DELETE FROM spell_chain WHERE spell_id = 9788;

INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (9787,0,9787,1,9785);
INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (9788,0,9788,1,9785);

-- axe/sword/hammer smith req weaponsmith

DELETE FROM spell_chain WHERE spell_id = 17039;
DELETE FROM spell_chain WHERE spell_id = 17040;
DELETE FROM spell_chain WHERE spell_id = 17041;

INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (17039,0,17039,1,9787);
INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (17040,0,17040,1,9787);
INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (17041,0,17041,1,9787);

-- letherworking specs req spells

DELETE FROM spell_chain WHERE spell_id = 10660;
DELETE FROM spell_chain WHERE spell_id = 10658;
DELETE FROM spell_chain WHERE spell_id = 10656;

INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (10660,0,10660,1,10662);
INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (10658,0,10658,1,10662);
INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (10656,0,10656,1,10662);

-- alchemy specs req spells

DELETE FROM spell_chain WHERE spell_id = 28672;
DELETE FROM spell_chain WHERE spell_id = 28675;
DELETE FROM spell_chain WHERE spell_id = 28677;

INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (28672,0,28672,1,28596);
INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (28675,0,28675,1,28596);
INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (28677,0,28677,1,28596);

-- tailoring specs req spells

DELETE FROM spell_chain WHERE spell_id = 26801;
DELETE FROM spell_chain WHERE spell_id = 26798;
DELETE FROM spell_chain WHERE spell_id = 26797;

INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (26801,0,26801,1,26790);
INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (26798,0,26798,1,26790);
INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (26797,0,26797,1,26790);

-- engineering specs req spells

DELETE FROM spell_chain WHERE spell_id = 20222;
DELETE FROM spell_chain WHERE spell_id = 20219;

INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (20222,0,20222,1,12656);
INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (20219,0,20219,1,12656);

-- divine spirit req spells

DELETE FROM spell_chain WHERE spell_id = 27681;
DELETE FROM spell_chain WHERE spell_id = 32999;

INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (27681,0,27681,1,14752);
INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (32999,27681,27681,2,0);

-- judgement of justice req seal of justice(dunno what is this for)

DELETE FROM spell_chain WHERE spell_id = 20184;
DELETE FROM spell_chain WHERE spell_id = 31896;

INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (20184,0,20184,1,20164);
INSERT INTO spell_chain (spell_id,prev_spell,first_spell,rank,req_spell) VALUES (31896,20184,20184,2,0);

ALTER TABLE spell_chain DROP COLUMN prev_spell;
