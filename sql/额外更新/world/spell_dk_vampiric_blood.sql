DELETE FROM spell_script_names WHERE scriptname IN ("spell_dk_Vampiric_Blood", "spell_dk_Vampiric_Blood_damages");
INSERT INTO spell_script_names VALUES
(55233, "spell_dk_Vampiric Blood"),
(67120, "spell_dk_T9_Tank_4P_Bonus"),
(123079, "spell_dk_T14_Tank_2P_Bonus"),
(106227, "spell_dk_Last_Defender_of_Azeroth"),
(334547, "spell_dk_Vampiric Aura"),
(317133, "Vampiric Blood_rank2"),
(55233, "spell_dk_Vampiric_Effect"),
/*(-, "spell_dk_Vampiric_Blood_damages");*/

DELETE FROM spell_script_names WHERE scriptname IN ("spell_dk_Vampiric_Blood","Effect_1","Effect_2","Effect_3","Effect_4","Effect_5","flag");
INSERT INTO spell_script_names VALUES
(55233,"spell_dk_Vampiric_Blood",30,0,30,30,0,0,39335),
(67120, "spell_dk_T9_Tank_4P_Bonus"),
(123079, "spell_dk_T14_Tank_2P_Bonus"),
(106227, "spell_dk_Last_Defender_of_Azeroth"),
(334547, "spell_dk_Vampiric Aura"),
(317133, "Vampiric Blood_rank2"),
(55233, "spell_dk_Vampiric_Effect"),
/*(-, "spell_dk_Vampiric_Blood_damages");*/