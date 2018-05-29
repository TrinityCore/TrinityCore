DELETE FROM spell_script_names WHERE scriptname = "spell_mage_ring_of_frost" OR spell_id IN (136511, 82691);
INSERT INTO spell_script_names VALUES
(136511, "spell_mage_ring_of_frost"),
(82691, "spell_mage_ring_of_frost_stun");

UPDATE creature_template SET flags_extra = 128 WHERE entry = 44199;
